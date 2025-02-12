#ifndef _OS_EXCEPTION_H_
#define _OS_EXCEPTION_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "ultratypes.h"

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

typedef u32 OSIntMask;
typedef u32 OSHWIntr;

#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/* Flags for debugging purpose */

#define OS_FLAG_CPU_BREAK   1   /* Break exception has occurred */
#define OS_FLAG_FAULT       2   /* CPU fault has occurred */

/* Interrupt masks */

#define OS_IM_NONE      0x00000001
#define OS_IM_RCP       0x00000401
#define OS_IM_SW1       0x00000501
#define OS_IM_SW2       0x00000601
#define OS_IM_CART      0x00000c01
#define OS_IM_PRENMI    0x00001401
#define OS_IM_RDBWRITE  0x00002401
#define OS_IM_RDBREAD   0x00004401
#define OS_IM_COUNTER   0x00008401
#define OS_IM_CPU       0x0000ff01
#define OS_IM_SP        0x00010401
#define OS_IM_SI        0x00020401
#define OS_IM_AI        0x00040401
#define OS_IM_VI        0x00080401
#define OS_IM_PI        0x00100401
#define OS_IM_DP        0x00200401
#define OS_IM_ALL       0x003fff01
#define RCP_IMASK       0x003f0000
#define RCP_IMASKSHIFT  16

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/* Interrupt operations */

extern OSIntMask    osGetIntMask(void);
extern OSIntMask    osSetIntMask(OSIntMask);

#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_EXCEPTION_H_ */
