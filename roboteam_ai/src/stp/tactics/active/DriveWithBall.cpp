//
// Created by timovdk on 3/16/20.
/// Rotates the target position and drives towards it

/// ACTIVE
//

#include "stp/tactics/active/DriveWithBall.h"

#include "stp/skills/GoToPos.h"
#include "stp/skills/Rotate.h"

namespace rtt::ai::stp::tactic {

DriveWithBall::DriveWithBall() {
    // Create state machine of skills and initialize first skill
    // TODO: The rotate skill might be unnecessary in this tactic if our dribbler works well whilst driving backwards
    skills = rtt::collections::state_machine<Skill, Status, StpInfo>{skill::Rotate(), skill::GoToPos()};
}

std::optional<StpInfo> DriveWithBall::calculateInfoForSkill(StpInfo const& info) noexcept {
    StpInfo skillStpInfo = info;

    if (!skillStpInfo.getPositionToMoveTo() || !skillStpInfo.getBall()) return std::nullopt;

    if (skills.current_num() == 0) {
        skillStpInfo.setAngle((info.getPositionToMoveTo().value() - info.getRobot()->get()->getPos()).angle());
    } else {
        double angleToBall = (info.getPositionToMoveTo().value() - info.getBall()->get()->position).angle();
        skillStpInfo.setAngle(angleToBall);
    }

    skillStpInfo.setDribblerSpeed(100);

    return skillStpInfo;
}

bool DriveWithBall::isTacticFailing(const StpInfo& info) noexcept {
    // Fail if we don't have the ball or there is no movement position
    return !info.getRobot().value()->hasBall() || !info.getPositionToMoveTo();
}

bool DriveWithBall::shouldTacticReset(const StpInfo& info) noexcept {
    // Should reset if the angle the robot is at is no longer correct after doing rotate
    return skills.current_num() == 1 && info.getRobot()->get()->getAngle().shortestAngleDiff(info.getAngle()) > Constants::HAS_BALL_ANGLE();
}

bool DriveWithBall::isEndTactic() noexcept {
    // This is not an end tactic
    return false;
}

const char* DriveWithBall::getName() { return "Drive With Ball"; }

}  // namespace rtt::ai::stp::tactic
