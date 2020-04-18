#include <inst.h>
#include <regs.h>
#include <utils.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern struct inst instructions[];
extern struct regs registers[];
const char *delim = " ,()";


static const char *opcode_lookup(const char *inst)
{
    if (inst == NULL)
        return (NULL);

    for (int i = 0; instructions[i].name != NULL; i++)
    {
        if (!strcmp(instructions[i].name, inst))
            return (instructions[i].opcode);
    }
    return (NULL);
}

static const char *register_lookup(const char *register_name)
{
	if (register_name == NULL)
		return (NULL);

	for (int i = 0; i < REG_NUM; i++)
	{
		if (!strcmp(registers[i].name, register_name))
			return (registers[i].code);
	}

	return (NULL);
}

static void encode_addi_instruction(FILE *output, const char *inst){
    const char *opcode;
    const char *branch10;
    char branch2[33];
    check((branch10 = strtok(NULL, delim)) != NULL);
    check((opcode = opcode_lookup(inst)) != NULL);
    itoa2(atoi(branch10), branch2, 2);
    fprintf(output, "%s %s\n", opcode, &branch2[27]);
}
static void encode_beq_instruction(FILE *output, const char *inst){
	const char *opcode;
    const char *rt;
	const char *rs;
    check((rt = register_lookup(strtok(NULL, delim))) != NULL);
	check((rs = register_lookup(strtok(NULL, delim))) != NULL);
	check((opcode = opcode_lookup(inst)) != NULL);
	fprintf(output, "%s %s %s 0\n", opcode,rt,rs);
}


static void encode_addi(FILE *output, const char *inst)
{
	encode_addi_instruction(output, inst);
}
static void encode_beq(FILE *output, const char *inst)
{
	encode_beq_instruction(output, inst);
}

struct inst instructions[] = {
	{INST_NAME_ADDI, INST_OPCODE_ADDI,  encode_addi},
	{INST_NAME_BEQ, INST_OPCODE_BEQ,  encode_beq},
    {NULL, NULL,  NULL},
};

struct regs registers[] = {
    {REG_R0_NAME, REG_R0_NUM_STR},
    {REG_R1_NAME, REG_R1_NUM_STR},
    {REG_R2_NAME, REG_R2_NUM_STR},
    {REG_R3_NAME, REG_R3_NUM_STR},
};

void encode(FILE *output, FILE *input)
{
    ssize_t nread;
    size_t len = 0;
    char *line = NULL;
    while ((nread = getline(&line, &len, input)) != -1)
    {
        int unkown = 1;
        char *token;
        line[nread - 1] = '\0';
        debug(line);
        if ((token = strtok(line, delim)) == NULL)
            break;
        for (int j = 0; instructions[j].encode != NULL; j++)
        {
            if (!strcmp(token, instructions[j].name))
            {
                unkown = 0;
                instructions[j].encode(output,token);
                break;
            }
        }

        if (unkown)
            error("Comando não suportado");
    }
    free(line);
}



// int converter_to_binary(int num)
// {
//     int aux;
//     int bin[5]; // <---------------
//     for (aux = 4; aux >= 0; aux--)
//     {
//         if (num % 2 == 0)
//             bin[aux] = 0;
//         else
//             bin[aux] = 1;
//         num = num / 2;
//     }
//     return bin;
// }
// static void encode_add(FILE *output, const char *inst){}
// static void encode_sub(FILE *output, const char *inst){}
// static void encode_mta(FILE *output, const char *inst){}
// static void encode_mtb(FILE *output, const char *inst){}
// static void encode_mfa(FILE *output, const char *inst){}
// static void encode_mfb(FILE *output, const char *inst){}
// static void encode_beq(FILE *output, const char *inst){}
// static void encode_halt(FILE *output, const char *inst){}