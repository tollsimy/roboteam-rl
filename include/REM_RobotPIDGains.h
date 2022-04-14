// AUTOGENERATED. Run generator/main.py to regenerate
/*
[  0   ] [  1   ] [  2   ] [  3   ] [  4   ] [  5   ] [  6   ] [  7   ] [  8   ] [  9   ] [  10  ] [  11  ] [  12  ] [  13  ] [  14  ] [  15  ] [  16  ] [  17  ] [  18  ] [  19  ] [  20  ] [  21  ] [  22  ] [  23  ] [  24  ] [  25  ]
11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- header
-------- 1111---- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- remVersion
-------- ----1111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- id
-------- -------- 11111111 11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- PbodyX
-------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- IbodyX
-------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- DbodyX
-------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- PbodyY
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- IbodyY
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- DbodyY
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- PbodyYaw
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- -------- -------- -------- -------- IbodyYaw
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- -------- -------- DbodyYaw
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- Pwheels
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- Iwheels
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 Dwheels
*/

#ifndef __REM_ROBOT_PIDGAINS_H
#define __REM_ROBOT_PIDGAINS_H

#include <stdbool.h>
#include <stdint.h>
#include "REM_BaseTypes.h"

typedef struct _REM_RobotPIDGainsPayload {
    uint8_t payload[PACKET_SIZE_REM_ROBOT_PIDGAINS];
} REM_RobotPIDGainsPayload;

typedef struct _REM_RobotPIDGains {
    uint32_t   header              ; // integer [0, 255]             Header byte indicating the type of packet
    uint32_t   remVersion          ; // integer [0, 15]              Version of roboteam_embedded_messages
    uint32_t   id                  ; // integer [0, 15]              Id of the robot
    float      PbodyX              ; // float   [0.000, 40.000]      Received P gain of the PID for body_x (x-direction)
    float      IbodyX              ; // float   [0.000, 20.000]      Received I gain of the PID for body_x (x-direction)
    float      DbodyX              ; // float   [0.000, 10.000]      Received D gain of the PID for body_x (x-direction)
    float      PbodyY              ; // float   [0.000, 40.000]      Received P gain of the PID for body_y (y-direction)
    float      IbodyY              ; // float   [0.000, 20.000]      Received I gain of the PID for body_y (y-direction)
    float      DbodyY              ; // float   [0.000, 10.000]      Received D gain of the PID for body_y (y-direction)
    float      PbodyYaw            ; // float   [0.000, 40.000]      Received P gain of the PID for body_yaw (Absolute angle)
    float      IbodyYaw            ; // float   [0.000, 20.000]      Received I gain of the PID for body_yaw (Absolute angle)
    float      DbodyYaw            ; // float   [0.000, 10.000]      Received D gain of the PID for body_yaw (Absolute angle)
    float      Pwheels             ; // float   [0.000, 40.000]      Received P gain of the PID for the wheels
    float      Iwheels             ; // float   [0.000, 20.000]      Received I gain of the PID for the wheels
    float      Dwheels             ; // float   [0.000, 10.000]      Received D gain of the PID for the wheels
} REM_RobotPIDGains;

// ================================ GETTERS ================================
static inline uint32_t REM_RobotPIDGains_get_header(REM_RobotPIDGainsPayload *remrpidgp){
    return ((remrpidgp->payload[0]));
}

static inline uint32_t REM_RobotPIDGains_get_remVersion(REM_RobotPIDGainsPayload *remrpidgp){
    return ((remrpidgp->payload[1] & 0b11110000) >> 4);
}

static inline uint32_t REM_RobotPIDGains_get_id(REM_RobotPIDGainsPayload *remrpidgp){
    return ((remrpidgp->payload[1] & 0b00001111));
}

static inline float REM_RobotPIDGains_get_PbodyX(REM_RobotPIDGainsPayload *remrpidgp){
    uint32_t _PbodyX = ((remrpidgp->payload[2]) << 8) | ((remrpidgp->payload[3]));
    return (_PbodyX * 0.0006103608758679) + 0.0000000000000000;
}

