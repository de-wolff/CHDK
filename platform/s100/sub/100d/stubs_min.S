#include "stubs_asm.h"

DEF(physw_status                            ,0x000386bc) // Found @0xff024db0
DEF(physw_run                               ,0x00001c3c) // Found @0xff02493c
DEF(levent_table                            ,0xff5905bc) // Found @0xff5905bc
DEF(FlashParamsTable                        ,0xff6267a4) // Found @0xff6267a4
DEF(movie_status                            ,0x00009bfc) // Found @0xff1cb1b0
DEF(full_screen_refresh                     ,0x0000ca28) // Found @0xff297af0
DEF(canon_menu_active                       ,0x00004484) // Found @0xff0924cc
DEF(canon_shoot_menu_active                 ,0x0000b291) // Found @0xff22ca24
DEF(playrec_mode                            ,0x000041a4) // Found @0xff083ca8
DEF(zoom_status                             ,0x0000ad6c) // Found @0xff213958
DEF(zoom_busy                               ,0x00009b24) // Found @0xff1c6118
DEF(focus_busy                              ,0x00009940) // Found @0xff1bef10
DEF(recreview_hold                          ,0x00005008) // Found @0xff0a51b0

DEF(rear_dial_position                      ,0xC0240106) // TODO:
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
DEF(focus_len_table                         ,0xfffe2d2c) // TODO:
