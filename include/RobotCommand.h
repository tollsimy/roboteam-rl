// AUTOGENERATED. Run generator/main.py to regenerate
// Generated on July 04 2021, 22:47:52

/*
[  0   ] [  1   ] [  2   ] [  3   ] [  4   ] [  5   ] [  6   ] [  7   ] [  8   ] [  9   ] [  10  ] [  11  ]
11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- header
-------- 1111---- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- id
-------- ----1111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- messageId
-------- -------- 1------- -------- -------- -------- -------- -------- -------- -------- -------- -------- doKick
-------- -------- -1------ -------- -------- -------- -------- -------- -------- -------- -------- -------- doChip
-------- -------- --1----- -------- -------- -------- -------- -------- -------- -------- -------- -------- doForce
-------- -------- ---1---- -------- -------- -------- -------- -------- -------- -------- -------- -------- useCameraAngle
-------- -------- ----1111 11111111 1111---- -------- -------- -------- -------- -------- -------- -------- rho
-------- -------- -------- -------- ----1111 11111111 1111---- -------- -------- -------- -------- -------- theta
-------- -------- -------- -------- -------- -------- ----1111 11111111 1111---- -------- -------- -------- angle
-------- -------- -------- -------- -------- -------- -------- -------- ----1111 11111111 1111---- -------- cameraAngle
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- ----111- -------- dribbler
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------1 11------ kickChipPower
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- --1----- angularControl
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- ---1---- feedback
*/

#ifndef __ROBOT_COMMAND_H
#define __ROBOT_COMMAND_H

#include <stdbool.h>
#include <stdint.h>
#include "BaseTypes.h"

typedef struct _RobotCommandPayload {
    uint8_t payload[PACKET_SIZE_ROBOT_COMMAND];
} RobotCommandPayload;

typedef struct _RobotCommand {
    uint32_t   header              ; // Header byte indicating the type of packet
    uint32_t   id                  ; // Id of the robot
    uint32_t   messageId           ; // Id of the message
    bool       doKick              ; // Do a kick if ballsensor
    bool       doChip              ; // Do a chip if ballsensor
    bool       doForce             ; // Do regardless of ballsensor
    bool       useCameraAngle      ; // Use the info in 'cameraAngle'
    float      rho                 ; // Magnitude of movement (m/s)
    float      theta               ; // Direction of movement (radians)
    float      angle               ; // Absolute angle (rad) / angular velocity (rad/s)
    float      cameraAngle         ; // Angle of the robot as seen by camera (rad)
    uint32_t   dribbler            ; // Dribbler speed
    uint32_t   kickChipPower       ; // Power of the kick or chip
    bool       angularControl      ; // 0 = angular velocity, 1 = absolute angle
    bool       feedback            ; // Ignore the packet. Just send feedback
} RobotCommand;

// ================================ GETTERS ================================
static inline uint32_t RobotCommand_get_header(RobotCommandPayload *rcp){
    return ((rcp->payload[0]));
}

static inline uint32_t RobotCommand_get_id(RobotCommandPayload *rcp){
    return ((rcp->payload[1] & 0b11110000) >> 4);
}

static inline uint32_t RobotCommand_get_messageId(RobotCommandPayload *rcp){
    return ((rcp->payload[1] & 0b00001111));
}

static inline bool RobotCommand_get_doKick(RobotCommandPayload *rcp){
    return (rcp->payload[2] & 0b10000000) > 0}

static inline bool RobotCommand_get_doChip(RobotCommandPayload *rcp){
    return (rcp->payload[2] & 0b01000000) > 0}

static inline bool RobotCommand_get_doForce(RobotCommandPayload *rcp){
    return (rcp->payload[2] & 0b00100000) > 0}

static inline bool RobotCommand_get_useCameraAngle(RobotCommandPayload *rcp){
    return (rcp->payload[2] & 0b00010000) > 0}

static inline float RobotCommand_get_rho(RobotCommandPayload *rcp){
    _rho = ((rcp->payload[2] & 0b00001111) << 12) | ((rcp->payload[3]) << 4) | ((rcp->payload[4] & 0b11110000) >> 4);
    return (_rho * 0.0001220703125000) + 0.0000000000000000;
}

