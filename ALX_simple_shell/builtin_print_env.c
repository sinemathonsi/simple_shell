#include "main.h"

void builtin_print_env(__attribute__((unused)) char *arg)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}