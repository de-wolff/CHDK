#include "platform.h"
#include "stdlib.h"
#include "lolevel.h"

void *vid_get_bitmap_fb()        { return (void*)0x40685000; }             // Found @0xff051fbc
void *vid_get_viewport_fb()      { return (void*)0x407dab80; }             // Found @0xff3fc0d8
void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3da0+0x58)); } // Found @0xff07007c & 0xff0700b4
char *camera_jpeg_count_str()    { return (char*)0x000cf0cc; }             // Found @0xff289050
long hook_raw_size()             { return 0x01297380; }                    // Found @0xff3feee0
int get_flash_params_count(void) { return 0x9f; }                          // Found @0xff206d58

char *hook_raw_image_addr() // TODO:
{
	if (*((int*)0x2ECC) != 0)
		return (char*) 0x46000000;
	else
		return (char*) 0x41269150;
}

void *vid_get_viewport_live_fb()
{
    return vid_get_viewport_fb();
}

void JogDial_CW(void){ //TODO:
	_PostLogicalEventForNotPowerType(0x874, 1);  // RotateJogDialRight
}

void JogDial_CCW(void){ //TODO:
	_PostLogicalEventForNotPowerType(0x875, 1);  // RotateJogDialLeft
}

