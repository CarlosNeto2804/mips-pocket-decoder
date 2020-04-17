#include <stdio.h>
#include <stdlib.h>
#include <utils.h> 

extern void encode(FILE *output, FILE *input);
static void usage(void)
{
	fprintf(stderr, "mips-pocket-decoder [input] [output]\n");
	exit(EXIT_FAILURE);
}
int main(int argsc, const char *argsv[])
{
	const char *errorstr;
	FILE *input = stdin;
	FILE *output = stdout;
	if (argsc > 3)
		usage();

	if (argsc == 3)
	{
		if ((input = fopen(argsv[1], "r")) == NULL)
		{
			errorstr = "Não foi possível abrir o arquivo de entrada";
			goto error0;
		}

		if ((output = fopen(argsv[2], "w")) == NULL)
		{
			errorstr = "Não foi possivel criar o arquivo de saída";
			goto error1;
		}
	}

	encode(output, input);
	fclose(input);
	fclose(output);
	return (EXIT_SUCCESS);

error1:
	fclose(input);
error0:
	error(errorstr);
	return (EXIT_FAILURE);
}
