#include "PR/os_internal.h"
#include "../io/controller.h"
#include "PR/os_voice.h"

s32 __osVoiceSetADConverter(OSMesgQueue*, int ch, u8 cmd);

#define ACOUNT(a) (sizeof((a)) / sizeof((a[0])))

s32 osVoiceControlGain(OSVoiceHandle *hd, s32 analog, s32 digital) {
    s32 ret;
    u8 cmd = (u8) (analog == 0 ? 0x18 : 0x98);
    static u8 digital_table[] = {0x00, 0x80, 0x40, 0xC0, 0x20, 0xA0, 0x60, 0xE0};

    ERRCK(__osVoiceSetADConverter(hd->__mq,hd->__channel, cmd));
    
    if ((digital < 8) && (digital >= 0)) {
        cmd = digital_table[digital] + 2;
    } else {
        return 5;
    }

    ERRCK(__osVoiceSetADConverter(hd->__mq,hd->__channel, cmd));
    return ret;
}