static inline float REM_RobotPIDGains_get_IbodyX(REM_RobotPIDGainsPayload *remrpidgp){
    uint32_t _IbodyX = ((remrpidgp->payload[4]) << 8) | ((remrpidgp->payload[5]));
    return (_IbodyX * 0.0003051804379339) + 0.0000000000000000;
}

static inline float REM_RobotPIDGains_get_DbodyX(REM_RobotPIDGainsPayload *remrpidgp){
    uint32_t _DbodyX = ((remrpidgp->payload[6]) << 8) | ((remrpidgp->payload[7]));
    return (_DbodyX * 0.0001525902189670) + 0.0000000000000000;
}

static inline float REM_RobotPIDGains_get_PbodyY(REM_RobotPIDGainsPayload *remrpidgp){
    uint32_t _PbodyY = ((remrpidgp->payload[8]) << 8) | ((remrpidgp->payload[9]));
    return (_PbodyY * 0.0006103608758679) + 0.0000000000000000;
}

static inline float REM_RobotPIDGains_get_IbodyY(REM_RobotPIDGainsPayload *remrpidgp){
    uint32_t _IbodyY = ((remrpidgp->payload[10]) << 8) | ((remrpidgp->payload[11]));
    return (_IbodyY * 0.0003051804379339) + 0.0000000000000000;
}

static inline float REM_RobotPIDGains_get_DbodyY(REM_RobotPIDGainsPayload *remrpidgp){
    uint32_t _DbodyY = ((remrpidgp->payload[12]) << 8) | ((remrpidgp->payload[13]));
    return (_DbodyY * 0.0001525902189670) + 0.0000000000000000;
}

static inline float REM_RobotPIDGains_get_PbodyYaw(REM_RobotPIDGainsPayload *remrpidgp){
    uint32_t _PbodyYaw = ((remrpidgp->payload[14]) << 8) | ((remrpidgp->payload[15]));
    return (_PbodyYaw * 0.0006103608758679) + 0.0000000000000000;
}

static inline float REM_RobotPIDGains_get_IbodyYaw(REM_RobotPIDGainsPayload *remrpidgp){
    uint32_t _IbodyYaw = ((remrpidgp->payload[16]) << 8) | ((remrpidgp->payload[17]));
    return (_IbodyYaw * 0.0003051804379339) + 0.0000000000000000;
}

static inline float REM_RobotPIDGains_get_DbodyYaw(REM_RobotPIDGainsPayload *remrpidgp){
    uint32_t _DbodyYaw = ((remrpidgp->payload[18]) << 8) | ((remrpidgp->payload[19]));
    return (_DbodyYaw * 0.0001525902189670) + 0.0000000000000000;
}

static inline float REM_RobotPIDGains_get_Pwheels(REM_RobotPIDGainsPayload *remrpidgp){
    uint32_t _Pwheels = ((remrpidgp->payload[20]) << 8) | ((remrpidgp->payload[21]));
    return (_Pwheels * 0.0006103608758679) + 0.0000000000000000;
}

static inline float REM_RobotPIDGains_get_Iwheels(REM_RobotPIDGainsPayload *remrpidgp){
    uint32_t _Iwheels = ((remrpidgp->payload[22]) << 8) | ((remrpidgp->payload[23]));
    return (_Iwheels * 0.0003051804379339) + 0.0000000000000000;
}

static inline float REM_RobotPIDGains_get_Dwheels(REM_RobotPIDGainsPayload *remrpidgp){
    uint32_t _Dwheels = ((remrpidgp->payload[24]) << 8) | ((remrpidgp->payload[25]));
    return (_Dwheels * 0.0001525902189670) + 0.0000000000000000;
}

// ================================ SETTERS ================================
static inline void REM_RobotPIDGains_set_header(REM_RobotPIDGainsPayload *remrpidgp, uint32_t header){
    remrpidgp->payload[0] = header;
}

static inline void REM_RobotPIDGains_set_remVersion(REM_RobotPIDGainsPayload *remrpidgp, uint32_t remVersion){
    remrpidgp->payload[1] = ((remVersion << 4) & 0b11110000) | (remrpidgp->payload[1] & 0b00001111);
}

