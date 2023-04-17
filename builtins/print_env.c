#include "main.h"

void print_the_env(char *input)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("env_var: %s\n", environ[i]);
		environ++;
	}
	printf("\n");
	return;
}
