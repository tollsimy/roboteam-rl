// AUTOGENERATED. Run generator/main.py to regenerate
/*
[  0   ] [  1   ] [  2   ] [  3   ] [  4   ] [  5   ] [  6   ] [  7   ] [  8   ] [  9   ] [  10  ] [  11  ] [  12  ] [  13  ] [  14  ] [  15  ] [  16  ] [  17  ]
11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- header
-------- 1111---- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- toRobotId
-------- ----1--- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- toColor
-------- -----1-- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- toBC
-------- ------1- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- toBS
-------- -------1 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- toPC
-------- -------- 1111---- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- fromRobotId
-------- -------- ----1--- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- fromColor
-------- -------- -----1-- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- reserved
-------- -------- ------1- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- fromBS
-------- -------- -------1 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- fromPC
-------- -------- -------- 1111---- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- remVersion
-------- -------- -------- ----1111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- messageId
-------- -------- -------- -------- 11111111 11111111 11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- timestamp
-------- -------- -------- -------- -------- -------- -------- 11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- payloadSize
-------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- -------- -------- -------- -------- rho
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- -------- -------- theta
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- angle
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 1111---- -------- -------- -------- batteryLevel
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- ----1--- -------- -------- -------- XsensCalibrated
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -----1-- -------- -------- -------- capacitorCharged
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- ------1- -------- -------- -------- ballSensorWorking
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------1 -------- -------- -------- ballSensorSeesBall
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 1111---- -------- -------- ballPos
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- ----1--- -------- -------- dribblerSeesBall
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -----111 -------- -------- reserved1
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 1111---- -------- wheelLocked
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- ----1111 -------- wheelBraking
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 rssi
*/

#ifndef __REM_ROBOT_FEEDBACK_H
#define __REM_ROBOT_FEEDBACK_H

#include <stdbool.h>
#include <stdint.h>

#include "REM_BaseTypes.h"

typedef struct _REM_RobotFeedbackPayload {
    uint8_t payload[REM_PACKET_SIZE_REM_ROBOT_FEEDBACK];
} REM_RobotFeedbackPayload;

typedef struct _REM_RobotFeedback {
    uint32_t header;          // integer [0, 255]             Header byte indicating the type of packet
    uint32_t toRobotId;       // integer [0, 15]              Id of the receiving robot
    bool toColor;             // integer [0, 1]               Color of the receiving robot / basestation. Yellow = 0, Blue = 1
    bool toBC;                // integer [0, 1]               Bit indicating this packet has to be broadcasted to all robots
    bool toBS;                // integer [0, 1]               Bit indicating this packet is meant for the basestation
    bool toPC;                // integer [0, 1]               Bit indicating this packet is meant for the PC
    uint32_t fromRobotId;     // integer [0, 15]              Id of the transmitting robot
    bool fromColor;           // integer [0, 1]               Color of the transmitting robot / basestation. Yellow = 0, Blue = 1
    bool reserved;            // integer [0, 1]               reserved
    bool fromBS;              // integer [0, 1]               Bit indicating this packet is coming from the basestation
    bool fromPC;              // integer [0, 1]               Bit indicating this packet is coming from the PC
    uint32_t remVersion;      // integer [0, 15]              Version of roboteam_embedded_messages
    uint32_t messageId;       // integer [0, 15]              messageId. Can be used for aligning packets
    uint32_t timestamp;       // integer [0, 16777215]        Timestamp in milliseconds
    uint32_t payloadSize;     // integer [0, 255]             Size of the payload. At most 255 bytes including the generic_packet_header. Keep the 127 byte SX1280 limit in mind
    float rho;                // float   [0.000, 8.000]       The estimated magnitude of movement (m/s)
    float theta;              // float   [-3.142, 3.142]      The estimated direction of movement (rad)
    float angle;              // float   [-3.142, 3.142]      The estimated angle (rad)
    uint32_t batteryLevel;    // integer [0, 15]              The voltage level of the battery
    bool XsensCalibrated;     // integer [0, 1]               Indicates if the XSens IMU is calibrated
    bool capacitorCharged;    // integer [0, 1]               Indicates if the capacitor for kicking and chipping is charged
    bool ballSensorWorking;   // integer [0, 1]               Indicates if the ballsensor is working
    bool ballSensorSeesBall;  // integer [0, 1]               Indicates if the ballsensor sees the ball
    float ballPos;            // float   [-0.500, 0.500]      Indicates where in front of the ballsensor the ball is
    bool dribblerSeesBall;    // integer [0, 1]               Indicates if the dribbler sees the ball
    uint32_t reserved1;       // integer [0, 7]               reserved1
    uint32_t wheelLocked;     // integer [0, 15]              Indicates if a wheel is locked. One bit per wheel
    uint32_t wheelBraking;    // integer [0, 15]              Indicates if a wheel is slipping. One bit per wheel
    uint32_t rssi;            // integer [0, 255]             Signal strength of the last packet received by the robot
} REM_RobotFeedback;

