//
// Created by kjhertenberg on 14-5-19.
//

#include <gtest/gtest.h>
#include "roboteam_world/kalman/kalmanFilter.h"
#include "roboteam_world/world/filtered_world.h"
#include "roboteam_world/world/world_dummy.h"
#include "roboteam_msgs/DetectionFrame.h"
#include "roboteam_msgs/DetectionBall.h"
#include "roboteam_msgs/DetectionRobot.h"
#include "roboteam_msgs/World.h"
#include "roboteam_msgs/WorldRobot.h"
#include "roboteam_msgs/WorldBall.h"
#include "armadillo"
#include <vector>
namespace rtt {
    using namespace roboteam_msgs;


    void kalman_dummy_frame(float ballx, float bally, float botx, float boty, float botw, DetectionFrame* frame) {
        DetectionRobot bot;
        bot.pos.x = botx;
        bot.pos.y = boty;
        bot.orientation = botw;
        frame->us.push_back(bot);
        DetectionBall ball;
        ball.pos.x = ballx;
        ball.pos.y = bally;
        frame->balls.push_back(ball);
    }

    TEST(KalmanTest, Armadillo){
        //test to see if library is working

        //Initialisation
        arma::mat::fixed<2,2> A = {{1,2},
                                   {3,4}};
        arma::mat::fixed<2,2> B = {{1,2},
                                   {3,4}};

        //dot product multiplication
        arma::mat::fixed<2,2> C = A * B;
        ASSERT_DOUBLE_EQ(C(0, 0), 7);
        ASSERT_DOUBLE_EQ(C(0, 1), 10);
        ASSERT_DOUBLE_EQ(C(1, 0), 15);
        ASSERT_DOUBLE_EQ(C(1, 1), 22);
        //subtraction
        A = C - B;
        ASSERT_DOUBLE_EQ(A(0, 0), 6);
        ASSERT_DOUBLE_EQ(A(0, 1), 8);
        ASSERT_DOUBLE_EQ(A(1, 0), 12);
        ASSERT_DOUBLE_EQ(A(1, 1), 18);
        //addition
        A = A + B;
        ASSERT_DOUBLE_EQ(A(0, 0), C(0,0));
        ASSERT_DOUBLE_EQ(A(0, 1), C(0,1));
        ASSERT_DOUBLE_EQ(A(1, 0), C(1,0));
        ASSERT_DOUBLE_EQ(A(1, 1), C(1,1));
        //transpose
        arma::mat::fixed<2,3> D = {{1,2,3},
                                   {4,5,6}};
        arma::mat::fixed<3,2> E = D.t();
        ASSERT_DOUBLE_EQ(E(0, 0), 1);
        ASSERT_DOUBLE_EQ(E(0, 1), 4);
        ASSERT_DOUBLE_EQ(E(1, 0), 2);
        ASSERT_DOUBLE_EQ(E(1, 1), 5);
        ASSERT_DOUBLE_EQ(E(2, 0), 3);
        ASSERT_DOUBLE_EQ(E(2, 1), 6);
        //inverse
        arma::mat::fixed<2,2> F = C.i();
        ASSERT_DOUBLE_EQ(F(0, 0), 5.5);
        ASSERT_DOUBLE_EQ(F(0, 1), -2.5);
        ASSERT_DOUBLE_EQ(F(1, 0), -3.75);
        ASSERT_DOUBLE_EQ(F(1, 1), 1.75);
        //zero initialisation
        C.zeros();
        ASSERT_DOUBLE_EQ(C(0, 0), 0);
        ASSERT_DOUBLE_EQ(C(0, 1), 0);
        ASSERT_DOUBLE_EQ(C(1, 0), 0);
        ASSERT_DOUBLE_EQ(C(1, 1), 0);
        //identity initialisation
        C.eye();
        ASSERT_DOUBLE_EQ(C(0, 0), 1);
        ASSERT_DOUBLE_EQ(C(0, 1), 0);
        ASSERT_DOUBLE_EQ(C(1, 0), 0);
        ASSERT_DOUBLE_EQ(C(1, 1), 1);
    }


    TEST(KalmanTest, ZXK) {

        kalmanFilter ZXKtest;

        ZXKtest.setZ(1, 1.0, 2.0, 3.0, 1.0);
        for (int j = 0; j < 10000; ++j) {
            ZXKtest.kalmanUpdate();
        }

        float testK1 = ZXKtest.getK(1);

        Position testX = ZXKtest.getPos(1);
        EXPECT_FLOAT_EQ(testX.x, 1);
        EXPECT_FLOAT_EQ(testX.y, 2);
        EXPECT_FLOAT_EQ(testX.rot, 3);

        ZXKtest.setZ(1, 2.0, 4.0, 6.0, 2.0);
        for (int j = 0; j < 10000; ++j) {
            ZXKtest.kalmanUpdate();
        }

        testX = ZXKtest.getPos(1);
        EXPECT_FLOAT_EQ(testX.x, 2);
        EXPECT_FLOAT_EQ(testX.y, 4);
        EXPECT_FLOAT_EQ(testX.rot, 6);

        float testK2 = ZXKtest.getK(1);
        EXPECT_FLOAT_EQ(testK1, testK2);

    }

    TEST(KalmanTest, frame){

        kalmanFilter frametest;

        auto * frame = new DetectionFrame();
        kalman_dummy_frame(1.0, 1.0, 2.0, 2.0, 0.0, frame);

        frametest.newFrame(*frame);

        for (int j = 0; j < 10000; ++j) {
            frametest.kalmanUpdate();
        }

        Position testX = frametest.getPos(0);
        EXPECT_FLOAT_EQ(testX.x, 2);
        EXPECT_FLOAT_EQ(testX.y, 2);
        EXPECT_FLOAT_EQ(testX.rot, 0);
    }

}