extern long *blob_chdk_core;
extern long blob_chdk_core_size;

//long* MEMISOSTART = 0x30BA30;

void __attribute__((noreturn)) my_restart() 
{
    {
        long *dst = (long*)MEMISOSTART;
        const long *src = blob_chdk_core;
        long length = (blob_chdk_core_size + 3) >> 2;

        if (src < dst && dst < src + length)
        {
            /* Have to copy backwards */
            src += length;
            dst += length;
            while (length--)
            {
                *--dst = *--src;
            }
        }
        else
        {
            while (length--)
            {
                *dst++ = *src++;
            }
        }
    }

	// resetcode here:
	// S120 100e @FC0D5C20
    asm volatile (
        "PUSH            {R4,LR} \n"
        "MOV             R4, R0 \n"
        "BL              sub_FC0D9068 \n"
        "BL              sub_FC064B0C \n"
        "BL              sub_FC0E4582 \n"
        "MOVS            R0, #1 \n"
        "BL              sub_FC0ACBFC \n"
        "CMP             R4, #3 \n"
        "BEQ             loc_FC0D5C3E \n"
        "BL              sub_FC41C178 \n"
        "BL              sub_FC1309AC \n"
        "BL              sub_FC13B92C \n"
        "BL              sub_FC41A168 \n"
        "BLX             sub_FC2B2620 \n"
        "BLX             sub_FC2B2970 \n"
        "BL              sub_FC0E44DA \n"
        "CMP             R4, #7 \n"
        "BEQ             locret_FC0D5C6A \n"
        "MOVW            R1, #0x4FFC \n"
        "LDR             R0, =0x12345678 \n"
        "STR             R0, [R1] \n"
        "LDR             R0, =(sub_FC020000+1) \n"
//      "LDR             R0, =MEMISOSTART \n" //new jump-vector
        "POP.W           {R4,LR} \n"
        "BX              R0 \n"
    "locret_FC0D5C6A: \n"
        "POP             {R4,PC} \n"
      : : /* "r"(MEMISOSTART) */ : "memory", "r0", "r1", "r2", "r3", "r4");

    while(1);
}

