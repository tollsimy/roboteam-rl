// AUTOGENERATED. Run generator/main.py to regenerate
/*
[  0   ] [  1   ] [  2   ] [  3   ] [  4   ] [  5   ] [  6   ] [  7   ]
11111111 -------- -------- -------- -------- -------- -------- -------- header
-------- 1111---- -------- -------- -------- -------- -------- -------- toRobotId
-------- ----1--- -------- -------- -------- -------- -------- -------- toColor
-------- -----1-- -------- -------- -------- -------- -------- -------- toBC
-------- ------1- -------- -------- -------- -------- -------- -------- toBS
-------- -------1 -------- -------- -------- -------- -------- -------- toPC
-------- -------- 1111---- -------- -------- -------- -------- -------- fromRobotId
-------- -------- ----1--- -------- -------- -------- -------- -------- fromColor
-------- -------- -----1-- -------- -------- -------- -------- -------- reserved
-------- -------- ------1- -------- -------- -------- -------- -------- fromBS
-------- -------- -------1 -------- -------- -------- -------- -------- fromPC
-------- -------- -------- 1111---- -------- -------- -------- -------- remVersion
-------- -------- -------- ----1111 -------- -------- -------- -------- messageId
-------- -------- -------- -------- 11111111 11111111 11111111 -------- timestamp
-------- -------- -------- -------- -------- -------- -------- 11111111 payloadSize
*/

#ifndef __REM_PACKET_H
#define __REM_PACKET_H

#include <stdbool.h>
#include <stdint.h>

#include "REM_BaseTypes.h"

typedef struct _REM_PacketPayload {
    uint8_t payload[REM_PACKET_SIZE_REM_PACKET];
} REM_PacketPayload;

typedef struct _REM_Packet {
    uint32_t header;       // integer [0, 255]             Header byte indicating the type of packet
    uint32_t toRobotId;    // integer [0, 15]              Id of the receiving robot
    bool toColor;          // integer [0, 1]               Color of the receiving robot / basestation. Yellow = 0, Blue = 1
    bool toBC;             // integer [0, 1]               Bit indicating this packet has to be broadcasted to all robots
    bool toBS;             // integer [0, 1]               Bit indicating this packet is meant for the basestation
    bool toPC;             // integer [0, 1]               Bit indicating this packet is meant for the PC
    uint32_t fromRobotId;  // integer [0, 15]              Id of the transmitting robot
    bool fromColor;        // integer [0, 1]               Color of the transmitting robot / basestation. Yellow = 0, Blue = 1
    bool reserved;         // integer [0, 1]               reserved
    bool fromBS;           // integer [0, 1]               Bit indicating this packet is coming from the basestation
    bool fromPC;           // integer [0, 1]               Bit indicating this packet is coming from the PC
    uint32_t remVersion;   // integer [0, 15]              Version of roboteam_embedded_messages
    uint32_t messageId;    // integer [0, 15]              messageId. Can be used for aligning packets
    uint32_t timestamp;    // integer [0, 16777215]        Timestamp in milliseconds
    uint32_t payloadSize;  // integer [0, 255]             Size of the payload. At most 255 bytes including the generic_packet_header. Keep the 127 byte SX1280 limit in mind
} REM_Packet;

// ================================ GETTERS ================================
static inline uint32_t REM_Packet_get_header(REM_PacketPayload *rempp) { return ((rempp->payload[0])); }

static inline uint32_t REM_Packet_get_toRobotId(REM_PacketPayload *rempp) { return ((rempp->payload[1] & 0b11110000) >> 4); }

static inline bool REM_Packet_get_toColor(REM_PacketPayload *rempp) { return (rempp->payload[1] & 0b00001000) > 0; }

static inline bool REM_Packet_get_toBC(REM_PacketPayload *rempp) { return (rempp->payload[1] & 0b00000100) > 0; }

static inline bool REM_Packet_get_toBS(REM_PacketPayload *rempp) { return (rempp->payload[1] & 0b00000010) > 0; }

static inline bool REM_Packet_get_toPC(REM_PacketPayload *rempp) { return (rempp->payload[1] & 0b00000001) > 0; }

static inline uint32_t REM_Packet_get_fromRobotId(REM_PacketPayload *rempp) { return ((rempp->payload[2] & 0b11110000) >> 4); }

static inline bool REM_Packet_get_fromColor(REM_PacketPayload *rempp) { return (rempp->payload[2] & 0b00001000) > 0; }

static inline bool REM_Packet_get_reserved(REM_PacketPayload *rempp) { return (rempp->payload[2] & 0b00000100) > 0; }

static inline bool REM_Packet_get_fromBS(REM_PacketPayload *rempp) { return (rempp->payload[2] & 0b00000010) > 0; }

static inline bool REM_Packet_get_fromPC(REM_PacketPayload *rempp) { return (rempp->payload[2] & 0b00000001) > 0; }

static inline uint32_t REM_Packet_get_remVersion(REM_PacketPayload *rempp) { return ((rempp->payload[3] & 0b11110000) >> 4); }

static inline uint32_t REM_Packet_get_messageId(REM_PacketPayload *rempp) { return ((rempp->payload[3] & 0b00001111)); }

static inline uint32_t REM_Packet_get_timestamp(REM_PacketPayload *rempp) { return ((rempp->payload[4]) << 16) | ((rempp->payload[5]) << 8) | ((rempp->payload[6])); }

static inline uint32_t REM_Packet_get_payloadSize(REM_PacketPayload *rempp) { return ((rempp->payload[7])); }

