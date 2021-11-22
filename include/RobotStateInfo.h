// AUTOGENERATED. Run generator/main.py to regenerate
/*
[  0   ] [  1   ] [  2   ] [  3   ] [  4   ] [  5   ] [  6   ] [  7   ] [  8   ] [  9   ] [  10  ] [  11  ] [  12  ] [  13  ] [  14  ] [  15  ] [  16  ] [  17  ] [  18  ] [  19  ] [  20  ] [  21  ] [  22  ] [  23  ] [  24  ] [  25  ] [  26  ] [  27  ] [  28  ] [  29  ] [  30  ] [  31  ] [  32  ] [  33  ] [  34  ]
11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- header
-------- 1111---- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- remVersion
-------- ----1111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- id
-------- -------- 1111---- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- messageId
-------- -------- ----1111 11111111 11111111 11111111 1111---- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- xsensAcc1
-------- -------- -------- -------- -------- -------- ----1111 11111111 11111111 11111111 1111---- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- xsensAcc2
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- ----1111 11111111 11111111 11111111 1111---- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- xsensYaw
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- ----1111 11111111 11111111 11111111 1111---- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- rateOfTurn
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- ----1111 11111111 11111111 11111111 1111---- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- wheelSpeed1
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- ----1111 11111111 11111111 11111111 1111---- -------- -------- -------- -------- -------- -------- -------- -------- wheelSpeed2
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- ----1111 11111111 11111111 11111111 1111---- -------- -------- -------- -------- wheelSpeed3
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- ----1111 11111111 11111111 11111111 1111---- wheelSpeed4
*/

#ifndef __ROBOT_STATE_INFO_H
#define __ROBOT_STATE_INFO_H

#include <stdbool.h>
#include <stdint.h>
#include "BaseTypes.h"

typedef struct _RobotStateInfoPayload {
    uint8_t payload[PACKET_SIZE_ROBOT_STATE_INFO];
} RobotStateInfoPayload;

typedef struct _RobotStateInfo {
    uint32_t   header              ; // integer [0, 255]             Header byte indicating the type of packet
    uint32_t   remVersion          ; // integer [0, 15]              Version of roboteam_embedded_messages
    uint32_t   id                  ; // integer [0, 15]              Id of the robot 
    uint32_t   messageId           ; // integer [0, 15]              Id of the message
    float      xsensAcc1           ; // float   [-50000.000, 50000.000] xsensAcc1
    float      xsensAcc2           ; // float   [-50000.000, 50000.000] xsensAcc2
    float      xsensYaw            ; // float   [-50000.000, 50000.000] xsensYaw
    float      rateOfTurn          ; // float   [-50000.000, 50000.000] rateOfTurn
    float      wheelSpeed1         ; // float   [-50000.000, 50000.000] wheelSpeed1
    float      wheelSpeed2         ; // float   [-50000.000, 50000.000] wheelSpeed2
    float      wheelSpeed3         ; // float   [-50000.000, 50000.000] wheelSpeed3
    float      wheelSpeed4         ; // float   [-50000.000, 50000.000] wheelSpeed4
} RobotStateInfo;

// ================================ GETTERS ================================
static inline uint32_t RobotStateInfo_get_header(RobotStateInfoPayload *rsip){
    return ((rsip->payload[0]));
}

static inline uint32_t RobotStateInfo_get_remVersion(RobotStateInfoPayload *rsip){
    return ((rsip->payload[1] & 0b11110000) >> 4);
}

static inline uint32_t RobotStateInfo_get_id(RobotStateInfoPayload *rsip){
    return ((rsip->payload[1] & 0b00001111));
}

static inline uint32_t RobotStateInfo_get_messageId(RobotStateInfoPayload *rsip){
    return ((rsip->payload[2] & 0b11110000) >> 4);
}

static inline float RobotStateInfo_get_xsensAcc1(RobotStateInfoPayload *rsip){
    uint32_t _xsensAcc1 = ((rsip->payload[2] & 0b00001111) << 28) | ((rsip->payload[3]) << 20) | ((rsip->payload[4]) << 12) | ((rsip->payload[5]) << 4) | ((rsip->payload[6] & 0b11110000) >> 4);
    return (_xsensAcc1 * 0.0000232830643708) + -50000.0000000000000000;
}

