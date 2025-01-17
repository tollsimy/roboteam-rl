//
// Created by jordi on 08-04-20.
// Modified by timovdk on 4/29/20.
//

#ifndef RTT_PENALTYKEEPER_H
#define RTT_PENALTYKEEPER_H

#include <roboteam_utils/Field.hpp>

#include "Keeper.h"
#include "stp/Role.hpp"

namespace rtt::ai::stp::role {

//
// Role inherited from the Keeper
//

class PenaltyKeeper : public Keeper {
    /**
     * @brief Class that defines the penalty keeper. The penalty keeper will keep the ball out of the goal during a penalty
     */
   public:
    /**
     * @brief Constructor that sets the name of the role and creates a state machine of tactics
     * @param name name of the role
     */
    explicit PenaltyKeeper(std::string name);

    /**
     * @brief Besides the default update from base class Role, it also switches between tactics depending on the ball position and velocity
     * @param info TacticInfo to be passed to update()
     * @return The status that the current tactic returns
     */
    [[nodiscard]] Status update(StpInfo const& info) noexcept override;
};
}  // namespace rtt::ai::stp::role

#endif  // RTT_PENALTYKEEPER_H