// ================================ SETTERS ================================
static inline void REM_Packet_set_header(REM_PacketPayload *rempp, uint32_t header) { rempp->payload[0] = header; }

static inline void REM_Packet_set_toRobotId(REM_PacketPayload *rempp, uint32_t toRobotId) {
    rempp->payload[1] = ((toRobotId << 4) & 0b11110000) | (rempp->payload[1] & 0b00001111);
}

static inline void REM_Packet_set_toColor(REM_PacketPayload *rempp, bool toColor) { rempp->payload[1] = ((toColor << 3) & 0b00001000) | (rempp->payload[1] & 0b11110111); }

static inline void REM_Packet_set_toBC(REM_PacketPayload *rempp, bool toBC) { rempp->payload[1] = ((toBC << 2) & 0b00000100) | (rempp->payload[1] & 0b11111011); }

static inline void REM_Packet_set_toBS(REM_PacketPayload *rempp, bool toBS) { rempp->payload[1] = ((toBS << 1) & 0b00000010) | (rempp->payload[1] & 0b11111101); }

static inline void REM_Packet_set_toPC(REM_PacketPayload *rempp, bool toPC) { rempp->payload[1] = (toPC & 0b00000001) | (rempp->payload[1] & 0b11111110); }

static inline void REM_Packet_set_fromRobotId(REM_PacketPayload *rempp, uint32_t fromRobotId) {
    rempp->payload[2] = ((fromRobotId << 4) & 0b11110000) | (rempp->payload[2] & 0b00001111);
}

static inline void REM_Packet_set_fromColor(REM_PacketPayload *rempp, bool fromColor) { rempp->payload[2] = ((fromColor << 3) & 0b00001000) | (rempp->payload[2] & 0b11110111); }

static inline void REM_Packet_set_reserved(REM_PacketPayload *rempp, bool reserved) { rempp->payload[2] = ((reserved << 2) & 0b00000100) | (rempp->payload[2] & 0b11111011); }

static inline void REM_Packet_set_fromBS(REM_PacketPayload *rempp, bool fromBS) { rempp->payload[2] = ((fromBS << 1) & 0b00000010) | (rempp->payload[2] & 0b11111101); }

static inline void REM_Packet_set_fromPC(REM_PacketPayload *rempp, bool fromPC) { rempp->payload[2] = (fromPC & 0b00000001) | (rempp->payload[2] & 0b11111110); }

static inline void REM_Packet_set_remVersion(REM_PacketPayload *rempp, uint32_t remVersion) {
    rempp->payload[3] = ((remVersion << 4) & 0b11110000) | (rempp->payload[3] & 0b00001111);
}

static inline void REM_Packet_set_messageId(REM_PacketPayload *rempp, uint32_t messageId) { rempp->payload[3] = (messageId & 0b00001111) | (rempp->payload[3] & 0b11110000); }

static inline void REM_Packet_set_timestamp(REM_PacketPayload *rempp, uint32_t timestamp) {
    rempp->payload[4] = (timestamp >> 16);
    rempp->payload[5] = (timestamp >> 8);
    rempp->payload[6] = timestamp;
}

static inline void REM_Packet_set_payloadSize(REM_PacketPayload *rempp, uint32_t payloadSize) { rempp->payload[7] = payloadSize; }

// ================================ ENCODE ================================
static inline void encodeREM_Packet(REM_PacketPayload *rempp, REM_Packet *remp) {
    REM_Packet_set_header(rempp, remp->header);
    REM_Packet_set_toRobotId(rempp, remp->toRobotId);
    REM_Packet_set_toColor(rempp, remp->toColor);
    REM_Packet_set_toBC(rempp, remp->toBC);
    REM_Packet_set_toBS(rempp, remp->toBS);
    REM_Packet_set_toPC(rempp, remp->toPC);
    REM_Packet_set_fromRobotId(rempp, remp->fromRobotId);
    REM_Packet_set_fromColor(rempp, remp->fromColor);
    REM_Packet_set_reserved(rempp, remp->reserved);
    REM_Packet_set_fromBS(rempp, remp->fromBS);
    REM_Packet_set_fromPC(rempp, remp->fromPC);
    REM_Packet_set_remVersion(rempp, remp->remVersion);
    REM_Packet_set_messageId(rempp, remp->messageId);
    REM_Packet_set_timestamp(rempp, remp->timestamp);
    REM_Packet_set_payloadSize(rempp, remp->payloadSize);
}

// ================================ DECODE ================================
static inline void decodeREM_Packet(REM_Packet *remp, REM_PacketPayload *rempp) {
    remp->header = REM_Packet_get_header(rempp);
    remp->toRobotId = REM_Packet_get_toRobotId(rempp);
    remp->toColor = REM_Packet_get_toColor(rempp);
    remp->toBC = REM_Packet_get_toBC(rempp);
    remp->toBS = REM_Packet_get_toBS(rempp);
    remp->toPC = REM_Packet_get_toPC(rempp);
    remp->fromRobotId = REM_Packet_get_fromRobotId(rempp);
    remp->fromColor = REM_Packet_get_fromColor(rempp);
    remp->reserved = REM_Packet_get_reserved(rempp);
    remp->fromBS = REM_Packet_get_fromBS(rempp);
    remp->fromPC = REM_Packet_get_fromPC(rempp);
    remp->remVersion = REM_Packet_get_remVersion(rempp);
    remp->messageId = REM_Packet_get_messageId(rempp);
    remp->timestamp = REM_Packet_get_timestamp(rempp);
    remp->payloadSize = REM_Packet_get_payloadSize(rempp);
}

#endif /*__REM_PACKET_H*/
