#ifdef CAM_DRYOS_NEW_TASK_HOOK

/* WARNING: This function does not save any registers,
            the calling functions saves&restores the used registers
*/
void __attribute__((naked,noinline)) code_copy() {
    asm volatile (
"copy_loop:\n" // Copy patch code to RAM location
        "LDR     R3, [R0], #4\n"
        "STR     R3, [R1], #4\n"
        "SUBS    R2, R2, #1\n"
        "BNE     copy_loop\n"
		"BX      LR\n"
		);
}

/* ERR99: PATCH the TASK CREATE functions in RAM to install our hooks.
   To catch all TaskCreate calls (needed to install our own task functions),
   it is necessary to patch to different TaskCreate functions in RAM. 
 */

void __attribute__((naked,noinline)) HookIntoTaskCreateFunction() {

    asm volatile (
		"STMFD   SP!, {R0-R3,LR}\n" // Save all register which are used below
		/* Install HOOK #1 */
		"LDR     R0, =PatchCodeHook1\n" // R0 = Start addr. of our hook code call (SRC)
		"LDR     R1, =CreateTask2_hook\n"   // Get start address of function to patch (DST)
		"MOV     R2, #(PatchCodeHook1End-PatchCodeHook1)/4\n" // WORDs to copy (lenght of patch bytes/4)
		"BL      code_copy\n"

		/* Install HOOK #2 */
		"LDR     R0, =PatchCodeHook2\n" // Get start addr. of our hook code call (SRC)
		"LDR     R1, =CreateTask_hook\n"	// Get start address of function to patch (DST) (_CreateTask)
		"MOV     R2, #(PatchCodeHook2End-PatchCodeHook2)/4\n" // WORDs to copy (lenght of patch bytes/4)
		"BL      code_copy\n"

		"LDMFD   SP!, {R0-R3,PC}\n" // Restore all used registers

		/* Our hook code payload for HOOK #1*/
"PatchCodeHook1:\n"
        //"BL TaskHookFnc1\n"
		"LDR PC, [PC, #-0x4]\n"	// Do jump to absolute adress TaskHookFnc1
		".long TaskHookFnc1\n"
"PatchCodeHook1End:\n"
        /* Our hook code payload for HOOK #2*/
"PatchCodeHook2:\n"
        //"BL TaskHookFnc2\n"
		"LDR PC, [PC, #-0x4]\n"  // Do jump to absolute adress TaskHookFnc2
		".long TaskHookFnc2\n"
"PatchCodeHook2End:\n"
	 );
}

/* Task HOOK function #1. Called if TaskCreate is called. */
void __attribute__((naked,noinline)) TaskHookFnc1() {
    asm volatile (

	"STMFD   SP!, {R0-R1}\n"
	//R3 = Pointer to task function to create

	/*** INSTALL capt_seq_task() hook ***/
	"LDR     R0, =task_CaptSeq\n"	// DryOS original code function ptr.
	"LDR     R1, =capt_seq_task\n"	// our task function base ptr.
	"CMP     R0, R3\n"	       // is the given taskptr.  equal to our searched function?
	"MOVEQ   R3, R1\n"        // if so, overwrite original task pointer in R12 with our task (R1)
	"BEQ     exitHook\n"       // below compares not necessary if this check has found something.

	/*** INSTALL exp_drv_task() hook ***/
	"LDR     R0, =task_ExpDrv\n"
	"LDR     R1, =exp_drv_task\n"
	"CMP     R0, R3\n"
	"MOVEQ   R3, R1\n"
	"BEQ     exitHook\n"

	/*** INSTALL JogDial() hook ***/
	"LDR     R0, =task_RotaryEncoder\n"
	"LDR     R1, =JogDial_task_my\n"
	"CMP     R0, R3\n"
	"MOVEQ   R3, R1\n"
	"BEQ     exitHook\n"

	/*** INSTALL movie_record_task() hook ***/
	"LDR     R0, =task_MovieRecord\n"
	"LDR     R1, =movie_record_task\n"
	"CMP     R0, R3\n"
	"MOVEQ   R3, R1\n"

"exitHook:\n" // restore overwritten registers
	"LDMFD   SP!, {R0-R1}\n"

    // We patch two words in the CreateTask2 function
    // restore the instructions and jump to original function

    "STMFD  SP!, {R3-R5,LR} \n" 
    "MOV    R12, R3 \n"
    "LDR    PC, [PC, #-0x4]\n"
    ".long  CreateTask2_hook+8\n"
	);
}


void __attribute__((naked,noinline)) TaskHookFnc2() {
    asm volatile (

	"STMFD   SP!, {R0-R1}\n"
	//R3 = Pointer to task to create
	"LDR     R0, =task_InitFileModules\n"
	"LDR     R1, =init_file_modules_task\n"
	"CMP     R0, R3\n"
	"MOVEQ   R3, R1\n"

"exitHook2:\n"
	"LDMFD   SP!, {R0-R1}\n"

    // We patch two words in the CreateTask function
    // restore the instructions and jump to original function

    "STMFD  SP!, {R1-R9,LR} \n" 
    "MOV    R4, R0 \n"
    "LDR    PC, [PC, #-0x4]\n"
    ".long  CreateTask_hook+8\n"
	);
}

#endif
