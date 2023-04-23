#include "main.h"

/**
 * builtin_print_env - print environment variables using environ
 * @arg: unused neccessary for function pointer to builtins
 */
void builtin_print_env(__attribute__((unused)) char *arg)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{ /* loop through environ printing each variable */
		printf("%s\n", environ[i]);
	}
}