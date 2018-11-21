//
// Created by baris on 16/11/18.
//

#ifndef ROBOTEAM_AI_ROBOTDEALER_H
#define ROBOTEAM_AI_ROBOTDEALER_H

#include <map>
#include <set>
#include <mutex>
#include <vector>
#include "World.h"
#include "Field.h"

namespace robotDealer {
class RobotDealer {

    private:

        static std::map<std::string, std::set<std::pair<int, std::string>>> robotOwners;

        static std::mutex robotOwnersLock;

        static void removeRobotFromOwnerList(int ID);

        static void addRobotToOwnerList(int ID, std::string tacticName, std::string roleName);

        static void updateFromWorld();

        static std::set<int> getRobots();

        static int getRobotClosestToPoint(std::set<int> &ids, rtt::Vector2 &position);

        static int getRobotClosestToLine(std::set<int> &ids, rtt::Vector2 &point1, rtt::Vector2 &point2, bool inBetweenPoints);

    public:

       enum RobotType {
         closeToBall,
         farFromBall,
         readyToDefend,
         betweenBallAndOurGoal,
         random

       };

       static int claimRobotForTactic(RobotType feature, std::string roleName, std::string tacticName);

       static std::set<int> getAvailableRobots();

       static std::map<std::string, std::set<std::pair<int, std::string>>> getClaimedRobots();

       static void releaseRobotForRole(std::string roleName);

       static void removeTactic(std::string tacticName);

       static std::set<int> findRobotsForTactic(std::string tacticName);

       static int findRobotForRole(std::string roleName);



};
}
#endif //ROBOTEAM_AI_ROBOTDEALER_H
