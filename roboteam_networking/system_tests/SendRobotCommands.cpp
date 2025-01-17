#include <RobotCommandsNetworker.hpp>
#include <RobotFeedbackNetworker.hpp>
#include <SettingsNetworker.hpp>
#include <WorldNetworker.hpp>
#include <chrono>
#include <iostream>
#include <memory>

using namespace rtt::net;

constexpr int ID = 0;
constexpr int MAX_AMOUNT_OF_ROBOTS = 16;

rtt::RobotCommands getEmptyRobotCommandToAllRobots() {
    rtt::RobotCommands commands;
    for (int i = 0; i < 16; ++i) {
        commands.push_back({.id = i});
    }
    return commands;
}

proto::GameSettings getRobotHubBasestationModePacket() {
    proto::GameSettings settings;
    settings.set_robot_hub_mode(proto::GameSettings::BASESTATION);
    return settings;
}

void onFeedback(const rtt::RobotsFeedback& robotsFeedback) {
    int amountOfFeedback = robotsFeedback.feedback.size();
    bool isYellow = robotsFeedback.team == rtt::Team::YELLOW;

    std::cout << "Received " << amountOfFeedback << " feedbacks of team " << (isYellow ? "yellow" : "blue") << std::endl;

    for (const auto& feedback : robotsFeedback.feedback) {
        int id = feedback.id;
        bool xSensCalibrated = feedback.xSensIsCalibrated;
        bool ballsensorworking = feedback.ballSensorIsWorking;
        bool hasBall = feedback.dribblerSeesBall;

        std::cout << " - Robot " << id << " has " << (hasBall ? "" : "not ") << "the ball" << std::endl;
    }
}

void onWorld(const proto::State& world) {
    for (const auto& robot : world.last_seen_world().yellow()) {
        std::cout << "Robot " << robot.id() << " of team yellow has " << (robot.feedbackinfo().dribbler_sees_ball() ? "" : "not ") << "the ball" << std::endl;
    }

    for (const auto& robot : world.last_seen_world().blue()) {
        std::cout << "Robot " << robot.id() << " of team blue has " << (robot.feedbackinfo().dribbler_sees_ball() ? "" : "not ") << "the ball" << std::endl;
    }
}

int main() {
    auto settingsPub = std::make_unique<SettingsPublisher>();
    auto commandsBluePub = std::make_unique<RobotCommandsBluePublisher>();
    auto commandsYellowPub = std::make_unique<RobotCommandsYellowPublisher>();

    auto feedbackSub = std::make_unique<RobotFeedbackSubscriber>(onFeedback);
    auto worldSub = std::make_unique<WorldSubscriber>(onWorld);

    auto teamCommand = getEmptyRobotCommandToAllRobots();

    // First, send settings message to robothub that it needs to forward messages to the basestation
    std::cout << "Started test..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Sending robothub mode settings message" << std::endl;
    settingsPub->publish(getRobotHubBasestationModePacket());
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "Starting to send commands: " << std::endl << std::endl;
    auto command = getEmptyRobotCommandToAllRobots();
    while (true) {
        commandsYellowPub->publish(command);
        commandsBluePub->publish(command);
        std::cout << "Sent robot command..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}