/*
 * filewrite.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"

typedef struct {
    unsigned int address;
    unsigned int length;
} cam_ptp_data_chunk; //camera specific structure

// Found in sub_FFAE0EFC (1.00c) --> "CMP     R0, #6"
#define MAX_CHUNKS_FOR_JPEG 7   // filewritetask is prepared for this many chunks
/*
 * fwt_data_struct: defined here as it's camera dependent
 * unneeded members are designated with unkn
 * pdc is required, everything after that is optional (DryOS < R50)
 * file_offset, full_size, seek_flag only needs to be defined for DryOS>=r50 generation cameras
 */
typedef struct
{
    int unkn1[5];                                   // sub_FFAE0EFC --> "LDR     R7, [R0, #0x14]!"
    cam_ptp_data_chunk pdc[MAX_CHUNKS_FOR_JPEG];
    int unkn2;
    char name[32];                                  // sub_FFAE0DBC --> "ADD     R0, R0, #0x50"
                                                    // offset of 'name' from start = 0x50 = 80 bytes = 20 words
} fwt_data_struct;

#include "../../../generic/filewrite.c"

/*************************************************************/
//** filewritetask @ 0xFFAE0AF0 - 0xFFAE0BCC, length=56
void __attribute__((naked,noinline)) filewritetask() {
asm volatile (
"    STMFD   SP!, {R1-R5,LR} \n"
"    LDR     R4, =0xC0C4 \n"

"loc_FFAE0AF8:\n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #8 \n"
"    BL      sub_FF83A460 /*_ReceiveMessageQueue*/ \n"
"    CMP     R0, #0 \n"
"    LDRNE   R1, =0x33F \n"
"    LDRNE   R0, =0xFFAE0BE0 /*'dwFWrite.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP, #8] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #9 \n"
"    ADDLS   PC, PC, R1, LSL#2 \n"
"    B       loc_FFAE0AF8 \n"
"    B       loc_FFAE0BC0 \n"
"    B       loc_FFAE0BC0 \n"
"    B       loc_FFAE0BC0 \n"
"    B       loc_FFAE0BC0 \n"
"    B       loc_FFAE0BC0 \n"
"    B       loc_FFAE0BC0 \n"
"    B       loc_FFAE0BC0 \n"
"    B       loc_FFAE0BC8 \n"
"    B       loc_FFAE0B54 \n"
"    B       loc_FFAE0BB8 \n"

"loc_FFAE0B54:\n"
"    MOV     R0, #0 \n"
"    STR     R0, [SP] \n"

"loc_FFAE0B5C:\n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R1, SP \n"
"    BL      sub_FF83A6A4 /*_GetNumberOfPostedMessages*/ \n"
"    LDR     R0, [SP] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FFAE0B88 \n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_FF83A460 /*_ReceiveMessageQueue*/ \n"
"    B       loc_FFAE0B5C \n"

"loc_FFAE0B88:\n"
"    LDR     R0, [R4, #4] \n"
"    CMN     R0, #1 \n"
"    BEQ     loc_FFAE0BAC \n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    MVN     R0, #0 \n"
"    STR     R0, [R4, #4] \n"
"    LDR     R0, =0xFE668 \n"
"    BL      sub_FF876B34 \n"
"    BL      sub_FF874D90 \n"

"loc_FFAE0BAC:\n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      _GiveSemaphore \n"
"    B       loc_FFAE0AF8 \n"

"loc_FFAE0BB8:\n"
"    BL      sub_FFAE0DC8_my \n"  // --> Patched. Old value = 0xFFAE0DC8.
"    B       loc_FFAE0AF8 \n"

"loc_FFAE0BC0:\n"
"    BL      sub_FFAE0F08_my \n"  // --> Patched. Old value = 0xFFAE0F08.
"    B       loc_FFAE0AF8 \n"

"loc_FFAE0BC8:\n"
"    BL      sub_FFAE097C_my \n"  // --> Patched. Old value = 0xFFAE097C.
"    B       loc_FFAE0AF8 \n"
);
}

