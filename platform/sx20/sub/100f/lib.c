#include "platform.h"

char *hook_raw_image_addr()
{
  return (char*) 0x41F723E0; // with help of SD980 (sub_FF8B8514)
}

void *vid_get_bitmap_fb()
{
  return (void*)0x403F1000; // sub_FF90A358 
}

void *vid_get_viewport_fb()
{
  return (void*)0x41020120; // sub_FF8CB908
}

void *vid_get_viewport_fb_d()
{
  return (void*)(*(int*)(0x2A30+0x58)); // sub_FF8718D0
}

int vid_get_viewport_width()
{
  return 360;
}

long vid_get_viewport_height()
{
  return 240;
}

char *camera_jpeg_count_str()
{
  return (char*)0x72DB0; // loc_FF9F71B0
}
