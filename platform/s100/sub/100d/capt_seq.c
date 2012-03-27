#include "lolevel.h"
#include "platform.h"
#include "core.h"

static long *nrflag = (long*)(0xcb38+0x00);  // Found @ ff2a56cc & ff2a5714
#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto
#define PAUSE_FOR_FILE_COUNTER 150          // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated

#include "../../../generic/capt_seq.c"

//void __attribute__((naked,noinline)) hangdebug() {
//	debug_led(1);
//	while(1);
//}

// @ 0xff07ccdc in firmware
void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
"    STMFD   SP!, {R3-R7,LR} \n" 
"    LDR     R5, =0x403D8 \n" 
"    LDR     R7, =0x4078 \n" 
"    MOV     R6, #0 \n" 
"loc_FF07CCEC:\n"
"    LDR     R0, [R7, #4] \n" 
"    MOV     R2, #0 \n" 
"    MOV     R1, SP \n" 
"    BL      sub_FF02AFD0 \n" 
"    TST     R0, #1 \n" 
"    BEQ     loc_FF07CD18 \n" 
"    LDR     R1, =0x491 \n" 
"    LDR     R0, =0xFF07C654 \n" 
"    BL      sub_FF00EDC8 \n" 
"    BL      sub_FF00ED80 \n" 
"    LDMFD   SP!, {R3-R7,PC} \n" 
"loc_FF07CD18:\n"
"    LDR     R0, [SP] \n" 
"    LDR     R1, [R0] \n" 
"    CMP     R1, #0x27 \n" 
"    ADDCC   PC, PC, R1, LSL #2 \n" 
"    B       loc_FF07CF70 \n" 
"    B       loc_FF07CDC8 \n" 
"    B       loc_FF07CDE0 \n" 
"    B       loc_FF07CDEC \n" 
"    B       loc_FF07CE00 \n" 
"    B       loc_FF07CDF8 \n" 
"    B       loc_FF07CE0C \n" 
"    B       loc_FF07CE14 \n" 
"    B       loc_FF07CE1C \n" 
"    B       loc_FF07CE38 \n" 
"    B       loc_FF07CE78 \n" 
"    B       loc_FF07CE44 \n" 
"    B       loc_FF07CE50 \n" 
"    B       loc_FF07CE58 \n" 
"    B       loc_FF07CE60 \n" 
"    B       loc_FF07CE68 \n" 
"    B       loc_FF07CE70 \n" 
"    B       loc_FF07CE80 \n" 
"    B       loc_FF07CE88 \n" 
"    B       loc_FF07CE90 \n" 
"    B       loc_FF07CE98 \n" 
"    B       loc_FF07CEA0 \n" 
"    B       loc_FF07CEA8 \n" 
"    B       loc_FF07CEB0 \n" 
"    B       loc_FF07CEB8 \n" 
"    B       loc_FF07CEC0 \n" 
"    B       loc_FF07CEC8 \n" 
"    B       loc_FF07CED4 \n" 
"    B       loc_FF07CEDC \n" 
"    B       loc_FF07CEE8 \n" 
"    B       loc_FF07CEF0 \n" 
"    B       loc_FF07CEF8 \n" 
"    B       loc_FF07CF00 \n" 
"    B       loc_FF07CF08 \n" 
"    B       loc_FF07CF10 \n" 
"    B       loc_FF07CF18 \n" 
"    B       loc_FF07CF24 \n" 
"    B       loc_FF07CF2C \n" 
"    B       loc_FF07CF38 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CDC8:\n" // jump table entry 0
"	 BL      shooting_expo_iso_override\n"  		    // added
"    BL      sub_FF07D5B0 \n" 
"    BL      shooting_expo_param_override\n"  		// added
"    BL      sub_FF079F94 \n" 
"    MOV     R0, #0\n"							// added
"	 STR     R0, [R5,#0x28]\n" // added, fixes overrides  behavior at short shutter press (from S95)
/*
"    LDR     R0, [R5, #0x28] \n" 
"    CMP     R0, #0 \n" 
"    BLNE    sub_FF1D2E60 \n" 
*/
"    B       loc_FF07CF7C \n" 
"loc_FF07CDE0:\n" // jump table entry 1
"    BL      wait_until_remote_button_is_released\n"	// added
"    BL      capt_seq_hook_set_nr\n"           		// added
"    LDR     R0, [R0, #0x10] \n" 
"    BL      sub_FF07D0C4_my \n" // ---> 
"    B       loc_FF07CF7C \n" 
"loc_FF07CDEC:\n"
"    MOV     R0, #1 \n" 
"    BL      sub_FF07D8D4 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CDF8:\n"
"    BL      sub_FF07D21C \n" 
"    B       loc_FF07CE04 \n" 
"loc_FF07CE00:\n"
"    BL      sub_FF07D590 \n" 
"loc_FF07CE04:\n"
"    STR     R6, [R5, #0x28] \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CE0C:\n"
"    BL      sub_FF07D598 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CE14:\n"
"    BL      sub_FF07D7A8 \n" 
"    B       loc_FF07CE3C \n" 
"loc_FF07CE1C:\n"
"    LDR     R4, [R0, #0x10] \n" 
"    MOV     R0, R4 \n" 
"    BL      sub_FF1D2EF0 \n" 
"    MOV     R2, R4 \n" 
"    MOV     R1, #9 \n" 
"    BL      sub_FF07AA30 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CE38:\n"
"    BL      sub_FF07D838 \n" 
"loc_FF07CE3C:\n"
"    BL      sub_FF079F94 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CE44:\n"
"    LDR     R0, [R5, #0x58] \n" 
"    BL      sub_FF07E4B8 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CE50:\n"
"    BL      sub_FF07E7B4 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CE58:\n"
"    BL      sub_FF07E818 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CE60:\n"
"    BL      sub_FF07EA14 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CE68:\n"
"    BL      sub_FF07EE64 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CE70:\n"
"    BL      sub_FF07EF14 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CE78:\n"
"    BL      sub_FF07D590 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CE80:\n"
"    BL      sub_FF1D0E34 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CE88:\n"
"    BL      sub_FF1D10A0 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CE90:\n"
"    BL      sub_FF1D115C \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CE98:\n"
"    BL      sub_FF1D1244 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CEA0:\n"
"    BL      sub_FF1D1340 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CEA8:\n"
"    MOV     R0, #0 \n" 
"    B       loc_FF07CECC \n" 
"loc_FF07CEB0:\n"
"    BL      sub_FF1D1580 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CEB8:\n"
"    BL      sub_FF1D1614 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CEC0:\n"
"    BL      sub_FF1D16D0 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CEC8:\n"
"    MOV     R0, #1 \n" 
"loc_FF07CECC:\n"
"    BL      sub_FF1D1410 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CED4:\n"
"    BL      sub_FF07DB10 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CEDC:\n"
"    BL      sub_FF07DBA4 \n" 
"    BL      sub_FF1D41FC \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CEE8:\n"
"    BL      sub_FF07DFB4 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CEF0:\n"
"    BL      sub_FF07E100 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CEF8:\n"
"    BL      sub_FF1D42C8 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CF00:\n"
"    BL      sub_FF028430 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CF08:\n"
"    BL      sub_FF0818DC \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CF10:\n"
"    BL      sub_FF081964 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CF18:\n"
"    LDR     R0, [R0, #0xC] \n" 
"    BL      sub_FF1D17F8 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CF24:\n"
"    BL      sub_FF1D1868 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CF2C:\n"
"    BL      sub_FF0819CC \n" 
"    BL      sub_FF081984 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CF38:\n"
"    MOV     R0, #1 \n" 
"    BL      sub_FF1D3600 \n" 
"    MOV     R0, #1 \n" 
"    BL      sub_FF1D3734 \n" 
"    LDRH    R0, [R5, #0xA0] \n" 
"    CMP     R0, #4 \n" 
"    LDRNEH  R0, [R5] \n" 
"    SUBNE   R1, R0, #0x4200 \n" 
"    SUBNES  R1, R1, #0x2B \n" 
"    BNE     loc_FF07CF7C \n" 
"    BL      sub_FF081964 \n" 
"    BL      sub_FF0820E0 \n" 
"    BL      sub_FF081DF4 \n" 
"    B       loc_FF07CF7C \n" 
"loc_FF07CF70:\n"
"    LDR     R1, =0x5F2 \n" 
"    LDR     R0, =0xFF07C654 \n" 
"    BL      sub_FF00EDC8 \n" 
"loc_FF07CF7C:\n"
"    LDR     R0, [SP] \n" 
"    LDR     R1, [R0, #4] \n" 
"    LDR     R0, [R7] \n" 
"    BL      sub_FF0893D8 \n" 
"    LDR     R4, [SP] \n" 
"    LDR     R0, [R4, #8] \n" 
"    CMP     R0, #0 \n" 
"    LDREQ   R1, =0x117 \n" 
"    LDREQ   R0, =0xFF07C654 \n" 
"    BLEQ    sub_FF00EDC8 \n" 
"    STR     R6, [R4, #8] \n" 
"    B       loc_FF07CCEC \n" 
	);
}

