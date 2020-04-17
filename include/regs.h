#ifndef MIPS_REGS_H_
#define MIPS_REGS_H_

#define REG_R0_NAME "r0"
#define REG_R1_NAME "r1"
#define REG_R2_NAME "r2"
#define REG_R3_NAME "r3"

#define REG_R0_NUM_STR "00"
#define REG_R1_NUM_STR "01"
#define REG_R2_NUM_STR "10"
#define REG_R3_NUM_STR "11"

struct regs
{
    const char *name;
    const char *code;
};

#endif //  MIPS_REGS_H_