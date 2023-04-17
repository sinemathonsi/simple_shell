#include "main.h"

void shell_exit(char *args)
{
	int num, i;

	if (args == NULL)
		exit(0);

	for (i = 0; args[i] != '\0'; i++)
	{
		if (args[i] < '0' || args[i] > '9')
		{
			return;
		}
	}
	num = atoi(args);
	exit(num);
}
