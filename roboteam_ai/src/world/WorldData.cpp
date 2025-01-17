//
// Created by john on 12/16/19.
//

#include "world/WorldData.hpp"

#include "roboteam_utils/Print.h"
#include "utilities/GameSettings.h"

namespace rtt::world {
WorldData::WorldData(const World *data, proto::World &protoMsg) noexcept : time{protoMsg.time()} {
    auto &ours = GameSettings::isYellow() ? protoMsg.yellow() : protoMsg.blue();
    auto &others = GameSettings::isYellow() ? protoMsg.blue() : protoMsg.yellow();

    // If there is a ball in the protobuf message, add it to the world
    ball = ball::Ball{protoMsg.ball(), data};

    auto amountUs = ours.size();
    auto amountThem = others.size();
    us.reserve(amountUs);
    them.reserve(amountThem);
    robots.reserve(amountUs + amountThem);

    // NOTE: This is a (hopefully) temporary fix for issue #57 (https://github.com/RoboTeamTwente/roboteam/issues/57)
    // for (auto &each : ours) {
    //     robots.emplace_back( each, Team::us, getBall());
    // }
    // for (auto &each : others) {
    //     robots.emplace_back( each, Team::them, getBall());
    // }

    for (auto &each : ours) {
        if (isnan(each.pos().x())) {
            RTT_ERROR("WATCH OUT! ROBOT WITH NAN VALUES RECEIVED FROM OBSERVER! Omitting robot for now..")
        } else {
            robots.emplace_back(each, Team::us, getBall());
        }
    }
    for (auto &each : others) {
        if (isnan(each.pos().x())) {
            RTT_ERROR("WATCH OUT! ROBOT WITH NAN VALUES RECEIVED FROM OBSERVER! Omitting robot for now..")
        } else {
            robots.emplace_back(each, Team::them, getBall());
        }
    }
    // End of temporary fix

    us.reserve(amountUs);
    them.reserve(amountThem);
    setViewVectors();

    // TODO: add information from robots which were only seen on feedback but not on vision
    if (GameSettings::isYellow() && protoMsg.yellow_unseen_robots_size() > 0) {
        RTT_WARNING("Received feedback from unseen robots!")
    } else if (!GameSettings::isYellow() && protoMsg.blue_unseen_robots_size() > 0) {
        RTT_WARNING("Received feedback from unseen robots!")
    }
}

std::vector<view::RobotView> const &WorldData::getUs() const noexcept { return us; }

std::vector<view::RobotView> const &WorldData::getThem() const noexcept { return them; }

std::optional<view::BallView> WorldData::getBall() const noexcept {
    if (ball.has_value()) {
        return std::optional<view::BallView>(&ball.value());
    } else {
        return std::nullopt;
    }
}

uint64_t WorldData::getTime() const noexcept { return time; }

std::vector<view::RobotView> const &WorldData::getRobotsNonOwning() const noexcept { return robotsNonOwning; }

WorldData &WorldData::operator=(WorldData const &other) noexcept {
    if (this == &other) {
        return *this;
    }

    this->robots = other.robots;
    this->ball = other.ball;

    this->us.reserve(other.getUs().size());
    this->them.reserve(other.getThem().size());
    robotsNonOwning.reserve(getUs().size() + getThem().size());

    setViewVectors();
    return *this;
}

WorldData::WorldData(WorldData const &other) noexcept : robots{other.robots}, ball{other.ball} {
    us.reserve(other.getUs().size());
    them.reserve(other.getThem().size());
    robotsNonOwning.reserve(getUs().size() + getThem().size());
    setViewVectors();
}

void WorldData::setViewVectors() noexcept {
    /*
     * Reserve the us and them vectors, making sure they are not being resized (which will invalidate the references)
     */
    for (auto const &each : robots) {
        robotsNonOwning.emplace_back(&each);
        auto &matchingVector = each.getTeam() == Team::us ? us : them;
        matchingVector.emplace_back(&each);
    }
}
}  // namespace rtt::world