void __attribute__((naked,noinline)) sub_FF07D0C4_my()
{
 asm volatile(
"    STMFD   SP!, {R4-R6,LR} \n" 
"    LDR     R5, =0x403D8 \n" 
"    MOV     R6, R0 \n" 
"    LDR     R0, [R5, #0x28] \n" 
"    LDR     R4, =0x222F \n" 
"    CMP     R0, #0 \n" 
"    BNE     loc_FF07D120 \n" 
"    LDRH    R0, [R5] \n" 
"    CMP     R0, R4 \n" 
"    SUBNE   R1, R0, #0x4200 \n" 
"    SUBNES  R1, R1, #0x2E \n" 
"    BLEQ    sub_FF07FA08 \n" 
"    BL      sub_FF07F6A4 \n" 
"    MOV     R1, R6 \n" 
"    BL      sub_FF07F6FC \n" 
"    LDR     R0, =0x10F \n" 
"    MOV     R2, #4 \n" 
"    ADD     R1, R6, #0x68 \n" 
"    BL      sub_FF0917B4 \n" 
"    MOV     R2, #4 \n" 
"    ADD     R1, R6, #0x6C \n" 
"    MOV     R0, #0x2C \n" 
"    BL      sub_FF0917B4 \n" 
"loc_FF07D120:\n"
"    LDRH    R0, [R5] \n" 
"    CMP     R0, R4 \n" 
"    MOV     R0, R6 \n" 
"    BNE     loc_FF07D138 \n" 
"    BL      sub_FF1D3C24 \n" 
"    B       loc_FF07D13C \n" 
"loc_FF07D138:\n"
"    BL      sub_FF1D2C18 \n" 
"loc_FF07D13C:\n"
"    BL      capt_seq_hook_raw_here\n"           	// added
"    MOV     R4, R0 \n" 
"    MOV     R2, R6 \n" 
"    MOV     R1, #1 \n" 
"    BL      sub_FF07AA30 \n" 
"    TST     R4, #1 \n" 
"    MOVEQ   R0, R6 \n" 
"    BLEQ    sub_FF1D1DDC \n" 
"    LDR     R0, [R5, #0xC4] \n" 
"    CMP     R0, #2 \n" 
"    LDMNEFD SP!, {R4-R6,PC} \n" 
"    MOV     R0, R6 \n" 
"    LDMFD   SP!, {R4-R6,LR} \n" 
"    B       sub_FF07AC04 \n" 

 );
}

