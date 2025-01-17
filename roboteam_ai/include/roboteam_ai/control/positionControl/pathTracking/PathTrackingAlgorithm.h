//
// Created by ratoone on 09-03-20.
//

#ifndef RTT_PATHTRACKINGALGORITHM_H
#define RTT_PATHTRACKINGALGORITHM_H

#include <roboteam_utils/Position.h>
#include <utilities/StpInfoEnums.h>

#include <vector>

namespace rtt::ai::control {
/**
 * @brief Base class of the path tracking algorithms
 */
class PathTrackingAlgorithm {
   public:
    /**
     * @brief Virtual destructor for the PathTrackingAlgorithm class
     */
    virtual ~PathTrackingAlgorithm() = default;

    /**
     * Purely virtual function that will handle tracking of a path
     * @param currentPosition current position of the robot
     * @param currentVelocity current velocity of the robot
     * @param pathPoints Vector of points the path should follow
     * @param robotId ID of the robot
     * @param angle Angle the robot should be at
     * @param pidType The desired PID type (intercept, regular, keeper etc.)
     * @return a structure containing the tracking velocity and the orientation angle
     */
    virtual Position trackPath(const Vector2 &currentPosition, const Vector2 &currentVelocity, std::vector<Vector2> &pathPoints, int robotId, double angle,
                               stp::PIDType pidType) = 0;

    /**
     * Uses the implementation of trackPath, but replaces the angle with the orientation of the
     * direction of the current position and the next point in the path
     * @param currentPosition current position of the robot
     * @param currentVelocity current velocity of the robot
     * @param pathPoints Vector of points the path should follow
     * @param robotId ID of the robot
     * @param pidType The desired PID type (intercept, regular, keeper etc.)
     * @return a structure containing the tracking velocity and the orientation angle
     */
    Position trackPathDefaultAngle(const Vector2 &currentPosition, const Vector2 &currentVelocity, std::vector<Vector2> &pathPoints, int robotId, stp::PIDType pidType);
};
}  // namespace rtt::ai::control

#endif  // RTT_PATHTRACKINGALGORITHM_H