// ================================ GETTERS ================================
static inline uint32_t REM_RobotFeedback_get_header(REM_RobotFeedbackPayload *remrfp) { return ((remrfp->payload[0])); }

static inline uint32_t REM_RobotFeedback_get_toRobotId(REM_RobotFeedbackPayload *remrfp) { return ((remrfp->payload[1] & 0b11110000) >> 4); }

static inline bool REM_RobotFeedback_get_toColor(REM_RobotFeedbackPayload *remrfp) { return (remrfp->payload[1] & 0b00001000) > 0; }

static inline bool REM_RobotFeedback_get_toBC(REM_RobotFeedbackPayload *remrfp) { return (remrfp->payload[1] & 0b00000100) > 0; }

static inline bool REM_RobotFeedback_get_toBS(REM_RobotFeedbackPayload *remrfp) { return (remrfp->payload[1] & 0b00000010) > 0; }

static inline bool REM_RobotFeedback_get_toPC(REM_RobotFeedbackPayload *remrfp) { return (remrfp->payload[1] & 0b00000001) > 0; }

static inline uint32_t REM_RobotFeedback_get_fromRobotId(REM_RobotFeedbackPayload *remrfp) { return ((remrfp->payload[2] & 0b11110000) >> 4); }

static inline bool REM_RobotFeedback_get_fromColor(REM_RobotFeedbackPayload *remrfp) { return (remrfp->payload[2] & 0b00001000) > 0; }

static inline bool REM_RobotFeedback_get_reserved(REM_RobotFeedbackPayload *remrfp) { return (remrfp->payload[2] & 0b00000100) > 0; }

static inline bool REM_RobotFeedback_get_fromBS(REM_RobotFeedbackPayload *remrfp) { return (remrfp->payload[2] & 0b00000010) > 0; }

static inline bool REM_RobotFeedback_get_fromPC(REM_RobotFeedbackPayload *remrfp) { return (remrfp->payload[2] & 0b00000001) > 0; }

static inline uint32_t REM_RobotFeedback_get_remVersion(REM_RobotFeedbackPayload *remrfp) { return ((remrfp->payload[3] & 0b11110000) >> 4); }

static inline uint32_t REM_RobotFeedback_get_messageId(REM_RobotFeedbackPayload *remrfp) { return ((remrfp->payload[3] & 0b00001111)); }

static inline uint32_t REM_RobotFeedback_get_timestamp(REM_RobotFeedbackPayload *remrfp) {
    return ((remrfp->payload[4]) << 16) | ((remrfp->payload[5]) << 8) | ((remrfp->payload[6]));
}

static inline uint32_t REM_RobotFeedback_get_payloadSize(REM_RobotFeedbackPayload *remrfp) { return ((remrfp->payload[7])); }

static inline float REM_RobotFeedback_get_rho(REM_RobotFeedbackPayload *remrfp) {
    uint32_t _rho = ((remrfp->payload[8]) << 8) | ((remrfp->payload[9]));
    return (_rho * 0.0001220721751736F);
}

