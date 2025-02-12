#ifndef _OS_MESSAGE_H_
#define _OS_MESSAGE_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "ultratypes.h"
#include "os_thread.h"

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

typedef u32 OSEvent;

/*
 * Structure for message
 */
typedef void *OSMesg;

/*
 * Structure for message queue
 */
typedef struct OSMesgQueue_s {
    OSThread    *mtqueue;       /* Queue to store threads blocked on empty mailboxes (receive) */
    OSThread    *fullqueue;     /* Queue to store threads blocked on full mailboxes (send) */
    s32          validCount;    /* Contains number of valid message */
    s32          first;         /* Points to first valid message */
    s32          msgCount;      /* Contains total # of messages */
    OSMesg      *msg;           /* Points to message buffer array */
} OSMesgQueue;

#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/* Events */
#ifdef _FINALROM
#define OS_NUM_EVENTS           15
#else
#define OS_NUM_EVENTS           23
#endif

#define OS_EVENT_SW1              0     /* CPU SW1 interrupt */
#define OS_EVENT_SW2              1     /* CPU SW2 interrupt */
#define OS_EVENT_CART             2     /* Cartridge interrupt: used by rmon */
#define OS_EVENT_COUNTER          3     /* Counter int: used by VI/Timer Mgr */
#define OS_EVENT_SP               4     /* SP task done interrupt */
#define OS_EVENT_SI               5     /* SI (controller) interrupt */
#define OS_EVENT_AI               6     /* AI interrupt */
#define OS_EVENT_VI               7     /* VI interrupt: used by VI/Timer Mgr */
#define OS_EVENT_PI               8     /* PI interrupt: used by PI Manager */
#define OS_EVENT_DP               9     /* DP full sync interrupt */
#define OS_EVENT_CPU_BREAK        10    /* CPU breakpoint: used by rmon */
#define OS_EVENT_SP_BREAK         11    /* SP breakpoint:  used by rmon */
#define OS_EVENT_FAULT            12    /* CPU fault event: used by rmon */
#define OS_EVENT_THREADSTATUS     13    /* CPU thread status: used by rmon */
#define OS_EVENT_PRENMI           14    /* Pre NMI interrupt */
#ifndef _FINALROM
#define OS_EVENT_RDB_READ_DONE    15    /* RDB read ok event: used by rmon */
#define OS_EVENT_RDB_LOG_DONE     16    /* read of log data complete */
#define OS_EVENT_RDB_DATA_DONE    17    /* read of hostio data complete */
#define OS_EVENT_RDB_REQ_RAMROM   18    /* host needs ramrom access */
#define OS_EVENT_RDB_FREE_RAMROM  19    /* host is done with ramrom access */
#define OS_EVENT_RDB_DBG_DONE     20
#define OS_EVENT_RDB_FLUSH_PROF   21
#define OS_EVENT_RDB_ACK_PROF     22
#endif

/* Flags to turn blocking on/off when sending/receiving message */

#define OS_MESG_NOBLOCK     0
#define OS_MESG_BLOCK       1

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/* Get count of valid messages in queue */
#define MQ_GET_COUNT(mq)    ((mq)->validCount)

/* Figure out if message queue is empty or full */
#define MQ_IS_EMPTY(mq)     (MQ_GET_COUNT(mq) == 0)
#define MQ_IS_FULL(mq)      (MQ_GET_COUNT(mq) >= (mq)->msgCount)

/* Message operations */

extern void     osCreateMesgQueue(OSMesgQueue *, OSMesg *, s32);
extern s32      osSendMesg(OSMesgQueue *, OSMesg, s32);
extern s32      osJamMesg(OSMesgQueue *, OSMesg, s32);
extern s32      osRecvMesg(OSMesgQueue *, OSMesg *, s32);

/* Event operations */

extern void     osSetEventMesg(OSEvent, OSMesgQueue *, OSMesg);

#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_MESSAGE_H_ */
