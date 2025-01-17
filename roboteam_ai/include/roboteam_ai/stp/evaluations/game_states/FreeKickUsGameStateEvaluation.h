//
// Created by jordi on 28-04-20.
//

#ifndef RTT_FREEKICKUSGAMESTATEEVALUATION_H
#define RTT_FREEKICKUSGAMESTATEEVALUATION_H

#include "stp/evaluations/BaseEvaluation.h"

namespace rtt::ai::stp::evaluation {
/**
 * @brief Class that evaluates the free kick us game state
 */
class FreeKickUsGameStateEvaluation : public BaseEvaluation {
   public:
    /**
     * @brief Calculates the score for the free kick us game state
     * @param world The current world
     * @param field The current field
     * @return The score of the free kick us game state
     */
    [[nodiscard]] uint8_t metricCheck(const world::World* world, const Field* field) const noexcept override;

    /**
     * @brief Retrieves the name of the evaluation
     * @return A string containing the name of the evaluation
     */
    const char* getName() override { return "gs::FreeKickUs"; }
};
}  // namespace rtt::ai::stp::evaluation

#endif  // RTT_FREEKICKUSGAMESTATEEVALUATION_H