static inline float RobotStateInfo_get_xsensAcc2(RobotStateInfoPayload *rsip){
    uint32_t _xsensAcc2 = ((rsip->payload[6] & 0b00001111) << 28) | ((rsip->payload[7]) << 20) | ((rsip->payload[8]) << 12) | ((rsip->payload[9]) << 4) | ((rsip->payload[10] & 0b11110000) >> 4);
    return (_xsensAcc2 * 0.0000232830643708) + -50000.0000000000000000;
}

static inline float RobotStateInfo_get_xsensYaw(RobotStateInfoPayload *rsip){
    uint32_t _xsensYaw = ((rsip->payload[10] & 0b00001111) << 28) | ((rsip->payload[11]) << 20) | ((rsip->payload[12]) << 12) | ((rsip->payload[13]) << 4) | ((rsip->payload[14] & 0b11110000) >> 4);
    return (_xsensYaw * 0.0000232830643708) + -50000.0000000000000000;
}

static inline float RobotStateInfo_get_rateOfTurn(RobotStateInfoPayload *rsip){
    uint32_t _rateOfTurn = ((rsip->payload[14] & 0b00001111) << 28) | ((rsip->payload[15]) << 20) | ((rsip->payload[16]) << 12) | ((rsip->payload[17]) << 4) | ((rsip->payload[18] & 0b11110000) >> 4);
    return (_rateOfTurn * 0.0000232830643708) + -50000.0000000000000000;
}

static inline float RobotStateInfo_get_wheelSpeed1(RobotStateInfoPayload *rsip){
    uint32_t _wheelSpeed1 = ((rsip->payload[18] & 0b00001111) << 28) | ((rsip->payload[19]) << 20) | ((rsip->payload[20]) << 12) | ((rsip->payload[21]) << 4) | ((rsip->payload[22] & 0b11110000) >> 4);
    return (_wheelSpeed1 * 0.0000232830643708) + -50000.0000000000000000;
}

static inline float RobotStateInfo_get_wheelSpeed2(RobotStateInfoPayload *rsip){
    uint32_t _wheelSpeed2 = ((rsip->payload[22] & 0b00001111) << 28) | ((rsip->payload[23]) << 20) | ((rsip->payload[24]) << 12) | ((rsip->payload[25]) << 4) | ((rsip->payload[26] & 0b11110000) >> 4);
    return (_wheelSpeed2 * 0.0000232830643708) + -50000.0000000000000000;
}

static inline float RobotStateInfo_get_wheelSpeed3(RobotStateInfoPayload *rsip){
    uint32_t _wheelSpeed3 = ((rsip->payload[26] & 0b00001111) << 28) | ((rsip->payload[27]) << 20) | ((rsip->payload[28]) << 12) | ((rsip->payload[29]) << 4) | ((rsip->payload[30] & 0b11110000) >> 4);
    return (_wheelSpeed3 * 0.0000232830643708) + -50000.0000000000000000;
}

static inline float RobotStateInfo_get_wheelSpeed4(RobotStateInfoPayload *rsip){
    uint32_t _wheelSpeed4 = ((rsip->payload[30] & 0b00001111) << 28) | ((rsip->payload[31]) << 20) | ((rsip->payload[32]) << 12) | ((rsip->payload[33]) << 4) | ((rsip->payload[34] & 0b11110000) >> 4);
    return (_wheelSpeed4 * 0.0000232830643708) + -50000.0000000000000000;
}

// ================================ SETTERS ================================
static inline void RobotStateInfo_set_header(RobotStateInfoPayload *rsip, uint32_t header){
    rsip->payload[0] = header;
}

static inline void RobotStateInfo_set_remVersion(RobotStateInfoPayload *rsip, uint32_t remVersion){
    rsip->payload[1] = ((remVersion << 4) & 0b11110000) | (rsip->payload[1] & 0b00001111);
}

static inline void RobotStateInfo_set_id(RobotStateInfoPayload *rsip, uint32_t id){
    rsip->payload[1] = (id & 0b00001111) | (rsip->payload[1] & 0b11110000);
}

static inline void RobotStateInfo_set_messageId(RobotStateInfoPayload *rsip, uint32_t messageId){
    rsip->payload[2] = ((messageId << 4) & 0b11110000) | (rsip->payload[2] & 0b00001111);
}

