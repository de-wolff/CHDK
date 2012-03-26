#include "stubs_asm.h"
#define NULL_SUB 0xFF02D7E0

// Override stubs_entry.S
NHSTUB(kbd_pwr_off,                 NULL_SUB)
NHSTUB(kbd_pwr_on,                  NULL_SUB)

NHSTUB(MakeAFScan,                  NULL_SUB)
NHSTUB(UnsetZoomForMovie,           NULL_SUB)
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

DEF(some_flag_for_af_scan                   ,0x00007534) // TODO: TAKEN FROM S95
