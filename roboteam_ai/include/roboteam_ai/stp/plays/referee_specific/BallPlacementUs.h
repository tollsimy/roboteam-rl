#ifndef RTT_BALLPLACEMENTUS_H
#define RTT_BALLPLACEMENTUS_H

#include "stp/Play.hpp"

namespace rtt::ai::stp::play {

/**
 * @brief The ball placement us play is executed when the ball placement us game state is selected
 */
class BallPlacementUs : public Play {
   public:
    /**
     * @brief Constructor that initializes roles with roles that are necessary for this play
     */
    BallPlacementUs();

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

#endif  // RTT_BALLPLACEMENTUS_H