#include "main.h"

/**
 * print_the_env - prints the environment vars
 * @arg: unused but need for which_builtin to work
 * @env: environment variable passed form main functions prototype
*/
void print_the_env(char * arg, char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
}