static inline void REM_RobotPIDGains_set_id(REM_RobotPIDGainsPayload *remrpidgp, uint32_t id){
    remrpidgp->payload[1] = (id & 0b00001111) | (remrpidgp->payload[1] & 0b11110000);
}

static inline void REM_RobotPIDGains_set_PbodyX(REM_RobotPIDGainsPayload *remrpidgp, float PbodyX){
    uint32_t _PbodyX = (uint32_t)(PbodyX / 0.0006103608758679);
    remrpidgp->payload[2] = (_PbodyX >> 8);
    remrpidgp->payload[3] = _PbodyX;
}

static inline void REM_RobotPIDGains_set_IbodyX(REM_RobotPIDGainsPayload *remrpidgp, float IbodyX){
    uint32_t _IbodyX = (uint32_t)(IbodyX / 0.0003051804379339);
    remrpidgp->payload[4] = (_IbodyX >> 8);
    remrpidgp->payload[5] = _IbodyX;
}

static inline void REM_RobotPIDGains_set_DbodyX(REM_RobotPIDGainsPayload *remrpidgp, float DbodyX){
    uint32_t _DbodyX = (uint32_t)(DbodyX / 0.0001525902189670);
    remrpidgp->payload[6] = (_DbodyX >> 8);
    remrpidgp->payload[7] = _DbodyX;
}

static inline void REM_RobotPIDGains_set_PbodyY(REM_RobotPIDGainsPayload *remrpidgp, float PbodyY){
    uint32_t _PbodyY = (uint32_t)(PbodyY / 0.0006103608758679);
    remrpidgp->payload[8] = (_PbodyY >> 8);
    remrpidgp->payload[9] = _PbodyY;
}

static inline void REM_RobotPIDGains_set_IbodyY(REM_RobotPIDGainsPayload *remrpidgp, float IbodyY){
    uint32_t _IbodyY = (uint32_t)(IbodyY / 0.0003051804379339);
    remrpidgp->payload[10] = (_IbodyY >> 8);
    remrpidgp->payload[11] = _IbodyY;
}

static inline void REM_RobotPIDGains_set_DbodyY(REM_RobotPIDGainsPayload *remrpidgp, float DbodyY){
    uint32_t _DbodyY = (uint32_t)(DbodyY / 0.0001525902189670);
    remrpidgp->payload[12] = (_DbodyY >> 8);
    remrpidgp->payload[13] = _DbodyY;
}

static inline void REM_RobotPIDGains_set_PbodyYaw(REM_RobotPIDGainsPayload *remrpidgp, float PbodyYaw){
    uint32_t _PbodyYaw = (uint32_t)(PbodyYaw / 0.0006103608758679);
    remrpidgp->payload[14] = (_PbodyYaw >> 8);
    remrpidgp->payload[15] = _PbodyYaw;
}

static inline void REM_RobotPIDGains_set_IbodyYaw(REM_RobotPIDGainsPayload *remrpidgp, float IbodyYaw){
    uint32_t _IbodyYaw = (uint32_t)(IbodyYaw / 0.0003051804379339);
    remrpidgp->payload[16] = (_IbodyYaw >> 8);
    remrpidgp->payload[17] = _IbodyYaw;
}

static inline void REM_RobotPIDGains_set_DbodyYaw(REM_RobotPIDGainsPayload *remrpidgp, float DbodyYaw){
    uint32_t _DbodyYaw = (uint32_t)(DbodyYaw / 0.0001525902189670);
    remrpidgp->payload[18] = (_DbodyYaw >> 8);
    remrpidgp->payload[19] = _DbodyYaw;
}

static inline void REM_RobotPIDGains_set_Pwheels(REM_RobotPIDGainsPayload *remrpidgp, float Pwheels){
    uint32_t _Pwheels = (uint32_t)(Pwheels / 0.0006103608758679);
    remrpidgp->payload[20] = (_Pwheels >> 8);
    remrpidgp->payload[21] = _Pwheels;
}

static inline void REM_RobotPIDGains_set_Iwheels(REM_RobotPIDGainsPayload *remrpidgp, float Iwheels){
    uint32_t _Iwheels = (uint32_t)(Iwheels / 0.0003051804379339);
    remrpidgp->payload[22] = (_Iwheels >> 8);
    remrpidgp->payload[23] = _Iwheels;
}

