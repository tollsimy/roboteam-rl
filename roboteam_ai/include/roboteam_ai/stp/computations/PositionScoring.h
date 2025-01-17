//
// Created by alexander on 02-12-21.
//

#ifndef RTT_POSITIONSCORING_H
#define RTT_POSITIONSCORING_H

#include <roboteam_utils/Field.hpp>

#include "stp/constants/GeneralizationConstants.h"
#include "world/World.hpp"

namespace rtt::ai::stp {

/**
 * @brief Class that manages the scoring for a position
 */
class PositionScoring {
   private:
    /**
     * @brief Determine score for the Open score at given position
     * @param point Position to calculate from
     * @param field The current field
     * @param world The current world
     * @param scores ref to struct linked to that pos
     * @return Open score value
     */
    static double determineOpenScore(Vector2 &point, const rtt::Field &field, const world::World *world, gen::PositionScores &scores);

    /**
     * @brief Determine score for the Line of Sight to the ball at given position
     * @param point Position to calculate from
     * @param world The current world
     * @param scores ref to struct linked to that pos
     * @return Line of Sight score value
     */
    static double determineLineOfSightScore(Vector2 &point, const world::World *world, gen::PositionScores &scores);

    /**
     * @brief Determine score for the Visibility of the goal at given position
     * @param point Position to calculate from
     * @param field The current field
     * @param world The current world
     * @param scores ref to struct linked to that pos
     * @return Goal Shot score value
     */
    static double determineGoalShotScore(Vector2 &point, const Field &field, const world::World *world, gen::PositionScores &scores);

    /**
     * @brief Determine score for blocking potential of a position
     * @param point Position to calculate from
     * @param world The current world
     * @param scores ref to struct linked to that pos
     * @return Blocking score value
     */
    static double determineBlockingScore(Vector2 &point, const world::World *world, gen::PositionScores &scores);

    /**
     * @brief Score a position using the given weights weights for a profile.
     * Will check if the position already has a pre-calculated score (from this tick) then throws the weight over it
     * and sums the scores, resulting in a position scored a particular set of weights.
     * @param profile set of weights of the different factors that determine the score
     * @param position x,y coordinates
     * @param scores reference to scores of said position in map
     * @param field The current field
     * @param world The current world
     * @return score of position including the weights
     */
    static uint8_t getScoreOfPosition(const gen::ScoreProfile &profile, Vector2 position, gen::PositionScores &scores, const Field &field, const world::World *world);

   public:
    /**
     * @brief Get score of a position, used in getPosition
     * @param position Vector2 that needs to be scored
     * @param profile combination of weights for different factors that should be scored
     * @param field The current field
     * @param world The current world
     * @param bias value added to score
     * @return Position with score
     */
    static gen::ScoredPosition scorePosition(const Vector2 &position, const gen::ScoreProfile &profile, const Field &field, const world::World *world, uint8_t bias = 0);
};
}  // namespace rtt::ai::stp
#endif  // RTT_POSITIONSCORING_H
