// AUTOGENERATED. Run generator/main.py to regenerate
// Generated on July 04 2021, 22:47:52

/*
[  0   ]
11111111 header
*/

#ifndef __BASESTATION_LOG_H
#define __BASESTATION_LOG_H

#include <stdbool.h>
#include <stdint.h>
#include "BaseTypes.h"

typedef struct _BasestationLogPayload {
    uint8_t payload[PACKET_SIZE_BASESTATION_LOG];
} BasestationLogPayload;

typedef struct _BasestationLog {
    uint32_t   header              ; // Header byte indicating the type of packet
} BasestationLog;

// ================================ GETTERS ================================
static inline uint32_t BasestationLog_get_header(BasestationLogPayload *blp){
    return ((blp->payload[0]));
}

// ================================ SETTERS ================================
static inline void BasestationLog_set_header(BasestationLogPayload *blp, uint32_t header){
    blp->payload[0] = header;
}

// ================================ ENCODE ================================
static inline void encodeBasestationLog(BasestationLogPayload *blp, BasestationLog *bl){
    BasestationLog_set_header              (blp, bl->header);
}

// ================================ DECODE ================================
static inline void decodeBasestationLog(BasestationLog *bl, BasestationLogPayload *blp){
    bl->header           = BasestationLog_get_header(blp);
}

#endif /*__BASESTATION_LOG_H*/