static inline void RobotStateInfo_set_xsensAcc1(RobotStateInfoPayload *rsip, float xsensAcc1){
    uint32_t _xsensAcc1 = (uint32_t)((xsensAcc1 +50000.0000000000000000) / 0.0000232830643708);
    rsip->payload[2] = ((_xsensAcc1 >> 28) & 0b00001111) | (rsip->payload[2] & 0b11110000);
    rsip->payload[3] = (_xsensAcc1 >> 20);
    rsip->payload[4] = (_xsensAcc1 >> 12);
    rsip->payload[5] = (_xsensAcc1 >> 4);
    rsip->payload[6] = ((_xsensAcc1 << 4) & 0b11110000) | (rsip->payload[6] & 0b00001111);
}

static inline void RobotStateInfo_set_xsensAcc2(RobotStateInfoPayload *rsip, float xsensAcc2){
    uint32_t _xsensAcc2 = (uint32_t)((xsensAcc2 +50000.0000000000000000) / 0.0000232830643708);
    rsip->payload[6] = ((_xsensAcc2 >> 28) & 0b00001111) | (rsip->payload[6] & 0b11110000);
    rsip->payload[7] = (_xsensAcc2 >> 20);
    rsip->payload[8] = (_xsensAcc2 >> 12);
    rsip->payload[9] = (_xsensAcc2 >> 4);
    rsip->payload[10] = ((_xsensAcc2 << 4) & 0b11110000) | (rsip->payload[10] & 0b00001111);
}

static inline void RobotStateInfo_set_xsensYaw(RobotStateInfoPayload *rsip, float xsensYaw){
    uint32_t _xsensYaw = (uint32_t)((xsensYaw +50000.0000000000000000) / 0.0000232830643708);
    rsip->payload[10] = ((_xsensYaw >> 28) & 0b00001111) | (rsip->payload[10] & 0b11110000);
    rsip->payload[11] = (_xsensYaw >> 20);
    rsip->payload[12] = (_xsensYaw >> 12);
    rsip->payload[13] = (_xsensYaw >> 4);
    rsip->payload[14] = ((_xsensYaw << 4) & 0b11110000) | (rsip->payload[14] & 0b00001111);
}

static inline void RobotStateInfo_set_rateOfTurn(RobotStateInfoPayload *rsip, float rateOfTurn){
    uint32_t _rateOfTurn = (uint32_t)((rateOfTurn +50000.0000000000000000) / 0.0000232830643708);
    rsip->payload[14] = ((_rateOfTurn >> 28) & 0b00001111) | (rsip->payload[14] & 0b11110000);
    rsip->payload[15] = (_rateOfTurn >> 20);
    rsip->payload[16] = (_rateOfTurn >> 12);
    rsip->payload[17] = (_rateOfTurn >> 4);
    rsip->payload[18] = ((_rateOfTurn << 4) & 0b11110000) | (rsip->payload[18] & 0b00001111);
}

static inline void RobotStateInfo_set_wheelSpeed1(RobotStateInfoPayload *rsip, float wheelSpeed1){
    uint32_t _wheelSpeed1 = (uint32_t)((wheelSpeed1 +50000.0000000000000000) / 0.0000232830643708);
    rsip->payload[18] = ((_wheelSpeed1 >> 28) & 0b00001111) | (rsip->payload[18] & 0b11110000);
    rsip->payload[19] = (_wheelSpeed1 >> 20);
    rsip->payload[20] = (_wheelSpeed1 >> 12);
    rsip->payload[21] = (_wheelSpeed1 >> 4);
    rsip->payload[22] = ((_wheelSpeed1 << 4) & 0b11110000) | (rsip->payload[22] & 0b00001111);
}

static inline void RobotStateInfo_set_wheelSpeed2(RobotStateInfoPayload *rsip, float wheelSpeed2){
    uint32_t _wheelSpeed2 = (uint32_t)((wheelSpeed2 +50000.0000000000000000) / 0.0000232830643708);
    rsip->payload[22] = ((_wheelSpeed2 >> 28) & 0b00001111) | (rsip->payload[22] & 0b11110000);
    rsip->payload[23] = (_wheelSpeed2 >> 20);
    rsip->payload[24] = (_wheelSpeed2 >> 12);
    rsip->payload[25] = (_wheelSpeed2 >> 4);
    rsip->payload[26] = ((_wheelSpeed2 << 4) & 0b11110000) | (rsip->payload[26] & 0b00001111);
}

