// AUTOGENERATED. Run generator/main.py to regenerate
/*
[  0   ] [  1   ] [  2   ] [  3   ] [  4   ] [  5   ] [  6   ] [  7   ] [  8   ] [  9   ]
11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- header
-------- 1111---- -------- -------- -------- -------- -------- -------- -------- -------- toRobotId
-------- ----1--- -------- -------- -------- -------- -------- -------- -------- -------- toColor
-------- -----1-- -------- -------- -------- -------- -------- -------- -------- -------- toBC
-------- ------1- -------- -------- -------- -------- -------- -------- -------- -------- toBS
-------- -------1 -------- -------- -------- -------- -------- -------- -------- -------- toPC
-------- -------- 1111---- -------- -------- -------- -------- -------- -------- -------- fromRobotId
-------- -------- ----1--- -------- -------- -------- -------- -------- -------- -------- fromColor
-------- -------- -----1-- -------- -------- -------- -------- -------- -------- -------- reserved
-------- -------- ------1- -------- -------- -------- -------- -------- -------- -------- fromBS
-------- -------- -------1 -------- -------- -------- -------- -------- -------- -------- fromPC
-------- -------- -------- 1111---- -------- -------- -------- -------- -------- -------- remVersion
-------- -------- -------- ----1111 -------- -------- -------- -------- -------- -------- messageId
-------- -------- -------- -------- 11111111 11111111 11111111 -------- -------- -------- timestamp
-------- -------- -------- -------- -------- -------- -------- 11111111 -------- -------- payloadSize
-------- -------- -------- -------- -------- -------- -------- -------- 11111111 -------- sequenceNumber
-------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 messageLength
*/

#ifndef __REM_ROBOT_ASSURED_PACKET_H
#define __REM_ROBOT_ASSURED_PACKET_H

#include <stdbool.h>
#include <stdint.h>

#include "REM_BaseTypes.h"

typedef struct _REM_RobotAssuredPacketPayload {
    uint8_t payload[REM_PACKET_SIZE_REM_ROBOT_ASSURED_PACKET];
} REM_RobotAssuredPacketPayload;

typedef struct _REM_RobotAssuredPacket {
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
    uint32_t sequenceNumber;  // integer [0, 255]             Number to match this packet with AssuredAck
    uint32_t messageLength;   // integer [0, 255]             Length of the following message
} REM_RobotAssuredPacket;

// ================================ GETTERS ================================
static inline uint32_t REM_RobotAssuredPacket_get_header(REM_RobotAssuredPacketPayload *remrapp) { return ((remrapp->payload[0])); }

static inline uint32_t REM_RobotAssuredPacket_get_toRobotId(REM_RobotAssuredPacketPayload *remrapp) { return ((remrapp->payload[1] & 0b11110000) >> 4); }

static inline bool REM_RobotAssuredPacket_get_toColor(REM_RobotAssuredPacketPayload *remrapp) { return (remrapp->payload[1] & 0b00001000) > 0; }

static inline bool REM_RobotAssuredPacket_get_toBC(REM_RobotAssuredPacketPayload *remrapp) { return (remrapp->payload[1] & 0b00000100) > 0; }

static inline bool REM_RobotAssuredPacket_get_toBS(REM_RobotAssuredPacketPayload *remrapp) { return (remrapp->payload[1] & 0b00000010) > 0; }

static inline bool REM_RobotAssuredPacket_get_toPC(REM_RobotAssuredPacketPayload *remrapp) { return (remrapp->payload[1] & 0b00000001) > 0; }

static inline uint32_t REM_RobotAssuredPacket_get_fromRobotId(REM_RobotAssuredPacketPayload *remrapp) { return ((remrapp->payload[2] & 0b11110000) >> 4); }

static inline bool REM_RobotAssuredPacket_get_fromColor(REM_RobotAssuredPacketPayload *remrapp) { return (remrapp->payload[2] & 0b00001000) > 0; }

static inline bool REM_RobotAssuredPacket_get_reserved(REM_RobotAssuredPacketPayload *remrapp) { return (remrapp->payload[2] & 0b00000100) > 0; }

static inline bool REM_RobotAssuredPacket_get_fromBS(REM_RobotAssuredPacketPayload *remrapp) { return (remrapp->payload[2] & 0b00000010) > 0; }

static inline bool REM_RobotAssuredPacket_get_fromPC(REM_RobotAssuredPacketPayload *remrapp) { return (remrapp->payload[2] & 0b00000001) > 0; }

