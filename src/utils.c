#include <stdio.h>
#include <stdlib.h>
void error(const char *msg)
{
	fprintf(stderr, "%s\n", msg);

	exit(EXIT_FAILURE);
}
void debug(const char *msg)
{
#ifndef NDEBUG
	fprintf(stderr, "%s\n", msg);
#else
	((void) msg);
#endif
}

static void reverse(char *str, int len)
	{
	int start = 0;
	int end = len -1;
	while (start < end)
	{
		char tmp;
		tmp = *(str+start);
		*(str+start) = *(str+end);
		*(str+end) = tmp;

		start++;
		end--;
	}
}

char *itoa2(int val, char *str)
{
	int i = 0;
	int isNegative = 0;
	if (val == 0)
	{
		for ( ; i < 32; i++)
			str[i] = '0';
		str[i] = '\0';
		return str;
	}

	while (val != 0)
	{
		int rem = val % 2;
		str[i++] = rem + '0';
		val = val/2;
	}

	if (isNegative)
		str[i++] = '-';

	for ( ; i < 32; i++)
		str[i] = '0';

	str[i] = '\0';

	reverse(str, i);

	return str;
}
  
void __checkfail(int x, const char *msg, const char *filename, int linenum)
{
	if (!x)
	{
		fprintf(stderr, "%s: %s %d\n", msg, filename, linenum);
		exit(EXIT_FAILURE);
	}
}
