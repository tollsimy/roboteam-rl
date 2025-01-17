//
// Created by tijmen on 01-07-22.
//

#ifndef RTT_ORBITKICK_H
#define RTT_ORBITKICK_H

#include "stp/Tactic.h"

namespace rtt::ai::stp::tactic {
/**
 * @brief Class that defines the orbit kick tactic. This tactic is used when the robot should orbit before kicking the ball
 */
class OrbitKick : public Tactic {
   public:
    /**
     * @brief Constructor for the tactic, it constructs the state machine of skills
     */
    OrbitKick();

   private:
    /**
     * @brief Calculate the info for skills from the StpInfo struct parameter
     * @param info info is the StpInfo passed by the role
     * @return std::optional<SkillInfo> based on the StpInfo parameter
     */
    std::optional<StpInfo> calculateInfoForSkill(StpInfo const &info) noexcept override;

    /**
     * @brief Is this tactic failing during execution (go back to the previous tactic)
     * Fails is robot doesn't have the ball or if there is no shootTarget
     * @param info StpInfo can be used to check some data
     * @return true, tactic will fail (go back to prev tactic), false execution will continue as usual
     */
    bool isTacticFailing(const StpInfo &info) noexcept override;

    /**
     * @brief Should this tactic be reset (go back to the first skill of this tactic)
     * Returns true when the robot angle is outside some error margin
     * @param info StpInfo can be used to check some data
     * @return true if tactic  should reset, false if execution should continue
     */
    bool shouldTacticReset(const StpInfo &info) noexcept override;

    /**
     * @brief Checks whether this is a passive tactic (formerly called endTactic)
     * @return This will always return false, since it is NOT an endTactic
     */
    bool isEndTactic() noexcept override;

    /**
     * @brief Gets the tactic name
     * @return The name of this tactic
     */
    const char *getName() override;
};
}  // namespace rtt::ai::stp::tactic

#endif  // RTT_ORBITKICK_H
