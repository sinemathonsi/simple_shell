#include "main.h"

/**
 * shell_exit - the builtin exit function
 * @args: args to pass to exit
 * @env: necessary for struct to use built in env function, not used here though
 */
void shell_exit(char *args, char **env)
{
	int num;

	if (*args == '0')
	{
		exit(0);
	}

	num = atoi(args);
	if (num == 0)
	{
		perror("Invalid number");
		return;
	}
	else
	{
		exit(num);
	}
}