static inline float REM_RobotFeedback_get_theta(REM_RobotFeedbackPayload *remrfp) {
    uint32_t _theta = ((remrfp->payload[10]) << 8) | ((remrfp->payload[11]));
    return (_theta * 0.0000958752621833F) + -3.1415926535897931F;
}

static inline float REM_RobotFeedback_get_angle(REM_RobotFeedbackPayload *remrfp) {
    uint32_t _angle = ((remrfp->payload[12]) << 8) | ((remrfp->payload[13]));
    return (_angle * 0.0000958752621833F) + -3.1415926535897931F;
}

static inline uint32_t REM_RobotFeedback_get_batteryLevel(REM_RobotFeedbackPayload *remrfp) { return ((remrfp->payload[14] & 0b11110000) >> 4); }

static inline bool REM_RobotFeedback_get_XsensCalibrated(REM_RobotFeedbackPayload *remrfp) { return (remrfp->payload[14] & 0b00001000) > 0; }

static inline bool REM_RobotFeedback_get_capacitorCharged(REM_RobotFeedbackPayload *remrfp) { return (remrfp->payload[14] & 0b00000100) > 0; }

static inline bool REM_RobotFeedback_get_ballSensorWorking(REM_RobotFeedbackPayload *remrfp) { return (remrfp->payload[14] & 0b00000010) > 0; }

static inline bool REM_RobotFeedback_get_ballSensorSeesBall(REM_RobotFeedbackPayload *remrfp) { return (remrfp->payload[14] & 0b00000001) > 0; }

static inline float REM_RobotFeedback_get_ballPos(REM_RobotFeedbackPayload *remrfp) {
    uint32_t _ballPos = ((remrfp->payload[15] & 0b11110000) >> 4);
    return (_ballPos * 0.0666666666666667F) + -0.5000000000000000F;
}

static inline bool REM_RobotFeedback_get_dribblerSeesBall(REM_RobotFeedbackPayload *remrfp) { return (remrfp->payload[15] & 0b00001000) > 0; }

static inline uint32_t REM_RobotFeedback_get_reserved1(REM_RobotFeedbackPayload *remrfp) { return ((remrfp->payload[15] & 0b00000111)); }

static inline uint32_t REM_RobotFeedback_get_wheelLocked(REM_RobotFeedbackPayload *remrfp) { return ((remrfp->payload[16] & 0b11110000) >> 4); }

static inline uint32_t REM_RobotFeedback_get_wheelBraking(REM_RobotFeedbackPayload *remrfp) { return ((remrfp->payload[16] & 0b00001111)); }

static inline uint32_t REM_RobotFeedback_get_rssi(REM_RobotFeedbackPayload *remrfp) { return ((remrfp->payload[17])); }

// ================================ SETTERS ================================
static inline void REM_RobotFeedback_set_header(REM_RobotFeedbackPayload *remrfp, uint32_t header) { remrfp->payload[0] = header; }

static inline void REM_RobotFeedback_set_toRobotId(REM_RobotFeedbackPayload *remrfp, uint32_t toRobotId) {
    remrfp->payload[1] = ((toRobotId << 4) & 0b11110000) | (remrfp->payload[1] & 0b00001111);
}

static inline void REM_RobotFeedback_set_toColor(REM_RobotFeedbackPayload *remrfp, bool toColor) {
    remrfp->payload[1] = ((toColor << 3) & 0b00001000) | (remrfp->payload[1] & 0b11110111);
}

static inline void REM_RobotFeedback_set_toBC(REM_RobotFeedbackPayload *remrfp, bool toBC) { remrfp->payload[1] = ((toBC << 2) & 0b00000100) | (remrfp->payload[1] & 0b11111011); }

static inline void REM_RobotFeedback_set_toBS(REM_RobotFeedbackPayload *remrfp, bool toBS) { remrfp->payload[1] = ((toBS << 1) & 0b00000010) | (remrfp->payload[1] & 0b11111101); }

static inline void REM_RobotFeedback_set_toPC(REM_RobotFeedbackPayload *remrfp, bool toPC) { remrfp->payload[1] = (toPC & 0b00000001) | (remrfp->payload[1] & 0b11111110); }