static inline float RobotCommand_get_theta(RobotCommandPayload *rcp){
    _theta = ((rcp->payload[4] & 0b00001111) << 12) | ((rcp->payload[5]) << 4) | ((rcp->payload[6] & 0b11110000) >> 4);
    return (_theta * 0.0000958737992429) + -3.1415926535897931;
}

static inline float RobotCommand_get_angle(RobotCommandPayload *rcp){
    _angle = ((rcp->payload[6] & 0b00001111) << 12) | ((rcp->payload[7]) << 4) | ((rcp->payload[8] & 0b11110000) >> 4);
    return (_angle * 0.0000958737992429) + -3.1415926535897931;
}

static inline float RobotCommand_get_cameraAngle(RobotCommandPayload *rcp){
    _cameraAngle = ((rcp->payload[8] & 0b00001111) << 12) | ((rcp->payload[9]) << 4) | ((rcp->payload[10] & 0b11110000) >> 4);
    return (_cameraAngle * 0.0000958737992429) + -3.1415926535897931;
}

static inline uint32_t RobotCommand_get_dribbler(RobotCommandPayload *rcp){
    return ((rcp->payload[10] & 0b00001110) >> 1);
}

static inline uint32_t RobotCommand_get_kickChipPower(RobotCommandPayload *rcp){
    return ((rcp->payload[10] & 0b00000001) << 2) | ((rcp->payload[11] & 0b11000000) >> 6);
}

static inline bool RobotCommand_get_angularControl(RobotCommandPayload *rcp){
    return (rcp->payload[11] & 0b00100000) > 0}

static inline bool RobotCommand_get_feedback(RobotCommandPayload *rcp){
    return (rcp->payload[11] & 0b00010000) > 0}

// ================================ SETTERS ================================
static inline void RobotCommand_set_header(RobotCommandPayload *rcp, uint32_t header){
    rcp->payload[0] = header;
}

static inline void RobotCommand_set_id(RobotCommandPayload *rcp, uint32_t id){
    rcp->payload[1] = ((id << 4) & 0b11110000) | (payload[1] & 0b00001111);
}

static inline void RobotCommand_set_messageId(RobotCommandPayload *rcp, uint32_t messageId){
    rcp->payload[1] = (messageId & 0b00001111) | (payload[1] & 0b11110000);
}

static inline void RobotCommand_set_doKick(RobotCommandPayload *rcp, bool doKick){
    rcp->payload[2] = ((doKick << 7) & 0b10000000) | (payload[2] & 0b01111111);
}

static inline void RobotCommand_set_doChip(RobotCommandPayload *rcp, bool doChip){
    rcp->payload[2] = ((doChip << 6) & 0b01000000) | (payload[2] & 0b10111111);
}

static inline void RobotCommand_set_doForce(RobotCommandPayload *rcp, bool doForce){
    rcp->payload[2] = ((doForce << 5) & 0b00100000) | (payload[2] & 0b11011111);
}

static inline void RobotCommand_set_useCameraAngle(RobotCommandPayload *rcp, bool useCameraAngle){
    rcp->payload[2] = ((useCameraAngle << 4) & 0b00010000) | (payload[2] & 0b11101111);
}

static inline void RobotCommand_set_rho(RobotCommandPayload *rcp, float rho){
    _rho = int(rho / 0.0001220703125000)
    rcp->payload[2] = ((_rho >> 12) & 0b00001111) | (payload[2] & 0b11110000);
    rcp->payload[3] = (_rho >> 8);
    rcp->payload[4] = ((_rho >> 8) & 0b11110000) | (payload[4] & 0b00001111);
}

static inline void RobotCommand_set_theta(RobotCommandPayload *rcp, float theta){
    _theta = int((theta +3.1415926535897931) / 0.0000958737992429)
    rcp->payload[4] = ((_theta >> 12) & 0b00001111) | (payload[4] & 0b11110000);
    rcp->payload[5] = (_theta >> 8);
    rcp->payload[6] = ((_theta >> 8) & 0b11110000) | (payload[6] & 0b00001111);
}

