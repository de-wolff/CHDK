#include "stubs_asm.h"
DEF(playrec_mode                            ,0x00003b60) // 0xff0a4118 

DEF(file_counter_var,               0x00008c0c) // found by searching for "FileBackupProperty.c"

//DEF(palette_control,                0x00009a50) // Found @0xff1f6ae4 Some instructions before loading Palette colour tables value 
//DEF(active_palette_buffer,          0x00009a58) // Found @0xff1f6c6c
//DEF(palette_buffer_ptr,             0x00009a5c) // Found @0xff1f6c94 or 0xff1f71a0 : Guess palette_control+0xC
//DEF(palette_buffer,                 0x000ea930) // Found @0xff1f719c check this!!

DEF(active_viewport_buffer,         0x000022d08) // 0xff0503fc 0x22ccc + 0xff050890  0x3c = 0x22d08  search for "LiveImage.c"
DEF(viewport_buffers,               0xff63dfe8) // by comparison to sx510hs

//DEF(viewport_fb_d,                  0x00003438) // Found @0xff067204 (0x33e4) + @0xff067240 (0x54) 
DEF(viewport_fb_d,                  0x000036ac) // Found @0xff067204 (0x3658) + @0xff08c634 (0x54) 
//DEF(viewport_fb_d,                  0x0000ced80) // Found @0xff067204 (0x3658) + @0xff08c634 (0x54) 

DEF(bitmap_buffer,                  0x000040b8) //  0x4090 + 0x28 = 0x40b8  0xff0b89bc
DEF(active_bitmap_buffer,           0x000040b0) //  0x4090 + 0x20 = 0x40b0  0xff0b7bc4

DEF(recreview_hold,                 0x00002a2c+0x84) //@0xff06aa9c + 0x84 (offset used by A2500)

// see NRTBL.SetDarkSubType, ineffective for the next photo (it 'lags') 0xec68 + 0x4
DEF(_nrflag, 0xEC6C)

//TODO
DEF(rear_dial_position,        0xC0240106)  //To do
