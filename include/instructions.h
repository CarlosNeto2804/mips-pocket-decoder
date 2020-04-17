#ifndef MIPS_INST_H_
#define MIPS_INST_H_
    #include<stdio.h>
    // Definição das instruções
    // tipo R
    #define INST_NAME_ADD "ADD"
    #define INST_NAME_SUB "SUB"
    #define INST_NAME_MTA "MTA"
    #define INST_NAME_MTB "MTB"
    #define INST_NAME_MFA "MFA"
    #define INST_NAME_MTA "MFB"
    #define INST_NAME_HALT "HALT"
    // tipo I
    #define INST_NAME_ADDI "ADDI"
    // tipo J
    #define INST_NAME_BEQ "BEQ"

    struct inst
	{
		const char *name;                                    
		void (*encode)(FILE *, const char *); 
	};

#endif //  MIPS_INST_H_