/*************************************************************/
// @ ff0cfb78
void __attribute__((naked,noinline)) exp_drv_task(){
asm volatile (
"    STMFD   SP!, {R4-R9,LR} \n" 
"    SUB     SP, SP, #0x24 \n" 
"    LDR     R6, =0x5A98 \n" 
"    LDR     R7, =0xBB8 \n" 
"    LDR     R4, =0x5E790 \n" 
"    MOV     R0, #0 \n" 
"    ADD     R5, SP, #0x14 \n" 
"    STR     R0, [SP, #0x10] \n" 
"loc_FF0CFB98:\n"
"    LDR     R0, [R6, #0x24] \n" 
"    MOV     R2, #0 \n" 
"    ADD     R1, SP, #0x20 \n" 
"    BL      sub_FF02AFD0 \n" 
"    LDR     R0, [SP, #0x10] \n" 
"    CMP     R0, #1 \n" 
"    BNE     loc_FF0CFBE4 \n" 
"    LDR     R0, [SP, #0x20] \n" 
"    LDR     R0, [R0] \n" 
"    CMP     R0, #0x14 \n" 
"    CMPNE   R0, #0x15 \n" 
"    CMPNE   R0, #0x16 \n" 
"    CMPNE   R0, #0x17 \n" 
"    BEQ     loc_FF0CFD44 \n" 
"    CMP     R0, #0x2A \n" 
"    BEQ     loc_FF0CFCCC \n" 
"    ADD     R1, SP, #0x10 \n" 
"    MOV     R0, #0 \n" 
"    BL      sub_FF0CFB28 \n" 
"loc_FF0CFBE4:\n"
"    LDR     R0, [SP, #0x20] \n" 
"    LDR     R1, [R0] \n" 
"    CMP     R1, #0x30 \n" 
"    BNE     loc_FF0CFC10 \n" 
"    BL      sub_FF0D0FE4 \n" 
"    LDR     R0, [R6, #0x20] \n" 
"    MOV     R1, #1 \n" 
"    BL      sub_FF0893D8 \n" 
"    BL      sub_FF00ED80 \n" 
"    ADD     SP, SP, #0x24 \n" 
"    LDMFD   SP!, {R4-R9,PC} \n" 
"loc_FF0CFC10:\n"
"    CMP     R1, #0x2F \n" 
"    BNE     loc_FF0CFC2C \n" 
"    LDR     R2, [R0, #0x8C]! \n" 
"    LDR     R1, [R0, #4] \n" 
"    MOV     R0, R1 \n" 
"    BLX     R2 \n" 
"    B       loc_FF0D01DC \n" 
"loc_FF0CFC2C:\n"
"    CMP     R1, #0x28 \n" 
"    BNE     loc_FF0CFC7C \n" 
"    LDR     R0, [R6, #0x20] \n" 
"    MOV     R1, #0x80 \n" 
"    BL      sub_FF08940C \n" 
"    LDR     R0, =0xFF0CB27C \n" 
"    MOV     R1, #0x80 \n" 
"    BL      sub_FF1C0A78 \n" 
"    LDR     R0, [R6, #0x20] \n" 
"    MOV     R2, R7 \n" 
"    MOV     R1, #0x80 \n" 
"    BL      sub_FF089318 \n" 
"    TST     R0, #1 \n" 
"    LDRNE   R1, =0x1543 \n" 
"    BNE     loc_FF0CFD38 \n" 
"loc_FF0CFC68:\n"
"    LDR     R1, [SP, #0x20] \n" 
"    LDR     R0, [R1, #0x90] \n" 
"    LDR     R1, [R1, #0x8C] \n" 
"    BLX     R1 \n" 
"    B       loc_FF0D01DC \n" 
"loc_FF0CFC7C:\n"
"    CMP     R1, #0x29 \n" 
"    BNE     loc_FF0CFCC4 \n" 
"    ADD     R1, SP, #0x10 \n" 
"    BL      sub_FF0CFB28 \n" 
"    LDR     R0, [R6, #0x20] \n" 
"    MOV     R1, #0x100 \n" 
"    BL      sub_FF08940C \n" 
"    LDR     R0, =0xFF0CB28C \n" 
"    MOV     R1, #0x100 \n" 
"    BL      sub_FF1C1848 \n" 
"    LDR     R0, [R6, #0x20] \n" 
"    MOV     R2, R7 \n" 
"    MOV     R1, #0x100 \n" 
"    BL      sub_FF089318 \n" 
"    TST     R0, #1 \n" 
"    BEQ     loc_FF0CFC68 \n" 
"    LDR     R1, =0x154D \n" 
"    B       loc_FF0CFD38 \n" 
"loc_FF0CFCC4:\n"
"    CMP     R1, #0x2A \n" 
"    BNE     loc_FF0CFCDC \n" 
"loc_FF0CFCCC:\n"
"    LDR     R0, [SP, #0x20] \n" 
"    ADD     R1, SP, #0x10 \n" 
"    BL      sub_FF0CFB28 \n" 
"    B       loc_FF0CFC68 \n" 
"loc_FF0CFCDC:\n"
"    CMP     R1, #0x2D \n" 
"    BNE     loc_FF0CFCF4 \n" 
"    BL      sub_FF0BB75C \n" 
"    BL      sub_FF0BC448 \n" 
"    BL      sub_FF0BBFAC \n" 
"    B       loc_FF0CFC68 \n" 
"loc_FF0CFCF4:\n"
"    CMP     R1, #0x2E \n" 
"    BNE     loc_FF0CFD44 \n" 
"    LDR     R0, [R6, #0x20] \n" 
"    MOV     R1, #4 \n" 
"    BL      sub_FF08940C \n" 
"    LDR     R1, =0xFF0CB2AC \n" 
"    LDR     R0, =0xFFFFF400 \n" 
"    MOV     R2, #4 \n" 
"    BL      sub_FF0BB1AC \n" 
"    BL      sub_FF0BB43C \n" 
"    LDR     R0, [R6, #0x20] \n" 
"    MOV     R2, R7 \n" 
"    MOV     R1, #4 \n" 
"    BL      sub_FF089234 \n" 
"    TST     R0, #1 \n" 
"    BEQ     loc_FF0CFC68 \n" 
"    LDR     R1, =0x1575 \n" 
"loc_FF0CFD38:\n"
"    LDR     R0, =0xFF0CBA38 \n" 
"    BL      sub_FF00EDC8 \n" 
"    B       loc_FF0CFC68 \n" 
"loc_FF0CFD44:\n"
"    LDR     R0, [SP, #0x20] \n" 
"    MOV     R8, #1 \n" 
"    LDR     R1, [R0] \n" 
"    CMP     R1, #0x12 \n" 
"    CMPNE   R1, #0x13 \n" 
"    BNE     loc_FF0CFDAC \n" 
"    LDR     R1, [R0, #0x7C] \n" 
"    ADD     R1, R1, R1, LSL #1 \n" 
"    ADD     R1, R0, R1, LSL #2 \n" 
"    SUB     R1, R1, #8 \n" 
"    LDMIA   R1, {R2,R3,R9} \n" 
"    STMIA   R5, {R2,R3,R9} \n" 
"    BL      sub_FF0CE028 \n" 
"    LDR     R0, [SP, #0x20] \n" 
"    LDR     R1, [R0, #0x7C] \n" 
"    LDR     R3, [R0, #0x8C] \n" 
"    LDR     R2, [R0, #0x90] \n" 
"    ADD     R0, R0, #4 \n" 
"    BLX     R3 \n" 
"    LDR     R0, [SP, #0x20] \n" 
"    BL      sub_FF0D13F4 \n" 
"    LDR     R0, [SP, #0x20] \n" 
"    LDR     R1, [R0, #0x7C] \n" 
"    LDR     R2, [R0, #0x98] \n" 
"    LDR     R3, [R0, #0x94] \n" 
"    B       loc_FF0D00C8 \n" 
"loc_FF0CFDAC:\n"
"    CMP     R1, #0x14 \n" 
"    CMPNE   R1, #0x15 \n" 
"    CMPNE   R1, #0x16 \n" 
"    CMPNE   R1, #0x17 \n" 
"    BNE     loc_FF0CFE64 \n" 
"    ADD     R3, SP, #0x10 \n" 
"    ADD     R2, SP, #4 \n" 
"    ADD     R1, SP, #0x14 \n" 
"    BL      sub_FF0CE294 \n" 
"    CMP     R0, #1 \n" 
"    MOV     R9, R0 \n" 
"    CMPNE   R9, #5 \n" 
"    BNE     loc_FF0CFE00 \n" 
"    LDR     R0, [SP, #0x20] \n" 
"    MOV     R2, R9 \n" 
"    LDR     R1, [R0, #0x7C]! \n" 
"    LDR     R12, [R0, #0x10]! \n" 
"    LDR     R3, [R0, #4] \n" 
"    ADD     R0, SP, #4 \n" 
"    BLX     R12 \n" 
"    B       loc_FF0CFE38 \n" 
"loc_FF0CFE00:\n"
"    LDR     R0, [SP, #0x20] \n" 
"    CMP     R9, #2 \n" 
"    LDR     R3, [R0, #0x90] \n" 
"    CMPNE   R9, #6 \n" 
"    BNE     loc_FF0CFE4C \n" 
"    LDR     R12, [R0, #0x8C] \n" 
"    MOV     R2, R9 \n" 
"    MOV     R1, #1 \n" 
"    ADD     R0, SP, #4 \n" 
"    BLX     R12 \n" 
"    LDR     R0, [SP, #0x20] \n" 
"    ADD     R2, SP, #4 \n" 
"    ADD     R1, SP, #0x14 \n" 
"    BL      sub_FF0CF814 \n" 
"loc_FF0CFE38:\n"
"    LDR     R0, [SP, #0x20] \n" 
"    LDR     R2, [SP, #0x10] \n" 
"    MOV     R1, R9 \n" 
"    BL      sub_FF0CFAC8 \n" 
"    B       loc_FF0D00D0 \n" 
"loc_FF0CFE4C:\n"
"    LDR     R1, [R0, #0x7C] \n" 
"    LDR     R12, [R0, #0x8C] \n" 
"    MOV     R2, R9 \n" 
"    ADD     R0, R0, #4 \n" 
"    BLX     R12 \n" 
"    B       loc_FF0D00D0 \n" 
"loc_FF0CFE64:\n"
"    CMP     R1, #0x23 \n" 
"    CMPNE   R1, #0x24 \n" 
"    CMPNE   R1, #0x25 \n" 
"    BNE     loc_FF0CFEB4 \n" 
"    LDR     R1, [R0, #0x7C] \n" 
"    ADD     R1, R1, R1, LSL #1 \n" 
"    ADD     R1, R0, R1, LSL #2 \n" 
"    SUB     R1, R1, #8 \n" 
"    LDMIA   R1, {R2,R3,R9} \n" 
"    STMIA   R5, {R2,R3,R9} \n" 
"    BL      sub_FF0CCFB0 \n" 
"    LDR     R0, [SP, #0x20] \n" 
"    LDR     R1, [R0, #0x7C] \n" 
"    LDR     R3, [R0, #0x8C] \n" 
"    LDR     R2, [R0, #0x90] \n" 
"    ADD     R0, R0, #4 \n" 
"    BLX     R3 \n" 
"    LDR     R0, [SP, #0x20] \n" 
"    BL      sub_FF0CD43C \n" 
"    B       loc_FF0D00D0 \n" 
"loc_FF0CFEB4:\n"
"    ADD     R1, R0, #4 \n" 
"    LDMIA   R1, {R2,R3,R9} \n" 
"    STMIA   R5, {R2,R3,R9} \n" 
"    LDR     R1, [R0] \n" 
"    CMP     R1, #0x28 \n" 
"    ADDCC   PC, PC, R1, LSL #2 \n" 
"    B       loc_FF0D00B8 \n" 
"    B       loc_FF0CFF70 \n" 
"    B       loc_FF0CFF70 \n" 
"    B       loc_FF0CFF78 \n" 
"    B       loc_FF0CFF80 \n" 
"    B       loc_FF0CFF80 \n" 
"    B       loc_FF0CFF80 \n" 
"    B       loc_FF0CFF70 \n" 
"    B       loc_FF0CFF78 \n" 
"    B       loc_FF0CFF80 \n" 
"    B       loc_FF0CFF80 \n" 
"    B       loc_FF0CFF98 \n" 
"    B       loc_FF0CFF98 \n" 
"    B       loc_FF0D00A4 \n" 
"    B       loc_FF0D00AC \n" 
"    B       loc_FF0D00AC \n" 
"    B       loc_FF0D00AC \n" 
"    B       loc_FF0D00AC \n" 
"    B       loc_FF0D00B4 \n" 
"    B       loc_FF0D00B8 \n" 
"    B       loc_FF0D00B8 \n" 
"    B       loc_FF0D00B8 \n" 
"    B       loc_FF0D00B8 \n" 
"    B       loc_FF0D00B8 \n" 
"    B       loc_FF0D00B8 \n" 
"    B       loc_FF0CFF88 \n" 
"    B       loc_FF0CFF90 \n" 
"    B       loc_FF0CFF90 \n" 
"    B       loc_FF0CFFA4 \n" 
"    B       loc_FF0CFFA4 \n" 
"    B       loc_FF0CFFAC \n" 
"    B       loc_FF0CFFE4 \n" 
"    B       loc_FF0D001C \n" 
"    B       loc_FF0D0054 \n" 
"    B       loc_FF0D008C \n" 
"    B       loc_FF0D008C \n" 
"    B       loc_FF0D00B8 \n" 
"    B       loc_FF0D00B8 \n" 
"    B       loc_FF0D00B8 \n" 
"    B       loc_FF0D0094 \n" 
"    B       loc_FF0D009C \n" 
"loc_FF0CFF70:\n"
"    BL      sub_FF0CB868 \n" 
"    B       loc_FF0D00B8 \n" 
"loc_FF0CFF78:\n"
"    BL      sub_FF0CBB60 \n" 
"    B       loc_FF0D00B8 \n" 
"loc_FF0CFF80:\n"
"    BL      sub_FF0CBDCC \n" 
"    B       loc_FF0D00B8 \n" 
"loc_FF0CFF88:\n"
"    BL      sub_FF0CC0C4 \n" 
"    B       loc_FF0D00B8 \n" 
"loc_FF0CFF90:\n"
"    BL      sub_FF0CC2E0 \n" 
"    B       loc_FF0D00B8 \n" 
"loc_FF0CFF98:\n"
"    BL      sub_FF0CC664_my \n" // -->
"    MOV     R8, #0 \n" 
"    B       loc_FF0D00B8 \n" 
"loc_FF0CFFA4:\n"
"    BL      sub_FF0CC7AC \n" 
"    B       loc_FF0D00B8 \n" 
"loc_FF0CFFAC:\n"
"    LDRH    R1, [R0, #4] \n" 
"    STRH    R1, [SP, #0x14] \n" 
"    LDRH    R1, [R4, #2] \n" 
"    STRH    R1, [SP, #0x16] \n" 
"    LDRH    R1, [R4, #4] \n" 
"    STRH    R1, [SP, #0x18] \n" 
"    LDRH    R1, [R4, #6] \n" 
"    STRH    R1, [SP, #0x1A] \n" 
"    LDRH    R1, [R0, #0xC] \n" 
"    STRH    R1, [SP, #0x1C] \n" 
"    LDRH    R1, [R4, #0xA] \n" 
"    STRH    R1, [SP, #0x1E] \n" 
"    BL      sub_FF0D1078 \n" 
"    B       loc_FF0D00B8 \n" 
"loc_FF0CFFE4:\n"
"    LDRH    R1, [R0, #4] \n" 
"    STRH    R1, [SP, #0x14] \n" 
"    LDRH    R1, [R4, #2] \n" 
"    STRH    R1, [SP, #0x16] \n" 
"    LDRH    R1, [R4, #4] \n" 
"    STRH    R1, [SP, #0x18] \n" 
"    LDRH    R1, [R4, #6] \n" 
"    STRH    R1, [SP, #0x1A] \n" 
"    LDRH    R1, [R4, #8] \n" 
"    STRH    R1, [SP, #0x1C] \n" 
"    LDRH    R1, [R4, #0xA] \n" 
"    STRH    R1, [SP, #0x1E] \n" 
"    BL      sub_FF0D11F4 \n" 
"    B       loc_FF0D00B8 \n" 
"loc_FF0D001C:\n"
"    LDRH    R1, [R4] \n" 
"    STRH    R1, [SP, #0x14] \n" 
"    LDRH    R1, [R0, #6] \n" 
"    STRH    R1, [SP, #0x16] \n" 
"    LDRH    R1, [R4, #4] \n" 
"    STRH    R1, [SP, #0x18] \n" 
"    LDRH    R1, [R4, #6] \n" 
"    STRH    R1, [SP, #0x1A] \n" 
"    LDRH    R1, [R4, #8] \n" 
"    STRH    R1, [SP, #0x1C] \n" 
"    LDRH    R1, [R4, #0xA] \n" 
"    STRH    R1, [SP, #0x1E] \n" 
"    BL      sub_FF0D12A8 \n" 
"    B       loc_FF0D00B8 \n" 
"loc_FF0D0054:\n"
"    LDRH    R1, [R4] \n" 
"    STRH    R1, [SP, #0x14] \n" 
"    LDRH    R1, [R4, #2] \n" 
"    STRH    R1, [SP, #0x16] \n" 
"    LDRH    R1, [R4, #4] \n" 
"    STRH    R1, [SP, #0x18] \n" 
"    LDRH    R1, [R4, #6] \n" 
"    STRH    R1, [SP, #0x1A] \n" 
"    LDRH    R1, [R0, #0xC] \n" 
"    STRH    R1, [SP, #0x1C] \n" 
"    LDRH    R1, [R4, #0xA] \n" 
"    STRH    R1, [SP, #0x1E] \n" 
"    BL      sub_FF0D1350 \n" 
"    B       loc_FF0D00B8 \n" 
"loc_FF0D008C:\n"
"    BL      sub_FF0CCD44 \n" 
"    B       loc_FF0D00B8 \n" 
"loc_FF0D0094:\n"
"    BL      sub_FF0CD54C \n" 
"    B       loc_FF0D00B8 \n" 
"loc_FF0D009C:\n"
"    BL      sub_FF0CD834 \n" 
"    B       loc_FF0D00B8 \n" 
"loc_FF0D00A4:\n"
"    BL      sub_FF0CDAEC \n" 
"    B       loc_FF0D00B8 \n" 
"loc_FF0D00AC:\n"
"    BL      sub_FF0CDCAC \n" 
"    B       loc_FF0D00B8 \n" 
"loc_FF0D00B4:\n"
"    BL      sub_FF0CDE1C \n" 
"loc_FF0D00B8:\n"
"    LDR     R0, [SP, #0x20] \n" 
"    LDR     R1, [R0, #0x7C] \n" 
"    LDR     R2, [R0, #0x90] \n" 
"    LDR     R3, [R0, #0x8C] \n" 
"loc_FF0D00C8:\n"
"    ADD     R0, R0, #4 \n" 
"    BLX     R3 \n" 
"loc_FF0D00D0:\n"
"    LDR     R1, [SP, #0x20] \n" 
"    LDR     R0, [R1] \n" 
"    CMP     R0, #0x10 \n" 
"    BEQ     loc_FF0D0108 \n" 
"    BGT     loc_FF0D00F8 \n" 
"    CMP     R0, #1 \n" 
"    CMPNE   R0, #4 \n" 
"    CMPNE   R0, #0xE \n" 
"    BNE     loc_FF0D0118 \n" 
"    B       loc_FF0D0108 \n" 
"loc_FF0D00F8:\n"
"    CMP     R0, #0x13 \n" 
"    CMPNE   R0, #0x17 \n" 
"    CMPNE   R0, #0x1A \n" 
"    BNE     loc_FF0D0118 \n" 
"loc_FF0D0108:\n"
"    LDRH    R0, [R4] \n" 
"    STRH    R0, [SP, #0x14] \n" 
"    LDRH    R0, [R4, #8] \n" 
"    STRH    R0, [SP, #0x1C] \n" 
"loc_FF0D0118:\n"
"    CMP     R8, #1 \n" 
"    BNE     loc_FF0D0164 \n" 
"    LDR     R0, [R1, #0x7C] \n" 
"    MOV     R2, #0xC \n" 
"    ADD     R0, R0, R0, LSL #1 \n" 
"    ADD     R0, R1, R0, LSL #2 \n" 
"    SUB     R8, R0, #8 \n" 
"    LDR     R0, =0x5E790 \n" 
"    ADD     R1, SP, #0x14 \n" 
"    BL      sub_FF44DE14 \n" 
"    LDR     R0, =0x5E79C \n" 
"    MOV     R2, #0xC \n" 
"    ADD     R1, SP, #0x14 \n" 
"    BL      sub_FF44DE14 \n" 
"    LDR     R0, =0x5E7A8 \n" 
"    MOV     R2, #0xC \n" 
"    MOV     R1, R8 \n" 
"    BL      sub_FF44DE14 \n" 
"    B       loc_FF0D01DC \n" 
"loc_FF0D0164:\n"
"    LDR     R0, [R1] \n" 
"    MOV     R3, #1 \n" 
"    CMP     R0, #0xB \n" 
"    BNE     loc_FF0D01A8 \n" 
"    MOV     R2, #0 \n" 
"    STRD    R2, [SP] \n" 
"    MOV     R2, R3 \n" 
"    MOV     R1, R3 \n" 
"    MOV     R0, #0 \n" 
"    BL      sub_FF0CB63C \n" 
"    MOV     R3, #1 \n" 
"    MOV     R2, #0 \n" 
"    STRD    R2, [SP] \n" 
"    MOV     R2, R3 \n" 
"    MOV     R1, R3 \n" 
"    MOV     R0, #0 \n" 
"    B       loc_FF0D01D8 \n" 
"loc_FF0D01A8:\n"
"    MOV     R2, #1 \n" 
"    STRD    R2, [SP] \n" 
"    MOV     R3, R2 \n" 
"    MOV     R1, R2 \n" 
"    MOV     R0, R2 \n" 
"    BL      sub_FF0CB63C \n" 
"    MOV     R3, #1 \n" 
"    MOV     R2, R3 \n" 
"    MOV     R1, R3 \n" 
"    MOV     R0, R3 \n" 
"    STR     R3, [SP] \n" 
"    STR     R3, [SP, #4] \n" 
"loc_FF0D01D8:\n"
"    BL      sub_FF0CB7B4 \n" 
"loc_FF0D01DC:\n"
"    LDR     R0, [SP, #0x20] \n" 
"    BL      sub_FF0D0FE4 \n" 
"    B       loc_FF0CFB98 \n" 
	);
}

