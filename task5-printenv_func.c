#include "main.h"

/**
 * print_the_env - prints the environment vars
 * @arg: unused but need for which_builtin to work
 * @env: environment variable passed form main functions prototype
*/
void print_the_env(char * arg, char **env)
{
	int i;
	char **new_env;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("env_var: %s\n", environ[i]);
	}
	printf("\n");

	new_env = malloc((i + 2) * sizeof(char *));
	new_env[i + 2] = NULL;
	for (i = 0; environ[i] != NULL; i++)
	{
		new_env[i] = strdup(environ[i]);
	}
	new_env[i] = strdup("my_var=someTextHere");

	for (i = 0; new_env[i] != NULL; i++)
	{
		printf("new_env: %s\n", new_env[i]);
	}
	printf("\n");
}