static inline void REM_RobotPIDGains_set_Dwheels(REM_RobotPIDGainsPayload *remrpidgp, float Dwheels){
    uint32_t _Dwheels = (uint32_t)(Dwheels / 0.0001525902189670);
    remrpidgp->payload[24] = (_Dwheels >> 8);
    remrpidgp->payload[25] = _Dwheels;
}

// ================================ ENCODE ================================
static inline void encodeREM_RobotPIDGains(REM_RobotPIDGainsPayload *remrpidgp, REM_RobotPIDGains *remrpidg){
    REM_RobotPIDGains_set_header              (remrpidgp, remrpidg->header);
    REM_RobotPIDGains_set_remVersion          (remrpidgp, remrpidg->remVersion);
    REM_RobotPIDGains_set_id                  (remrpidgp, remrpidg->id);
    REM_RobotPIDGains_set_PbodyX              (remrpidgp, remrpidg->PbodyX);
    REM_RobotPIDGains_set_IbodyX              (remrpidgp, remrpidg->IbodyX);
    REM_RobotPIDGains_set_DbodyX              (remrpidgp, remrpidg->DbodyX);
    REM_RobotPIDGains_set_PbodyY              (remrpidgp, remrpidg->PbodyY);
    REM_RobotPIDGains_set_IbodyY              (remrpidgp, remrpidg->IbodyY);
    REM_RobotPIDGains_set_DbodyY              (remrpidgp, remrpidg->DbodyY);
    REM_RobotPIDGains_set_PbodyYaw            (remrpidgp, remrpidg->PbodyYaw);
    REM_RobotPIDGains_set_IbodyYaw            (remrpidgp, remrpidg->IbodyYaw);
    REM_RobotPIDGains_set_DbodyYaw            (remrpidgp, remrpidg->DbodyYaw);
    REM_RobotPIDGains_set_Pwheels             (remrpidgp, remrpidg->Pwheels);
    REM_RobotPIDGains_set_Iwheels             (remrpidgp, remrpidg->Iwheels);
    REM_RobotPIDGains_set_Dwheels             (remrpidgp, remrpidg->Dwheels);
}

// ================================ DECODE ================================
static inline void decodeREM_RobotPIDGains(REM_RobotPIDGains *remrpidg, REM_RobotPIDGainsPayload *remrpidgp){
    remrpidg->header     = REM_RobotPIDGains_get_header(remrpidgp);
    remrpidg->remVersion = REM_RobotPIDGains_get_remVersion(remrpidgp);
    remrpidg->id         = REM_RobotPIDGains_get_id(remrpidgp);
    remrpidg->PbodyX     = REM_RobotPIDGains_get_PbodyX(remrpidgp);
    remrpidg->IbodyX     = REM_RobotPIDGains_get_IbodyX(remrpidgp);
    remrpidg->DbodyX     = REM_RobotPIDGains_get_DbodyX(remrpidgp);
    remrpidg->PbodyY     = REM_RobotPIDGains_get_PbodyY(remrpidgp);
    remrpidg->IbodyY     = REM_RobotPIDGains_get_IbodyY(remrpidgp);
    remrpidg->DbodyY     = REM_RobotPIDGains_get_DbodyY(remrpidgp);
    remrpidg->PbodyYaw   = REM_RobotPIDGains_get_PbodyYaw(remrpidgp);
    remrpidg->IbodyYaw   = REM_RobotPIDGains_get_IbodyYaw(remrpidgp);
    remrpidg->DbodyYaw   = REM_RobotPIDGains_get_DbodyYaw(remrpidgp);
    remrpidg->Pwheels    = REM_RobotPIDGains_get_Pwheels(remrpidgp);
    remrpidg->Iwheels    = REM_RobotPIDGains_get_Iwheels(remrpidgp);
    remrpidg->Dwheels    = REM_RobotPIDGains_get_Dwheels(remrpidgp);
}

#endif /*__REM_ROBOT_PIDGAINS_H*/
