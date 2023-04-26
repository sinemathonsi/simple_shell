#include "main.h"

/**
 * builtin_exit - exits the shell
 * @status: string arg to pass to exit
 */
void builtin_exit(char *status)
{
	int num;

	if (status == NULL)
		exit(0);

	/* does not handle error if non number chars were passed*/

	num = atoi(status);
	exit(num);
}