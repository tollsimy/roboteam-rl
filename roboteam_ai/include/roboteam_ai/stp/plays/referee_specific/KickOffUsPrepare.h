//
// Created by jordi on 30-04-20.
//

#ifndef RTT_KICKOFFUSPREPARE_H
#define RTT_KICKOFFUSPREPARE_H

#include "stp/Play.hpp"

namespace rtt::ai::stp::play {
/**
 * @brief The kick off us prepare play is executed when the kick off us prepare game state is selected
 */
class KickOffUsPrepare : public Play {
   public:
    /**
     * @brief Constructor that initializes roles with roles that are necessary for this play
     */
    KickOffUsPrepare();

    /**
     * @brief Calculates the score of this play to determine which play is best in this situation
     * @param field The current Field
     * @return The score of this play (0-255)
     */
    uint8_t score(const rtt::Field& field) noexcept override;

    /**
     * @brief Assigns robots to roles of this play
     * @return A map with assigned roles
     */
    Dealer::FlagMap decideRoleFlags() const noexcept override;

    /**
     * @brief Calculates info for the roles
     */
    void calculateInfoForRoles() noexcept override;

    /**
     * @brief Retrieves the name of the play
     * @return The name of the play as a string
     */
    const char* getName() const override;
};
}  // namespace rtt::ai::stp::play

#endif  // RTT_KICKOFFUSPREPARE_H
