#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int stringcmp(const char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (0);
		}
		else if (s1[i + 1] != '\0' && s2[i + 1] == '\0')
		{ /* strings arent equal, loop breaking ret 1, prevent that */
			return (0);
		}
		else if (s1[i + 1] == '\0' && s2[i + 1] != '\0')
		{ /* strings arent equal, loop breaking ret 1, prevent that */
			return (0);
		}
	}
	return (1);
}

int count_env_vars(char **the_env)
{
	int i;

	for (i = 0; the_env[i] != NULL; i++)
		;
	return (i);
}

void add_new_var(char ***env, const char *name, const char *var)
{
	int i, to_malloc;
	char **arr = NULL;

	to_malloc = count_env_vars((*env)) + 2;
	arr = malloc(to_malloc * sizeof(char *));
	for (i = 0; (*env)[i] != NULL; i++)
	{
		arr[i] = strdup((*env)[i]);
	}
	arr[i] = malloc((strlen(name) + 1 + strlen(var)) * sizeof(char));
	strcpy(arr[i], name);
	strcat(arr[i], "=");
	strcat(arr[i], var);
	strcat(arr[i], "\0");
	arr[++i] = NULL;

	(*env) = malloc(to_malloc * sizeof(char *));
	for (i = 0; arr[i] != NULL; i++)
	{
		(*env)[i] = strdup(arr[i]);
	}
	(*env)[i] = NULL;

	for (i = 0; arr[i] != NULL; i++)
		free(arr[i]);
	free(arr[i]);
	free(arr);
}

int _setenv(const char *name, const char *var, int overwrite)
{
	int i, j, eq_flag = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		eq_flag = 0;
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (name[j] != environ[i][j])
			{
				eq_flag = -1;
				break;
			}
		}
		if (eq_flag == 0 && overwrite == 1)
		{
			environ[i] = malloc((strlen(var) + strlen(name) + 2) * sizeof(char));
			strcpy(environ[i], name);
			strcat(environ[i], "=");
			strcat(environ[i], var);
			strcat(environ[i], "\0");
			break;
		}
		else if (eq_flag == 0 && overwrite == 0)
		{
			break;
		}
	}
	if (eq_flag == -1)
	{
		add_new_var(&environ, name, var);
	}
	return (0);
}

int main(void)
{
	int i, j, eq_flag = 0;
	const char *name;

	for (i = 0; environ[i] != NULL; i++)
	{
		eq_flag = 0;
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (name[j] != environ[i][j])
			{
				eq_flag = -1;
				break;
			}
		}
		}
	return (0);
}