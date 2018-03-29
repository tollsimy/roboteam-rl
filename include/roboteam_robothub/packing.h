#ifndef ROBOTHUB_SRC_PACKING_H_
#define ROBOTHUB_SRC_PACKING_H_

#include <array>
#include <cstdint>
#include <iostream>
#include <string>
#include <boost/optional.hpp>
#include <ros/message_forward.h>

#include "roboteam_msgs/World.h"

namespace roboteam_msgs {

    ROS_DECLARE_MESSAGE(RobotCommand);

}

namespace rtt {

    struct LowLevelRobotCommand{//Description                 Units             Values        Represented values    Bits
        int id;                 //Robot ID                    [0, 15]           -             [0, 15]                  4
        int rho;                //Velocity length             [0, 2047]         0.008m/s      [0, 8.191]              11
        int theta;              //Velocity angle              [-1024, 1023]     0.00307rad    [-pi, pi>               11
        bool driving_reference; //Driving reference           [0, 1]            -             {true, false}            1
        bool use_cam_info;      //Use camera information      [0, 1]            -             {true, false}            1
        int velocity_angular;   //Reference angular velocity  [-512, 511]       0.098rad/s    [-8*2pi, 8*2pi]          9
        bool debug_info;        //Debug information           [0, 1]            -             {true, false}            1
        bool do_kick;           //Kick                        [0, 1]            -             {true, false}            1
        bool do_chip;           //Chip                        [0, 1]            -             {true, false}            1
        bool kick_chip_forced;  //Kick/chip immediately       [0, 1]            -             {true, false}            1
        int kick_chip_power;    //Kick/chip power             [0, 255]          0.39%         [0, 100]%                8
        int velocity_dribbler;  //Reference dribbler speed    [0, 255]          0.39%         [0, 100]%                8
        int geneva_drive_state; //Geneva drive state          [0, 7]            -             [-2, 2]                  3
        int cam_position_x;     //x position robot (camera)   [-4096, 4095]     0.0025m       [-10.24, 10.23]         13
        int cam_position_y;     //y position robot (camera)   [-4096, 4095]     0.0025m       [-10.24, 10.23]         13
        int cam_rotation;       //Orientation (camera)        [-1024, 1023]     0.00307rad    [-pi, pi>               11
    };
    struct OldACK {
        int robotID;
        bool robotACK;
    };

    struct NewACK {
        int robotID;
        bool robotACK;
        bool batteryCritical;
        int ballSensor;

        bool flWheelDir;
        int flWheelSpeed;

        bool frWheelDir;
        int frWheelSpeed;

        bool blWheelDir;
        int blWheelSpeed;

        bool brWheelDir;
        int brWheelSpeed;
    };

    using packed_protocol_message = std::array<uint8_t, 12>;
    using packed_old_ack = std::array<uint8_t, 2>;
    using packed_new_ack = std::array<uint8_t, 8>;

    LowLevelRobotCommand createLowLevelRobotCommand(roboteam_msgs::RobotCommand const &command,
                                                    boost::optional<roboteam_msgs::World> const &worldOpt = boost::none
    );

    boost::optional<packed_protocol_message> createRobotPacket(LowLevelRobotCommand llrc);

    boost::optional<packed_protocol_message> createRobotPacket(roboteam_msgs::RobotCommand const &command,
                                                               boost::optional<roboteam_msgs::World> const &worldOpt = boost::none
    );

    OldACK decodeOldACK(packed_old_ack const &packedAck);

    NewACK decodeNewACK(packed_new_ack const &packedAck);

    std::string byteToBinary(uint8_t const &byte);

    template<unsigned int N>
    std::string byteArrayToString(std::array<uint8_t, N> bytes) {
        std::string result = "";

        for (auto byte : bytes) {
            result += byteToBinary(byte) + "\n";
        }

        return result;
    }

    int const PACKET_MAX_ROBOT_VEL = 8191;
    int const PACKET_MAX_ANG = 511;
    int const PACKET_MAX_W = 2047;
    int const PACKET_MAX_DRIBBLE_VEL = 7;

    int const PACKET_MAX_CAM_ROBOT_VEL = 8191;
    int const PACKET_MAX_CAM_ANG = 511;
    int const PACKET_MAX_CAM_W = 2047;

}

bool operator==(const rtt::LowLevelRobotCommand &lhs, const rtt::LowLevelRobotCommand &rhs);

bool operator!=(const rtt::LowLevelRobotCommand &lhs, const rtt::LowLevelRobotCommand &rhs);

#endif // ROBOTHUB_SRC_PACKING_H_
