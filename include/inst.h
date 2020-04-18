#ifndef MIPS_INST_H_
#define MIPS_INST_H_
#include <stdio.h>
// Definição das instruções
#define INST_NAME_ADD "ADD"
#define INST_NAME_SUB "SUB"
#define INST_NAME_MTA "MTA"
#define INST_NAME_MTB "MTB"
#define INST_NAME_MFA "MFA"
#define INST_NAME_MFB "MFB"
#define INST_NAME_HALT "HALT"
#define INST_NAME_ADDI "ADDI"
#define INST_NAME_BEQ "BEQ"
// Instrução em String
#define INST_OPCODE_ADD "000"
#define INST_OPCODE_SUB "010"
#define INST_OPCODE_MTA "110"
#define INST_OPCODE_MTB "110"
#define INST_OPCODE_MFA "111"
#define INST_OPCODE_MFB "111"
#define INST_OPCODE_HALT "111 000 11"
#define INST_OPCODE_ADDI "001"
#define INST_OPCODE_BEQ "011"

struct inst
{       const char *name;                    
		const char *opcode;                   
		void (*encode)(FILE *, const char *); 
};

#endif //  MIPS_INST_H_