static inline void REM_RobotFeedback_set_fromRobotId(REM_RobotFeedbackPayload *remrfp, uint32_t fromRobotId) {
    remrfp->payload[2] = ((fromRobotId << 4) & 0b11110000) | (remrfp->payload[2] & 0b00001111);
}

static inline void REM_RobotFeedback_set_fromColor(REM_RobotFeedbackPayload *remrfp, bool fromColor) {
    remrfp->payload[2] = ((fromColor << 3) & 0b00001000) | (remrfp->payload[2] & 0b11110111);
}

static inline void REM_RobotFeedback_set_reserved(REM_RobotFeedbackPayload *remrfp, bool reserved) {
    remrfp->payload[2] = ((reserved << 2) & 0b00000100) | (remrfp->payload[2] & 0b11111011);
}

static inline void REM_RobotFeedback_set_fromBS(REM_RobotFeedbackPayload *remrfp, bool fromBS) {
    remrfp->payload[2] = ((fromBS << 1) & 0b00000010) | (remrfp->payload[2] & 0b11111101);
}

static inline void REM_RobotFeedback_set_fromPC(REM_RobotFeedbackPayload *remrfp, bool fromPC) { remrfp->payload[2] = (fromPC & 0b00000001) | (remrfp->payload[2] & 0b11111110); }

static inline void REM_RobotFeedback_set_remVersion(REM_RobotFeedbackPayload *remrfp, uint32_t remVersion) {
    remrfp->payload[3] = ((remVersion << 4) & 0b11110000) | (remrfp->payload[3] & 0b00001111);
}

static inline void REM_RobotFeedback_set_messageId(REM_RobotFeedbackPayload *remrfp, uint32_t messageId) {
    remrfp->payload[3] = (messageId & 0b00001111) | (remrfp->payload[3] & 0b11110000);
}

static inline void REM_RobotFeedback_set_timestamp(REM_RobotFeedbackPayload *remrfp, uint32_t timestamp) {
    remrfp->payload[4] = (timestamp >> 16);
    remrfp->payload[5] = (timestamp >> 8);
    remrfp->payload[6] = timestamp;
}

static inline void REM_RobotFeedback_set_payloadSize(REM_RobotFeedbackPayload *remrfp, uint32_t payloadSize) { remrfp->payload[7] = payloadSize; }

static inline void REM_RobotFeedback_set_rho(REM_RobotFeedbackPayload *remrfp, float rho) {
    uint32_t _rho = (uint32_t)(rho / 0.0001220721751736F);
    remrfp->payload[8] = (_rho >> 8);
    remrfp->payload[9] = _rho;
}

static inline void REM_RobotFeedback_set_theta(REM_RobotFeedbackPayload *remrfp, float theta) {
    uint32_t _theta = (uint32_t)((theta + 3.1415926535897931F) / 0.0000958752621833F);
    remrfp->payload[10] = (_theta >> 8);
    remrfp->payload[11] = _theta;
}

static inline void REM_RobotFeedback_set_angle(REM_RobotFeedbackPayload *remrfp, float angle) {
    uint32_t _angle = (uint32_t)((angle + 3.1415926535897931F) / 0.0000958752621833F);
    remrfp->payload[12] = (_angle >> 8);
    remrfp->payload[13] = _angle;
}

static inline void REM_RobotFeedback_set_batteryLevel(REM_RobotFeedbackPayload *remrfp, uint32_t batteryLevel) {
    remrfp->payload[14] = ((batteryLevel << 4) & 0b11110000) | (remrfp->payload[14] & 0b00001111);
}

static inline void REM_RobotFeedback_set_XsensCalibrated(REM_RobotFeedbackPayload *remrfp, bool XsensCalibrated) {
    remrfp->payload[14] = ((XsensCalibrated << 3) & 0b00001000) | (remrfp->payload[14] & 0b11110111);
}