static inline void RobotCommand_set_angle(RobotCommandPayload *rcp, float angle){
    _angle = int((angle +3.1415926535897931) / 0.0000958737992429)
    rcp->payload[6] = ((_angle >> 12) & 0b00001111) | (payload[6] & 0b11110000);
    rcp->payload[7] = (_angle >> 8);
    rcp->payload[8] = ((_angle >> 8) & 0b11110000) | (payload[8] & 0b00001111);
}

static inline void RobotCommand_set_cameraAngle(RobotCommandPayload *rcp, float cameraAngle){
    _cameraAngle = int((cameraAngle +3.1415926535897931) / 0.0000958737992429)
    rcp->payload[8] = ((_cameraAngle >> 12) & 0b00001111) | (payload[8] & 0b11110000);
    rcp->payload[9] = (_cameraAngle >> 8);
    rcp->payload[10] = ((_cameraAngle >> 8) & 0b11110000) | (payload[10] & 0b00001111);
}

static inline void RobotCommand_set_dribbler(RobotCommandPayload *rcp, uint32_t dribbler){
    rcp->payload[10] = ((dribbler << 1) & 0b00001110) | (payload[10] & 0b11110001);
}

static inline void RobotCommand_set_kickChipPower(RobotCommandPayload *rcp, uint32_t kickChipPower){
    rcp->payload[10] = ((kickChipPower >> 2) & 0b00000001) | (payload[10] & 0b11111110);
    rcp->payload[11] = ((kickChipPower << 5) & 0b11000000) | (payload[11] & 0b00111111);
}

static inline void RobotCommand_set_angularControl(RobotCommandPayload *rcp, bool angularControl){
    rcp->payload[11] = ((angularControl << 5) & 0b00100000) | (payload[11] & 0b11011111);
}

static inline void RobotCommand_set_feedback(RobotCommandPayload *rcp, bool feedback){
    rcp->payload[11] = ((feedback << 4) & 0b00010000) | (payload[11] & 0b11101111);
}

// ================================ ENCODE ================================
static inline void encodeRobotCommand(RobotCommandPayload *rcp, RobotCommand *rc){
    RobotCommand_set_header              (rcp, rc->header);
    RobotCommand_set_id                  (rcp, rc->id);
    RobotCommand_set_messageId           (rcp, rc->messageId);
    RobotCommand_set_doKick              (rcp, rc->doKick);
    RobotCommand_set_doChip              (rcp, rc->doChip);
    RobotCommand_set_doForce             (rcp, rc->doForce);
    RobotCommand_set_useCameraAngle      (rcp, rc->useCameraAngle);
    RobotCommand_set_rho                 (rcp, rc->rho);
    RobotCommand_set_theta               (rcp, rc->theta);
    RobotCommand_set_angle               (rcp, rc->angle);
    RobotCommand_set_cameraAngle         (rcp, rc->cameraAngle);
    RobotCommand_set_dribbler            (rcp, rc->dribbler);
    RobotCommand_set_kickChipPower       (rcp, rc->kickChipPower);
    RobotCommand_set_angularControl      (rcp, rc->angularControl);
    RobotCommand_set_feedback            (rcp, rc->feedback);
}

// ================================ DECODE ================================
static inline void decodeRobotCommand(RobotCommand *rc, RobotCommandPayload *rcp){
    rc->header           = RobotCommand_get_header(rcp);
    rc->id               = RobotCommand_get_id(rcp);
    rc->messageId        = RobotCommand_get_messageId(rcp);
    rc->doKick           = RobotCommand_get_doKick(rcp);
    rc->doChip           = RobotCommand_get_doChip(rcp);
    rc->doForce          = RobotCommand_get_doForce(rcp);
    rc->useCameraAngle   = RobotCommand_get_useCameraAngle(rcp);
    rc->rho              = RobotCommand_get_rho(rcp);
    rc->theta            = RobotCommand_get_theta(rcp);
    rc->angle            = RobotCommand_get_angle(rcp);
    rc->cameraAngle      = RobotCommand_get_cameraAngle(rcp);
    rc->dribbler         = RobotCommand_get_dribbler(rcp);
    rc->kickChipPower    = RobotCommand_get_kickChipPower(rcp);
    rc->angularControl   = RobotCommand_get_angularControl(rcp);
    rc->feedback         = RobotCommand_get_feedback(rcp);
}

#endif /*__ROBOT_COMMAND_H*/