static inline uint32_t REM_RobotAssuredPacket_get_remVersion(REM_RobotAssuredPacketPayload *remrapp) { return ((remrapp->payload[3] & 0b11110000) >> 4); }

static inline uint32_t REM_RobotAssuredPacket_get_messageId(REM_RobotAssuredPacketPayload *remrapp) { return ((remrapp->payload[3] & 0b00001111)); }

static inline uint32_t REM_RobotAssuredPacket_get_timestamp(REM_RobotAssuredPacketPayload *remrapp) {
    return ((remrapp->payload[4]) << 16) | ((remrapp->payload[5]) << 8) | ((remrapp->payload[6]));
}

static inline uint32_t REM_RobotAssuredPacket_get_payloadSize(REM_RobotAssuredPacketPayload *remrapp) { return ((remrapp->payload[7])); }

static inline uint32_t REM_RobotAssuredPacket_get_sequenceNumber(REM_RobotAssuredPacketPayload *remrapp) { return ((remrapp->payload[8])); }

static inline uint32_t REM_RobotAssuredPacket_get_messageLength(REM_RobotAssuredPacketPayload *remrapp) { return ((remrapp->payload[9])); }

// ================================ SETTERS ================================
static inline void REM_RobotAssuredPacket_set_header(REM_RobotAssuredPacketPayload *remrapp, uint32_t header) { remrapp->payload[0] = header; }

static inline void REM_RobotAssuredPacket_set_toRobotId(REM_RobotAssuredPacketPayload *remrapp, uint32_t toRobotId) {
    remrapp->payload[1] = ((toRobotId << 4) & 0b11110000) | (remrapp->payload[1] & 0b00001111);
}

static inline void REM_RobotAssuredPacket_set_toColor(REM_RobotAssuredPacketPayload *remrapp, bool toColor) {
    remrapp->payload[1] = ((toColor << 3) & 0b00001000) | (remrapp->payload[1] & 0b11110111);
}

static inline void REM_RobotAssuredPacket_set_toBC(REM_RobotAssuredPacketPayload *remrapp, bool toBC) {
    remrapp->payload[1] = ((toBC << 2) & 0b00000100) | (remrapp->payload[1] & 0b11111011);
}

static inline void REM_RobotAssuredPacket_set_toBS(REM_RobotAssuredPacketPayload *remrapp, bool toBS) {
    remrapp->payload[1] = ((toBS << 1) & 0b00000010) | (remrapp->payload[1] & 0b11111101);
}

static inline void REM_RobotAssuredPacket_set_toPC(REM_RobotAssuredPacketPayload *remrapp, bool toPC) {
    remrapp->payload[1] = (toPC & 0b00000001) | (remrapp->payload[1] & 0b11111110);
}

static inline void REM_RobotAssuredPacket_set_fromRobotId(REM_RobotAssuredPacketPayload *remrapp, uint32_t fromRobotId) {
    remrapp->payload[2] = ((fromRobotId << 4) & 0b11110000) | (remrapp->payload[2] & 0b00001111);
}

static inline void REM_RobotAssuredPacket_set_fromColor(REM_RobotAssuredPacketPayload *remrapp, bool fromColor) {
    remrapp->payload[2] = ((fromColor << 3) & 0b00001000) | (remrapp->payload[2] & 0b11110111);
}

static inline void REM_RobotAssuredPacket_set_reserved(REM_RobotAssuredPacketPayload *remrapp, bool reserved) {
    remrapp->payload[2] = ((reserved << 2) & 0b00000100) | (remrapp->payload[2] & 0b11111011);
}

static inline void REM_RobotAssuredPacket_set_fromBS(REM_RobotAssuredPacketPayload *remrapp, bool fromBS) {
    remrapp->payload[2] = ((fromBS << 1) & 0b00000010) | (remrapp->payload[2] & 0b11111101);
}

static inline void REM_RobotAssuredPacket_set_fromPC(REM_RobotAssuredPacketPayload *remrapp, bool fromPC) {
    remrapp->payload[2] = (fromPC & 0b00000001) | (remrapp->payload[2] & 0b11111110);
}

static inline void REM_RobotAssuredPacket_set_remVersion(REM_RobotAssuredPacketPayload *remrapp, uint32_t remVersion) {
    remrapp->payload[3] = ((remVersion << 4) & 0b11110000) | (remrapp->payload[3] & 0b00001111);
}

static inline void REM_RobotAssuredPacket_set_messageId(REM_RobotAssuredPacketPayload *remrapp, uint32_t messageId) {
    remrapp->payload[3] = (messageId & 0b00001111) | (remrapp->payload[3] & 0b11110000);
}