static inline void REM_RobotFeedback_set_capacitorCharged(REM_RobotFeedbackPayload *remrfp, bool capacitorCharged) {
    remrfp->payload[14] = ((capacitorCharged << 2) & 0b00000100) | (remrfp->payload[14] & 0b11111011);
}

static inline void REM_RobotFeedback_set_ballSensorWorking(REM_RobotFeedbackPayload *remrfp, bool ballSensorWorking) {
    remrfp->payload[14] = ((ballSensorWorking << 1) & 0b00000010) | (remrfp->payload[14] & 0b11111101);
}

static inline void REM_RobotFeedback_set_ballSensorSeesBall(REM_RobotFeedbackPayload *remrfp, bool ballSensorSeesBall) {
    remrfp->payload[14] = (ballSensorSeesBall & 0b00000001) | (remrfp->payload[14] & 0b11111110);
}

static inline void REM_RobotFeedback_set_ballPos(REM_RobotFeedbackPayload *remrfp, float ballPos) {
    uint32_t _ballPos = (uint32_t)((ballPos + 0.5000000000000000F) / 0.0666666666666667F);
    remrfp->payload[15] = ((_ballPos << 4) & 0b11110000) | (remrfp->payload[15] & 0b00001111);
}

static inline void REM_RobotFeedback_set_dribblerSeesBall(REM_RobotFeedbackPayload *remrfp, bool dribblerSeesBall) {
    remrfp->payload[15] = ((dribblerSeesBall << 3) & 0b00001000) | (remrfp->payload[15] & 0b11110111);
}

static inline void REM_RobotFeedback_set_reserved1(REM_RobotFeedbackPayload *remrfp, uint32_t reserved1) {
    remrfp->payload[15] = (reserved1 & 0b00000111) | (remrfp->payload[15] & 0b11111000);
}

static inline void REM_RobotFeedback_set_wheelLocked(REM_RobotFeedbackPayload *remrfp, uint32_t wheelLocked) {
    remrfp->payload[16] = ((wheelLocked << 4) & 0b11110000) | (remrfp->payload[16] & 0b00001111);
}

static inline void REM_RobotFeedback_set_wheelBraking(REM_RobotFeedbackPayload *remrfp, uint32_t wheelBraking) {
    remrfp->payload[16] = (wheelBraking & 0b00001111) | (remrfp->payload[16] & 0b11110000);
}

static inline void REM_RobotFeedback_set_rssi(REM_RobotFeedbackPayload *remrfp, uint32_t rssi) { remrfp->payload[17] = rssi; }

// ================================ ENCODE ================================
static inline void encodeREM_RobotFeedback(REM_RobotFeedbackPayload *remrfp, REM_RobotFeedback *remrf) {
    REM_RobotFeedback_set_header(remrfp, remrf->header);
    REM_RobotFeedback_set_toRobotId(remrfp, remrf->toRobotId);
    REM_RobotFeedback_set_toColor(remrfp, remrf->toColor);
    REM_RobotFeedback_set_toBC(remrfp, remrf->toBC);
    REM_RobotFeedback_set_toBS(remrfp, remrf->toBS);
    REM_RobotFeedback_set_toPC(remrfp, remrf->toPC);
    REM_RobotFeedback_set_fromRobotId(remrfp, remrf->fromRobotId);
    REM_RobotFeedback_set_fromColor(remrfp, remrf->fromColor);
    REM_RobotFeedback_set_reserved(remrfp, remrf->reserved);
    REM_RobotFeedback_set_fromBS(remrfp, remrf->fromBS);
    REM_RobotFeedback_set_fromPC(remrfp, remrf->fromPC);
    REM_RobotFeedback_set_remVersion(remrfp, remrf->remVersion);
    REM_RobotFeedback_set_messageId(remrfp, remrf->messageId);
    REM_RobotFeedback_set_timestamp(remrfp, remrf->timestamp);
    REM_RobotFeedback_set_payloadSize(remrfp, remrf->payloadSize);
    REM_RobotFeedback_set_rho(remrfp, remrf->rho);
    REM_RobotFeedback_set_theta(remrfp, remrf->theta);
    REM_RobotFeedback_set_angle(remrfp, remrf->angle);
    REM_RobotFeedback_set_batteryLevel(remrfp, remrf->batteryLevel);
    REM_RobotFeedback_set_XsensCalibrated(remrfp, remrf->XsensCalibrated);
    REM_RobotFeedback_set_capacitorCharged(remrfp, remrf->capacitorCharged);
    REM_RobotFeedback_set_ballSensorWorking(remrfp, remrf->ballSensorWorking);
    REM_RobotFeedback_set_ballSensorSeesBall(remrfp, remrf->ballSensorSeesBall);
    REM_RobotFeedback_set_ballPos(remrfp, remrf->ballPos);
    REM_RobotFeedback_set_dribblerSeesBall(remrfp, remrf->dribblerSeesBall);
    REM_RobotFeedback_set_reserved1(remrfp, remrf->reserved1);
    REM_RobotFeedback_set_wheelLocked(remrfp, remrf->wheelLocked);
    REM_RobotFeedback_set_wheelBraking(remrfp, remrf->wheelBraking);
    REM_RobotFeedback_set_rssi(remrfp, remrf->rssi);
}

