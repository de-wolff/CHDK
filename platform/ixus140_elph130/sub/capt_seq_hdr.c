#include "lolevel.h"
#include "platform.h"
#include "core.h"

// NOTE auto in P mode doesn't seem to ever enable dark frame, even if you override > 1.3 sec
static long *nrflag = (long*)(0xE4F0+4); // FF3634B8, 4th arg to  sub_FF2A49C4

#include "../../../generic/capt_seq.c"