static inline void REM_RobotAssuredPacket_set_timestamp(REM_RobotAssuredPacketPayload *remrapp, uint32_t timestamp) {
    remrapp->payload[4] = (timestamp >> 16);
    remrapp->payload[5] = (timestamp >> 8);
    remrapp->payload[6] = timestamp;
}

static inline void REM_RobotAssuredPacket_set_payloadSize(REM_RobotAssuredPacketPayload *remrapp, uint32_t payloadSize) { remrapp->payload[7] = payloadSize; }

static inline void REM_RobotAssuredPacket_set_sequenceNumber(REM_RobotAssuredPacketPayload *remrapp, uint32_t sequenceNumber) { remrapp->payload[8] = sequenceNumber; }

static inline void REM_RobotAssuredPacket_set_messageLength(REM_RobotAssuredPacketPayload *remrapp, uint32_t messageLength) { remrapp->payload[9] = messageLength; }

// ================================ ENCODE ================================
static inline void encodeREM_RobotAssuredPacket(REM_RobotAssuredPacketPayload *remrapp, REM_RobotAssuredPacket *remrap) {
    REM_RobotAssuredPacket_set_header(remrapp, remrap->header);
    REM_RobotAssuredPacket_set_toRobotId(remrapp, remrap->toRobotId);
    REM_RobotAssuredPacket_set_toColor(remrapp, remrap->toColor);
    REM_RobotAssuredPacket_set_toBC(remrapp, remrap->toBC);
    REM_RobotAssuredPacket_set_toBS(remrapp, remrap->toBS);
    REM_RobotAssuredPacket_set_toPC(remrapp, remrap->toPC);
    REM_RobotAssuredPacket_set_fromRobotId(remrapp, remrap->fromRobotId);
    REM_RobotAssuredPacket_set_fromColor(remrapp, remrap->fromColor);
    REM_RobotAssuredPacket_set_reserved(remrapp, remrap->reserved);
    REM_RobotAssuredPacket_set_fromBS(remrapp, remrap->fromBS);
    REM_RobotAssuredPacket_set_fromPC(remrapp, remrap->fromPC);
    REM_RobotAssuredPacket_set_remVersion(remrapp, remrap->remVersion);
    REM_RobotAssuredPacket_set_messageId(remrapp, remrap->messageId);
    REM_RobotAssuredPacket_set_timestamp(remrapp, remrap->timestamp);
    REM_RobotAssuredPacket_set_payloadSize(remrapp, remrap->payloadSize);
    REM_RobotAssuredPacket_set_sequenceNumber(remrapp, remrap->sequenceNumber);
    REM_RobotAssuredPacket_set_messageLength(remrapp, remrap->messageLength);
}

// ================================ DECODE ================================
static inline void decodeREM_RobotAssuredPacket(REM_RobotAssuredPacket *remrap, REM_RobotAssuredPacketPayload *remrapp) {
    remrap->header = REM_RobotAssuredPacket_get_header(remrapp);
    remrap->toRobotId = REM_RobotAssuredPacket_get_toRobotId(remrapp);
    remrap->toColor = REM_RobotAssuredPacket_get_toColor(remrapp);
    remrap->toBC = REM_RobotAssuredPacket_get_toBC(remrapp);
    remrap->toBS = REM_RobotAssuredPacket_get_toBS(remrapp);
    remrap->toPC = REM_RobotAssuredPacket_get_toPC(remrapp);
    remrap->fromRobotId = REM_RobotAssuredPacket_get_fromRobotId(remrapp);
    remrap->fromColor = REM_RobotAssuredPacket_get_fromColor(remrapp);
    remrap->reserved = REM_RobotAssuredPacket_get_reserved(remrapp);
    remrap->fromBS = REM_RobotAssuredPacket_get_fromBS(remrapp);
    remrap->fromPC = REM_RobotAssuredPacket_get_fromPC(remrapp);
    remrap->remVersion = REM_RobotAssuredPacket_get_remVersion(remrapp);
    remrap->messageId = REM_RobotAssuredPacket_get_messageId(remrapp);
    remrap->timestamp = REM_RobotAssuredPacket_get_timestamp(remrapp);
    remrap->payloadSize = REM_RobotAssuredPacket_get_payloadSize(remrapp);
    remrap->sequenceNumber = REM_RobotAssuredPacket_get_sequenceNumber(remrapp);
    remrap->messageLength = REM_RobotAssuredPacket_get_messageLength(remrapp);
}

#endif /*__REM_ROBOT_ASSURED_PACKET_H*/
