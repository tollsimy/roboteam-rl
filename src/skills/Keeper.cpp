//
// Created by rolf on 10/12/18.
//

#include <boost/optional.hpp>
#include "interface/api/Input.h"
#include "interface/api/Output.h"
#include "skills/Keeper.h"
#include "world/Field.h"
#include "world/Ball.h"
#include "world/Robot.h"
#include "control/ControlUtils.h"

namespace rtt {
namespace ai {

Keeper::Keeper(string name, bt::Blackboard::Ptr blackboard)
        :Skill(std::move(name), std::move(blackboard)) { }

void Keeper::onInitialize() {
    goalPos = world::field->get_field().get(OUR_GOAL_CENTER);
    goalwidth = world::field->get_field().get(GOAL_WIDTH);
    //Create arc for keeper to drive on
    blockCircle = control::ControlUtils::createKeeperArc();

    /// This function is hacky; we need to manually update the PID now everytime.
    posController.setAutoListenToInterface(false);
    posController.updatePid(Constants::standardKeeperPID());
}

Keeper::Status Keeper::onUpdate() {
    Vector2 ballPos = world::world->getBall()->getPos();
    Vector2 blockPoint;

    goalPos = world::field->get_field().get(OUR_GOAL_CENTER);

    if (ball->getPos().x < 0) {
        auto attacker = world::world->getRobotClosestToPoint(ball->getPos(), THEIR_ROBOTS);
        if (attacker && (ball->getPos() - attacker->pos).length() < MIN_ATTACKER_DIST) {
            setGoalPosWithAttacker(attacker);
        }
    }

    blockPoint = computeBlockPoint(ballPos);

    if (! world::field->pointIsInField(blockPoint, static_cast<float>(-Constants::OUT_OF_FIELD_MARGIN()))) {
        blockPoint = goalPos;
        blockPoint.x += Constants::KEEPER_CENTREGOAL_MARGIN();
        command.set_w(0);
    }
    else {
        command.set_w(Angle((ballPos - blockPoint).angle() + M_PI_2).getAngle());
    }
    interface::Input::drawData(interface::Visual::KEEPER, {blockPoint}, Qt::darkYellow, robot->id,
            interface::Drawing::DOTS, 5, 5);
    /// Manual PID value update. Ugly and should be refactored in the future.
    posController.updatePid(interface::Output::getKeeperPid());
    Vector2 velocities = posController.getRobotCommand(robot, blockPoint).vel;
    command.mutable_vel()->set_x(velocities.x);
    command.mutable_vel()->set_y(velocities.y);
    publishRobotCommand();
    return Status::Running;
}

void Keeper::onTerminate(Status s) {
}

Vector2 Keeper::computeBlockPoint(const Vector2 &defendPos) {
    Vector2 blockPos, posA, posB;
    if (defendPos.x < world::field->get_field().get(OUR_GOAL_CENTER).x) {
        if (abs(defendPos.y) >= goalwidth) {
            blockPos = Vector2(goalPos.x + Constants::KEEPER_POST_MARGIN(), goalwidth/2
                    *signum(defendPos.y));
        }
        else {
            blockPos = goalPos;
            blockPos.x += Constants::KEEPER_CENTREGOAL_MARGIN();
        }
    }
    else {
        Vector2 u1 = (goalPos + Vector2(0.0, goalwidth*0.5) - defendPos).normalize();
        Vector2 u2 = (goalPos + Vector2(0.0, - goalwidth*0.5) - defendPos).normalize();
        double dist = (defendPos - goalPos).length();
        Vector2 blockLineStart = defendPos + (u1 + u2).stretchToLength(dist);
        std::pair<boost::optional<Vector2>, boost::optional<Vector2>> intersections = blockCircle.intersectionWithLine(
                blockLineStart, defendPos);

        // go stand on the intersection of the lines. Pick the one that is closest to (0,0) if there are multiple
        if (intersections.first && intersections.second) {
            posA = *intersections.first;
            posB = *intersections.second;

            if (! world::field->pointIsInDefenceArea(posA, true)) {
                blockPos = posB;
            }

            if (posA.length() < posB.length()) {
                blockPos = posA;
            }
            else blockPos = posB;
        }
        else if (intersections.first) {
            blockPos = *intersections.first;
        }
        else if (intersections.second) {
            blockPos = *intersections.second;
        }
        else {
            blockPos = Vector2(goalPos.x + Constants::KEEPER_POST_MARGIN(), goalwidth/2
                    *signum(defendPos.y)); // Go stand at one of the poles depending on the side the defendPos is on.
        }
    }

    interface::Input::drawData(interface::Visual::KEEPER, {defendPos, blockPos}, Qt::red, robot->id,
            interface::Drawing::DrawingMethod::DOTS, 5, 5);
    return blockPos;
}

void Keeper::setGoalPosWithAttacker(RobotPtr attacker) {
    Vector2 start;
    Vector2 end;
    double distanceToGoal = ((Vector2) attacker->pos - world::field->get_field().get(OUR_GOAL_CENTER)).length();

    start = attacker->pos;

    auto goal = world::field->getGoalSides(true);
    Vector2 attackerToBallV2 = ball->getPos() - attacker->pos;
    Vector2 attackerAngleV2 = attacker->angle.toVector2();
    Vector2 i1 = control::ControlUtils::twoLineIntersection(attackerToBallV2 + attacker->pos, attacker->pos, goal.first,
            goal.second);
    Vector2 i2 = control::ControlUtils::twoLineIntersection(attackerAngleV2 + attacker->pos, attacker->pos, goal.first,
            goal.second);
    Angle targetAngle = Vector2((i1 + i2)*0.5 - attacker->pos).toAngle();
    end = start + (Vector2) {distanceToGoal*1.2, 0}.rotate(targetAngle);

    auto field = world::field->get_field();
    Vector2 startGoal = {- field.get(FIELD_LENGTH) / 2, - field.get(GOAL_WIDTH) / 2};
    Vector2 endGoal = {- field.get(FIELD_LENGTH) / 2, field.get(GOAL_WIDTH) / 2};
    if (control::ControlUtils::lineSegmentsIntersect(start, end, startGoal, endGoal)) {
        goalPos = control::ControlUtils::twoLineIntersection(start, end, startGoal, endGoal);
    }
}

}
}