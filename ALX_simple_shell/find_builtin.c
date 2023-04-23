#include "main.h"

/**
 * which_func - matches user input to builtin function
 * @input: user input to match
 * @arg: an arg to pass if built in func is matched
 * Return: Builtin matched (0), Not matched (-1)
 */
int which_func(char *input, char *arg)
{
	int i;
	builtins for_shell[] = {/* array of structs for builtin funcs */
							{"exit", builtin_exit},
							{"env", builtin_print_env},
							{"\0", NULL}}; /* struct to stop looping at */

	for (i = 0; for_shell[i].func_names[0] != '\0'; i++)
	{
		if (stringcmp(input, for_shell[i].func_names))
		{
			for_shell[i].func(arg); /* call found function ret 0 (Success) */
			return (0);
		}
	}
	return (-1);
}
