//
// Created by maxl on 18-02-21.
//

#ifndef RTT_PLAYEVALUATOR_H
#define RTT_PLAYEVALUATOR_H

#include <roboteam_utils/Field.hpp>

#include "world/World.hpp"

namespace rtt::ai::stp {
/**
 * @brief Enumerator for global evaluations
 */
enum class GlobalEvaluation {
    /// Game States
    BallPlacementThemGameState = 0,
    BallPlacementUsGameState,
    FreeKickThemGameState,
    FreeKickUsGameState,
    HaltGameState,
    TimeOutGameState,
    KickOffThemGameState,
    KickOffThemPrepareGameState,
    KickOffUsGameState,
    KickOffUsOrNormalGameState,
    KickOffUsPrepareGameState,
    NormalOrFreeKickUsGameState,
    NormalPlayGameState,
    PenaltyThemGameState,
    PenaltyThemPrepareGameState,
    PenaltyUsGameState,
    PenaltyUsPrepareGameState,
    StopGameState,
    PreHalfGameState,
    /// Global Evaluations
    BallCloseToThem,
    BallCloseToUs,
    BallClosestToUs,
    BallGotShot,
    BallIsFree,
    BallMovesSlow,
    BallOnOurSide,
    BallOnTheirSide,
    BallInOurDefenseAreaAndStill,
    BallNotInOurDefenseAreaAndStill,
    DistanceFromBall,
    FreedomOfRobots,
    GoalVisionFromBall,
    GoalVision,
    NoGoalVisionFromBall,
    WeHaveBall,
    TheyHaveBall,
    TheyDoNotHaveBall,
    WeHaveMajority
};

/**
 * @brief Class that defines the play evaluator. It evaluates each play possible and gives it a score
 */
class PlayEvaluator {
   public:
    /**
     * @brief Structure for storing the scores for the plays
     */
    struct PlayScoring {
        uint8_t evaluationScore;
        double weight;
    };

    /**
     * @brief Gets the score of a Global Evaluation, if it was not updated yet, update it before.
     * @param evaluation that needs to be evaluated
     * @param world pointer to world
     * @return evaluated score for the evaluation, between 0 and 255
     */
    static uint8_t getGlobalEvaluation(GlobalEvaluation evaluation, const world::World* world);

    /**
     * @brief Clears the map of stored scores, to make sure new scores are calculated next tick
     */
    static void clearGlobalScores();

    /**
     * @brief Checks if FUZZY-TRUE score in uint8-t of global evaluation is above the TRUE threshold
     * @param globalEvaluation Invariant to be checked
     * @param world the pointer to world
     * @param cutOff Bottom bound value of true
     * @return boolean if FUZZY-TRUE is high enough
     */
    static bool checkEvaluation(GlobalEvaluation globalEvaluation, const rtt::world::World* world, uint8_t cutOff = control_constants::FUZZY_DEFAULT_CUTOFF) noexcept;

    /**
     * @brief Calculate a final weighted score given a vector of scores with their weights
     * @param scoring vector withto be considered Evaluations
     * @return final score (0-255)
     */
    static uint8_t calculateScore(std::vector<PlayScoring>& scoring);

   private:
    static inline std::unordered_map<GlobalEvaluation, uint8_t> scoresGlobal{}; /**< Map of all loaded Global Evaluations scores */

    /**
     * @brief Updates a given Global Evaluation, should only happen if this was not done in this tick yet.
     * @param index of evaluation that needs to be updated
     * @return the score of the updated evaluation
     */
    static uint8_t updateGlobalEvaluation(GlobalEvaluation& evaluation, const rtt::world::World* world);
};

}  // namespace rtt::ai::stp

#endif  // RTT_PLAYEVALUATOR_H
