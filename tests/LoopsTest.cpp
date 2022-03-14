#include <RobotCommandsNetworker.hpp>
#include <RobotFeedbackNetworker.hpp>
#include <SettingsNetworker.hpp>
#include <WorldNetworker.hpp>
#include <chrono>
#include <memory>
#include <gtest/gtest.h>

/* These tests will check if you send something with a publisher of type X,
 * you will receive the same data with the subscriber of X.
 * This ensures that all publishers and subscribers:
 * - Are on the correct channel
 * - Are able to send the correct data
 * */

using namespace rtt::net;

constexpr int TEST_VALUE = 69;
constexpr int PAUSE_MS = 50;

// Robot commands loop test
bool robotCommandsBlueLoopTestPassed = false;
bool robotCommandsYellowLoopTestPassed = false;
void onRobotCommandsBlue(const rtt::RobotCommands& commands) { robotCommandsBlueLoopTestPassed = commands[0].id == TEST_VALUE; }
void onRobotCommandsYellow(const rtt::RobotCommands& commands) { robotCommandsYellowLoopTestPassed = commands[0].id == TEST_VALUE; }

TEST(RTTChannels, testRobotCommandsLoop) {
    RobotCommandsBluePublisher pubBlue;
    RobotCommandsYellowPublisher pubYellow;

    RobotCommandsBlueSubscriber subBlue(onRobotCommandsBlue);
    RobotCommandsYellowSubscriber subYellow(onRobotCommandsYellow);

    std::this_thread::sleep_for(std::chrono::milliseconds(PAUSE_MS));

    rtt::RobotCommands commands;

    commands.push_back({.id = TEST_VALUE});

    pubBlue.publish(commands);
    pubYellow.publish(commands);

    std::this_thread::sleep_for(std::chrono::milliseconds(PAUSE_MS));


    EXPECT_TRUE(robotCommandsBlueLoopTestPassed);
    EXPECT_TRUE(robotCommandsYellowLoopTestPassed);
}

// Robot feedback loop test
bool robotFeedbackLoopTestPassed = false;
void onRobotFeedback(const proto::RobotData& feedback) { robotFeedbackLoopTestPassed = feedback.receivedfeedback().Get(0).id() == TEST_VALUE; }
TEST(RTTChannels, testRobotFeedbackLoop) {
    RobotFeedbackPublisher pub;
    RobotFeedbackSubscriber sub(onRobotFeedback);
    std::this_thread::sleep_for(std::chrono::milliseconds(PAUSE_MS));

    proto::RobotData feedback;
    feedback.add_receivedfeedback()->set_id(TEST_VALUE);

    pub.publish(feedback);
    std::this_thread::sleep_for(std::chrono::milliseconds(PAUSE_MS));

    EXPECT_TRUE(robotFeedbackLoopTestPassed);
}

// Settings loop test
bool settingsLoopTestPassed = false;
void onSettings(const proto::Setting& settings) { settingsLoopTestPassed = settings.visionport() == TEST_VALUE; }
TEST(RTTChannels, testSettingsLoop) {
    SettingsPublisher pub;
    SettingsSubscriber sub(onSettings);
    std::this_thread::sleep_for(std::chrono::milliseconds(PAUSE_MS));

    proto::Setting settings;
    settings.set_visionport(TEST_VALUE);

    pub.publish(settings);
    std::this_thread::sleep_for(std::chrono::milliseconds(PAUSE_MS));

    EXPECT_TRUE(settingsLoopTestPassed);
}

// World loop test
bool worldLoopTestPassed = false;
void onWorld(const proto::State& world) { worldLoopTestPassed = world.ball_camera_world().ball().pos().x() == TEST_VALUE; }
TEST(RTTChannels, testWorldLoop) {
    WorldPublisher pub;
    WorldSubscriber sub(onWorld);
    std::this_thread::sleep_for(std::chrono::milliseconds(PAUSE_MS));

    proto::State world;
    world.mutable_ball_camera_world()->mutable_ball()->mutable_pos()->set_x(TEST_VALUE);

    pub.publish(world);
    std::this_thread::sleep_for(std::chrono::milliseconds(PAUSE_MS));

    EXPECT_TRUE(worldLoopTestPassed);
}