// ================================ DECODE ================================
static inline void decodeREM_RobotFeedback(REM_RobotFeedback *remrf, REM_RobotFeedbackPayload *remrfp) {
    remrf->header = REM_RobotFeedback_get_header(remrfp);
    remrf->toRobotId = REM_RobotFeedback_get_toRobotId(remrfp);
    remrf->toColor = REM_RobotFeedback_get_toColor(remrfp);
    remrf->toBC = REM_RobotFeedback_get_toBC(remrfp);
    remrf->toBS = REM_RobotFeedback_get_toBS(remrfp);
    remrf->toPC = REM_RobotFeedback_get_toPC(remrfp);
    remrf->fromRobotId = REM_RobotFeedback_get_fromRobotId(remrfp);
    remrf->fromColor = REM_RobotFeedback_get_fromColor(remrfp);
    remrf->reserved = REM_RobotFeedback_get_reserved(remrfp);
    remrf->fromBS = REM_RobotFeedback_get_fromBS(remrfp);
    remrf->fromPC = REM_RobotFeedback_get_fromPC(remrfp);
    remrf->remVersion = REM_RobotFeedback_get_remVersion(remrfp);
    remrf->messageId = REM_RobotFeedback_get_messageId(remrfp);
    remrf->timestamp = REM_RobotFeedback_get_timestamp(remrfp);
    remrf->payloadSize = REM_RobotFeedback_get_payloadSize(remrfp);
    remrf->rho = REM_RobotFeedback_get_rho(remrfp);
    remrf->theta = REM_RobotFeedback_get_theta(remrfp);
    remrf->angle = REM_RobotFeedback_get_angle(remrfp);
    remrf->batteryLevel = REM_RobotFeedback_get_batteryLevel(remrfp);
    remrf->XsensCalibrated = REM_RobotFeedback_get_XsensCalibrated(remrfp);
    remrf->capacitorCharged = REM_RobotFeedback_get_capacitorCharged(remrfp);
    remrf->ballSensorWorking = REM_RobotFeedback_get_ballSensorWorking(remrfp);
    remrf->ballSensorSeesBall = REM_RobotFeedback_get_ballSensorSeesBall(remrfp);
    remrf->ballPos = REM_RobotFeedback_get_ballPos(remrfp);
    remrf->dribblerSeesBall = REM_RobotFeedback_get_dribblerSeesBall(remrfp);
    remrf->reserved1 = REM_RobotFeedback_get_reserved1(remrfp);
    remrf->wheelLocked = REM_RobotFeedback_get_wheelLocked(remrfp);
    remrf->wheelBraking = REM_RobotFeedback_get_wheelBraking(remrfp);
    remrf->rssi = REM_RobotFeedback_get_rssi(remrfp);
}

#endif /*__REM_ROBOT_FEEDBACK_H*/
