//
// Created by robzelluf on 3/8/19.
//

#include <roboteam_ai/src/interface/widget.h>
#include <roboteam_ai/src/interface/drawer.h>
#include "OffensiveCoach.h"

namespace rtt {
namespace ai {
namespace coach {

int OffensiveCoach::maxPositions = 4;
double OffensiveCoach::newRobotPositionMargin = 0.05;
double OffensiveCoach::marginFromLines = 0.2;
std::vector<OffensiveCoach::OffensivePosition> OffensiveCoach::offensivePositions;
std::map<int, OffensiveCoach::OffensivePosition> OffensiveCoach::robotPositions;

double OffensiveCoach::calculateCloseToGoalScore(Vector2 position) {
    double distanceFromGoal = (Field::get_their_goal_center() - position).length();

    double score = exp(-0.1 * distanceFromGoal);
    return score;
}

double OffensiveCoach::calculateShotAtGoalScore(Vector2 position, roboteam_msgs::World world) {
    double safelyness = 3;
    while (safelyness > 0) {
            if (control::ControlUtils::clearLine(position, Field::get_their_goal_center(), world, safelyness)) {
                break;
            }
            safelyness -= 0.5;
        }

    return 1 - exp(-0.1 * safelyness);
}


double OffensiveCoach::calculatePassLineScore(Vector2 position, roboteam_msgs::World world) {
    double safelyness = 3;
    while (safelyness > 0) {
        if (control::ControlUtils::clearLine(world.ball.pos, position, world, safelyness)) {
            break;
        }
        safelyness -= 0.5;
    }

    return 1 - exp(-0.1 * safelyness);
}

double OffensiveCoach::calculateDistanceToOpponentsScore(Vector2 position, roboteam_msgs::World world) {
    shared_ptr<roboteam_msgs::WorldRobot> closestRobot = World::getRobotClosestToPoint(world.them, position);
    if (closestRobot) {
        double distance = (position - closestRobot->pos).length();
        return 1 - exp(-1 * distance);
    } else {
        return 1;
    }
}

double OffensiveCoach::calculatePositionScore(Vector2 position) {
    roboteam_msgs::World world = World::get_world();
    roboteam_msgs::GeometryFieldSize field = Field::get_field();
    double closeToGoalScore = calculateCloseToGoalScore(position);
    double shotAtGoalScore = calculateShotAtGoalScore(position, world);
    double passLineScore = calculatePassLineScore(position, world);
    double closestOpponentScore = calculateDistanceToOpponentsScore(position, world);
    double tooCloseToBallScore = 1 - exp(-2 * (position - world.ball.pos).length());
    double behindBallScore = position.x < world.ball.pos.x ? 0.7 : 1.0;
    double distanceFromCornerScore = calculateDistanceFromCorner(position, field);

    double score = closeToGoalScore + shotAtGoalScore + passLineScore + closestOpponentScore
            + tooCloseToBallScore + behindBallScore + distanceFromCornerScore;

    return score;
}

void OffensiveCoach::calculateNewPositions() {
    auto it = offensivePositions.begin();
    while (it < offensivePositions.end()) {
        it->score = calculatePositionScore(it->position);
        for (auto& robotPosition : robotPositions) {
            if ((it->position - robotPosition.second.position).length() < Constants::ATTACKER_DISTANCE()) {
                offensivePositions.erase(it);
                break;
            }
        }
        it++;
    }

    roboteam_msgs::GeometryFieldSize field = Field::get_field();
    double xStart = 0 + marginFromLines;
    double xEnd = field.right_penalty_line.begin.x - marginFromLines;
    double yStart = -field.field_width + marginFromLines;
    double yEnd = field.field_width - marginFromLines;

    int attempts = 30;

    for (int attempt = 0; attempt < attempts; attempt++) {
        OffensivePosition position;

        double x = (xEnd - xStart) * ( (double)rand() / (double)RAND_MAX) + xStart;
        double y = (yEnd - yStart) * ( (double)rand() / (double)RAND_MAX) + yStart;

        position.position = {x, y};

        if (!Field::pointIsInField(position.position) || Field::pointIsInDefenceArea(position.position, false)) {
            attempt--;
            continue;
        }

        bool tooClose = false;
        for (auto &robotPosition : robotPositions) {
            if ((position.position - robotPosition.second.position).length() < Constants::ATTACKER_DISTANCE()) {
                tooClose = true;
                continue;
            }
        }

        if (tooClose) {
            attempt--;
            continue;
        }

        position.score =  calculatePositionScore({x, y});

        if (offensivePositions.empty()) {
            offensivePositions.push_back(position);
            continue;
        }

        OffensivePosition bestPos = position;
        auto it = offensivePositions.begin();
        while (it < offensivePositions.end()) {
            if ((position.position - it->position).length() < Constants::OFFENSIVE_POSITION_DISTANCE()) {//Constants::ATTACKER_DISTANCE()) {
                if (it->score >= bestPos.score) {
                    bestPos.position = it->position;
                    bestPos.score = it->score;
                }
                offensivePositions.erase(it);
            }
            it++;
        }
        offensivePositions.push_back(bestPos);
    }

    std::sort(offensivePositions.begin(), offensivePositions.end(), compareByScore);
    offensivePositions.erase(offensivePositions.begin() + maxPositions, offensivePositions.end());
    drawOffensivePoints();
}

bool OffensiveCoach::compareByScore(OffensivePosition position1, OffensivePosition position2) {
    return position1.score > position2.score;
}

Vector2 OffensiveCoach::calculatePositionForRobot(std::shared_ptr<roboteam_msgs::WorldRobot> robot) {
    if ((robotPositions.find(robot->id) == robotPositions.end())) { // not there yet
        std::cout << "Calculating new position for robot " << robot->id << std::endl;
        double distance = 999;
        double currentDistance;
        OffensiveCoach::OffensivePosition newRobotPosition;
        for (auto &position : offensivePositions) {
            currentDistance = (position.position - robot->pos).length();
            if (currentDistance < distance) {
                distance = currentDistance;
                newRobotPosition = position;
            }
        }
        if (distance == 999) {
            newRobotPosition.position = robot->pos;
            newRobotPosition.score = calculatePositionScore(robot->pos);
        }


        if ((newRobotPosition.position - robot->pos).length() < 0.8) {
            robotPositions[robot->id] = newRobotPosition;
        }
        return newRobotPosition.position;

    } else {
        std::cout << "Calculating better position for robot " << robot->id << std::endl;
        calculateNewRobotPositions(robot);
        if ((robotPositions.find(robot->id) == robotPositions.end())) { //not in there
            return calculatePositionForRobot(robot);
        } else {

            return robotPositions[robot->id].position;
        }
    }
}

void OffensiveCoach::releaseRobot(int robotID) {
    robotPositions.erase(robotID);
}

Vector2 OffensiveCoach::getPositionForRobotID(int robotID) {
    Vector2 position = robotPositions[robotID].position;
    return position;
}

vector<OffensiveCoach::OffensivePosition> &OffensiveCoach::getOffensivePositions() {
    return offensivePositions;
}

double OffensiveCoach::calculateDistanceFromCorner(Vector2 position, roboteam_msgs::GeometryFieldSize field) {
    Vector2 corner;
    corner.x = field.field_length / 2;
    if (position.y > 0) {
        corner.y = field.field_width / 2;
    } else {
        corner.y = -field.field_width / 2;
    }
    double distanceFromCorner = (position - corner).length();
    return 1 - exp(-0.05 * distanceFromCorner);
}

void OffensiveCoach::calculateNewRobotPositions(std::shared_ptr<roboteam_msgs::WorldRobot> robot) {
    OffensiveCoach::OffensivePosition currentRobotPosition = robotPositions[robot->id];

    Vector2 currentPosition = currentRobotPosition.position;
    double currentScore = calculatePositionScore(currentPosition);

    Vector2 newPosition;
    double newScore;
    bool foundNewPosition = false;

    for (int xDiff : {-2, -1, 0, 1, 2}) {
        for (int yDiff : {-2, -1, 0, 1, 2}) {
            if (!Field::pointIsInField(newPosition) || Field::pointIsInDefenceArea(newPosition, false)) continue;
            newPosition.x = currentPosition.x + 0.01 * xDiff;
            newPosition.y = currentPosition.y + 0.01 * yDiff;

            bool tooClose = false;
            for (auto &robotPosition : robotPositions) {
                if (robotPosition.first != robot->id) {
                    if ((newPosition - robotPosition.second.position).length() < Constants::ATTACKER_DISTANCE()) {
                        tooClose = true;
                        break;
                    }
                }
            }

            if (tooClose) continue;
            newScore = calculatePositionScore(newPosition);
            if (newScore > currentScore && newScore > 0.6 * offensivePositions[maxPositions - 1].score) {
                currentPosition = newPosition;
                currentScore = newScore;
                foundNewPosition = true;
            }

        }
    }
    if (foundNewPosition) {
        robotPositions[robot->id].position = currentPosition;
        robotPositions[robot->id].score = currentScore;
    } else {
        robotPositions.erase(robot->id);

    }
}

vector<OffensiveCoach::OffensivePosition>
OffensiveCoach::getAreaPositions(double xStart, double xEnd, double yStart, double yEnd, double numberOfPositions) {
    return vector<OffensiveCoach::OffensivePosition>();
}

vector<OffensiveCoach::OffensivePosition> OffensiveCoach::getRobotPositions() {
    std::vector<OffensivePosition> positions;
    for (auto &position : robotPositions) {
        positions.emplace_back(position.second);
    }

    return positions;
}

void OffensiveCoach::drawOffensivePoints() {
    /// Draw general offensive points
    std::vector<std::pair<rtt::Vector2, QColor>> displayColorData;
    for (auto offensivePosition : offensivePositions) {
        displayColorData.emplace_back(std::make_pair(offensivePosition.position, Qt::green));
    }
    interface::Drawer::setOffensivePoints(displayColorData);

    /// Draw attacker points specific to robot
    displayColorData = {};
    for (auto robotPosition : robotPositions) {
        displayColorData.emplace_back(std::make_pair(robotPosition.second.position, Qt::darkYellow));
        interface::Drawer::setAttackerPoints(robotPosition.first, displayColorData);
    }

}

}
}
}