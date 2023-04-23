#include "main.h"

/**
 * stringcmp - compare string for matching
 * @s1: 1st string
 * @s2: second string
 * Return: Matched (1), Not mathed (0)
 */
int stringcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (0);
		}
		else if (s1[i + 1] != '\0' && s2[i + 1] == '\0')
		{
			return (0);
		}
		else if (s1[i + 1] == '\0' && s2[i + 1] != '\0')
		{
			return (0);
		}
	}
	return (1);
}

/**
 * which_func - matches user input to builtin function
 * @input: user input to match
 * @arg: an arg to pass if built in func is matched
 * Return: Builtin matched (0), Not matched (-1)
 */
int which_func(char *input, char *arg)
{
	int i;
	builtins for_shell[] = {
		{"exit", builtin_exit},
		{"env", builtin_print_env},
		{"\0", NULL}};

	for (i = 0; for_shell[i].func_names[0] != '\0'; i++)
	{
		if (stringcmp(input, for_shell[i].func_names))
		{
			for_shell[i].func(arg);
			return (0);
		}
	}
	return (-1);
}
