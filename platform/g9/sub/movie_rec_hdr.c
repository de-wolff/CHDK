#include "conf.h"

int *video_quality = &conf.video_quality;
int *video_mode    = &conf.video_mode;

long def_table[48]={
  0x2000,   0x38D,   0x788, 0x5800,  0x9C5,  0x14B8, 0x10000,  0x1C6A,  0x3C45, 0x20000,  0x387A,  0x7813,
 0x25800,  0x422F,  0x8CB6, 0x8000,  0xE35,  0x1E23, 0x10000,  0x1C6A,  0x3C45, 0x12C00,  0x2118,  0x465B,
  0x1CCD,  -0x2E1,  -0x579, 0x4F33, -0x7EB,  -0xF0C,  0xE666, -0x170A, -0x2BC6, 0x1CC39, -0x2F5B, -0x59F0,
 0x21B53, -0x377F, -0x6965, 0x7333, -0xB85, -0x15E3,  0xE666, -0x170A, -0x2BC6, 0x10DAA, -0x1BC0, -0x34B3};

long table[48];

void change_video_tables(int a, int b){
    int i;
    for (i=0;i<48;i++) table[i]=(def_table[i]*a)/b; 
}

long CompressionRateTable[]={0x60, 0x5D, 0x5A, 0x57, 0x54, 0x51, 0x4D, 0x48, 0x42, 0x3B, 0x32, 0x29, 0x22, 0x1D, 0x17, 0x14, 0x10, 0xE, 0xB, 9, 7, 6, 5, 4, 3, 2, 1};