void __attribute__((naked,noinline)) sub_FF0CC664_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n" 
"    LDR     R7, =0x5A98 \n" 
"    MOV     R4, R0 \n" 
"    LDR     R0, [R7, #0x20] \n" 
"    MOV     R1, #0x3E \n" 
"    BL      sub_FF08940C \n" 
"    MOV     R2, #0 \n" 
"    LDRSH   R0, [R4, #4] \n" 
"    MOV     R1, R2 \n" 
"    BL      sub_FF0CB30C \n" 
"    MOV     R5, R0 \n" 
"    LDRSH   R0, [R4, #6] \n" 
"    BL      sub_FF0CB45C \n" 
"    LDRSH   R0, [R4, #8] \n" 
"    BL      sub_FF0CB4B4 \n" 
"    LDRSH   R0, [R4, #0xA] \n" 
"    BL      sub_FF0CB50C \n" 
"    LDRSH   R0, [R4, #0xC] \n" 
"    MOV     R1, #0 \n" 
"    BL      sub_FF0CB564 \n" 
"    MOV     R6, R0 \n" 
"    LDRSH   R0, [R4, #0xE] \n" 
"    BL      sub_FF0D1014 \n" 
"    LDR     R0, [R4] \n" 
"    LDR     R8, =0x5E7A8 \n" 
"    CMP     R0, #0xB \n" 
"    MOVEQ   R5, #0 \n" 
"    MOVEQ   R6, R5 \n" 
"    BEQ     loc_FF0CC700 \n" 
"    CMP     R5, #1 \n" 
"    BNE     loc_FF0CC700 \n" 
"    LDRSH   R0, [R4, #4] \n" 
"    LDR     R1, =0xFF0CB26C \n" 
"    MOV     R2, #2 \n" 
"    BL      sub_FF1C0D9C \n" 
"    STRH    R0, [R4, #4] \n" 
"    MOV     R0, #0 \n" 
"    STR     R0, [R7, #0x2C] \n" 
"    B       loc_FF0CC708 \n" 
"loc_FF0CC700:\n"
"    LDRH    R0, [R8] \n" 
"    STRH    R0, [R4, #4] \n" 
"loc_FF0CC708:\n"
"    CMP     R6, #1 \n" 
"    LDRNEH  R0, [R8, #8] \n" 
"    BNE     loc_FF0CC724 \n" 
"    LDRSH   R0, [R4, #0xC] \n" 
"    LDR     R1, =0xFF0CB2F0 \n" 
"    MOV     R2, #0x20 \n" 
"    BL      sub_FF0D1034 \n" 
"loc_FF0CC724:\n"
"    STRH    R0, [R4, #0xC] \n" 
"    LDRSH   R0, [R4, #6] \n" 
"    BL      sub_FF0BB4A8_my \n" // --> 
"    B       sub_FF0CC730 \n"  // continue in firmware
	);
}

void __attribute__((naked,noinline)) sub_FF0BB4A8_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n" 
"    LDR     R5, =0x573C \n" 
"    MOV     R4, R0 \n" 
"    LDR     R0, [R5, #4] \n" 
"    CMP     R0, #1 \n" 
"    LDRNE   R1, =0x14D \n" 
"    LDRNE   R0, =0xFF0BB2E0 \n" 
"    BLNE    sub_FF00EDC8 \n" 
"    CMN     R4, #0xC00 \n" 
"    LDREQSH R4, [R5, #2] \n" 
"    CMN     R4, #0xC00 \n" 
"    LDREQ   R1, =0x153 \n" 
"    LDREQ   R0, =0xFF0BB2E0 \n" 
"    STRH    R4, [R5, #2] \n" 
"    BLEQ    sub_FF00EDC8 \n" 
"    MOV     R0, R4 \n" 
"    BL      apex2us \n"		// patched
"    B	     sub_FF0BB4EC \n"	// continue in firmware
	);
}