static inline void RobotStateInfo_set_wheelSpeed3(RobotStateInfoPayload *rsip, float wheelSpeed3){
    uint32_t _wheelSpeed3 = (uint32_t)((wheelSpeed3 +50000.0000000000000000) / 0.0000232830643708);
    rsip->payload[26] = ((_wheelSpeed3 >> 28) & 0b00001111) | (rsip->payload[26] & 0b11110000);
    rsip->payload[27] = (_wheelSpeed3 >> 20);
    rsip->payload[28] = (_wheelSpeed3 >> 12);
    rsip->payload[29] = (_wheelSpeed3 >> 4);
    rsip->payload[30] = ((_wheelSpeed3 << 4) & 0b11110000) | (rsip->payload[30] & 0b00001111);
}

static inline void RobotStateInfo_set_wheelSpeed4(RobotStateInfoPayload *rsip, float wheelSpeed4){
    uint32_t _wheelSpeed4 = (uint32_t)((wheelSpeed4 +50000.0000000000000000) / 0.0000232830643708);
    rsip->payload[30] = ((_wheelSpeed4 >> 28) & 0b00001111) | (rsip->payload[30] & 0b11110000);
    rsip->payload[31] = (_wheelSpeed4 >> 20);
    rsip->payload[32] = (_wheelSpeed4 >> 12);
    rsip->payload[33] = (_wheelSpeed4 >> 4);
    rsip->payload[34] = ((_wheelSpeed4 << 4) & 0b11110000) | (rsip->payload[34] & 0b00001111);
}

// ================================ ENCODE ================================
static inline void encodeRobotStateInfo(RobotStateInfoPayload *rsip, RobotStateInfo *rsi){
    RobotStateInfo_set_header              (rsip, rsi->header);
    RobotStateInfo_set_remVersion          (rsip, rsi->remVersion);
    RobotStateInfo_set_id                  (rsip, rsi->id);
    RobotStateInfo_set_messageId           (rsip, rsi->messageId);
    RobotStateInfo_set_xsensAcc1           (rsip, rsi->xsensAcc1);
    RobotStateInfo_set_xsensAcc2           (rsip, rsi->xsensAcc2);
    RobotStateInfo_set_xsensYaw            (rsip, rsi->xsensYaw);
    RobotStateInfo_set_rateOfTurn          (rsip, rsi->rateOfTurn);
    RobotStateInfo_set_wheelSpeed1         (rsip, rsi->wheelSpeed1);
    RobotStateInfo_set_wheelSpeed2         (rsip, rsi->wheelSpeed2);
    RobotStateInfo_set_wheelSpeed3         (rsip, rsi->wheelSpeed3);
    RobotStateInfo_set_wheelSpeed4         (rsip, rsi->wheelSpeed4);
}

// ================================ DECODE ================================
static inline void decodeRobotStateInfo(RobotStateInfo *rsi, RobotStateInfoPayload *rsip){
    rsi->header          = RobotStateInfo_get_header(rsip);
    rsi->remVersion      = RobotStateInfo_get_remVersion(rsip);
    rsi->id              = RobotStateInfo_get_id(rsip);
    rsi->messageId       = RobotStateInfo_get_messageId(rsip);
    rsi->xsensAcc1       = RobotStateInfo_get_xsensAcc1(rsip);
    rsi->xsensAcc2       = RobotStateInfo_get_xsensAcc2(rsip);
    rsi->xsensYaw        = RobotStateInfo_get_xsensYaw(rsip);
    rsi->rateOfTurn      = RobotStateInfo_get_rateOfTurn(rsip);
    rsi->wheelSpeed1     = RobotStateInfo_get_wheelSpeed1(rsip);
    rsi->wheelSpeed2     = RobotStateInfo_get_wheelSpeed2(rsip);
    rsi->wheelSpeed3     = RobotStateInfo_get_wheelSpeed3(rsip);
    rsi->wheelSpeed4     = RobotStateInfo_get_wheelSpeed4(rsip);
}

#endif /*__ROBOT_STATE_INFO_H*/
