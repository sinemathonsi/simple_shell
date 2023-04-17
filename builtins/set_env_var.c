#include "main.h"

void set_env_var(char *arg)
{
	int i = 0;
	char **new_env;

	while (environ[i] != NULL)
	{
		i++;
	}
	new_env = malloc((i + 2) * sizeof(char *));
	for (i = 0; environ[i] != NULL; i++)
	{
		new_env[i] = malloc(strlen(environ[i]) * sizeof(char));
		strcpy(new_env[i], environ[i]);
	}
	new_env[i] = malloc(strlen(arg) * sizeof(char));
	strcpy(new_env[i], arg);
	new_env[i + 1] = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		free(environ[i]);
	}
	free(environ);

	environ = new_env;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("env_var: %s\n", environ[i]);
	}
}