/*************************************************************/
//** sub_FFAE0DC8_my @ 0xFFAE0DC8 - 0xFFAE0E7C, length=46
void __attribute__((naked,noinline)) sub_FFAE0DC8_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    MOV     R4, R0 \n"
"    ADD     R0, R0, #0x50 \n"
"    SUB     SP, SP, #0x38 \n"
"    BL      sub_FF876B34 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF874D28 \n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      sub_FF810338 \n"
"    LDR     R0, [R4, #0x4C] \n"
"    LDR     R8, =0x1B6 \n"
"    CMP     R0, #1 \n"
"    LDREQ   R0, [R4, #8] \n"
"    ADD     R6, R4, #0x50 \n"
"    ORREQ   R0, R0, #0x8000 \n"
"    STREQ   R0, [R4, #8] \n"
"    LDR     R7, [R4, #8] \n"
"    LDR     R5, [R4, #0xC] \n"
//hook start
"    STMFD   SP!, {R4-R12,LR} \n"
"    MOV     R0, R4 \n"
"    BL      filewrite_main_hook \n"
"    LDMFD   SP!, {R4-R12,LR} \n"
//hook end
"    MOV     R0, R6 \n"
"    MOV     R2, R8 \n"
"    MOV     R1, R7 \n"
"    BL      fwt_open \n"  // --> Patched. Old value = _Open.
"    CMN     R0, #1 \n"
"    BNE     sub_FFAE0E80 \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF837474 \n"
"    MOV     R2, #0xF \n"
"    MOV     R1, R6 \n"
"    MOV     R0, SP \n"
"    BL      sub_FFBB3254 \n"
"    LDR     R0, =0x41FF \n"
"    MOV     R1, #0 \n"
"    STRB    R1, [SP, #0xF] \n"
"    STR     R0, [SP, #0x20] \n"
"    MOV     R0, #0x10 \n"
"    ADD     R2, SP, #0x24 \n"
"    STMIA   R2, {R0,R1,R5} \n"
"    ADD     R1, SP, #0x20 \n"
"    MOV     R0, SP \n"
"    STR     R5, [SP, #0x30] \n"
"    STR     R5, [SP, #0x34] \n"
"    BL      sub_FF874698 \n"
"    MOV     R2, R8 \n"
"    MOV     R1, R7 \n"
"    MOV     R0, R6 \n"
"    BL      fwt_open \n"  // --> Patched. Old value = _Open.
"    LDR     PC, =0xFFAE0E80 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FFAE0F08_my @ 0xFFAE0F08 - 0xFFAE0FD0, length=51
void __attribute__((naked,noinline)) sub_FFAE0F08_my() {
asm volatile (
"    STMFD   SP!, {R4-R10,LR} \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #6 \n"
"    BHI     loc_FFAE0F3C \n"
"    ADD     R0, R5, R0, LSL#3 \n"
"    LDR     R7, [R0, #0x14]! \n"
"    LDR     R6, [R0, #4] \n"
"    CMP     R6, #0 \n"
"    BNE     loc_FFAE0F4C \n"

"loc_FFAE0F30:\n"
"    MOV     R1, R5 \n"
"    MOV     R0, #7 \n"
"    B       sub_FFAE0FE0 \n"

"loc_FFAE0F3C:\n"
"    LDR     R1, =0x299 \n"
"    LDR     R0, =0xFFAE0BE0 /*'dwFWrite.c'*/ \n"
"    BL      _DebugAssert \n"
"    B       loc_FFAE0F30 \n"

"loc_FFAE0F4C:\n"
"    LDR     R9, =0xC0C4 \n"
"    MOV     R4, R6 \n"

"loc_FFAE0F54:\n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R4, #0x1000000 \n"
"    MOVLS   R8, R4 \n"
"    MOVHI   R8, #0x1000000 \n"
"    BIC     R1, R0, #0xFF000000 \n"
"    CMP     R1, #0 \n"
"    BICNE   R0, R0, #0xFF000000 \n"
"    RSBNE   R0, R0, #0x1000000 \n"
"    CMPNE   R8, R0 \n"
"    MOVHI   R8, R0 \n"
"    LDR     R0, [R9, #4] \n"
"    MOV     R2, R8 \n"
"    MOV     R1, R7 \n"
"    BL      fwt_write \n"  // --> Patched. Old value = _Write.
"    LDR     R1, [R5, #4] \n"
"    CMP     R8, R0 \n"
"    ADD     R1, R1, R0 \n"
"    STR     R1, [R5, #4] \n"
"    BEQ     loc_FFAE0FB4 \n"
"    CMN     R0, #1 \n"
"    LDRNE   R0, =0x9200015 \n"
"    LDREQ   R0, =0x9200005 \n"
"    STR     R0, [R5, #0x10] \n"
"    B       loc_FFAE0F30 \n"

"loc_FFAE0FB4:\n"
"    SUB     R4, R4, R0 \n"
"    CMP     R4, R6 \n"
"    ADD     R7, R7, R0 \n"
"    LDRCS   R0, =0xFFAE0BE0 /*'dwFWrite.c'*/ \n"
"    MOVCS   R1, #0x2C4 \n"
"    BLCS    _DebugAssert \n"
"    CMP     R4, #0 \n"
"    BNE     loc_FFAE0F54 \n"
"    LDR     PC, =0xFFAE0FD4 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FFAE097C_my @ 0xFFAE097C - 0xFFAE09B0, length=14
void __attribute__((naked,noinline)) sub_FFAE097C_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0xC0C4 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    SUB     SP, SP, #0x38 \n"
"    CMN     R0, #1 \n"
"    BEQ     sub_FFAE09C4 \n"
"    LDR     R1, [R4, #8] \n"
"    LDR     R6, =0x9200003 \n"
"    TST     R1, #0x8000 \n"
"    BEQ     loc_FFAE09B0 \n"
//mod start
"    LDR R3, =current_write_ignored\n"
"    LDR R3, [R3]\n"
"    CMP R3, #0\n"
"    BNE loc_D\n" // jump over the next block
//mod end
"    BL      sub_FF873DD4 \n"
"    B       sub_FFAE09B4 \n"

"loc_FFAE09B0:\n"
"loc_D:\n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    LDR     PC, =0xFFAE09B4 \n"  // Continue in firmware
);
}
