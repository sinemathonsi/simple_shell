#include "main.h"

void builtin_exit(char *status)
{
	int num;

	if (status == NULL)
		exit(0);
	num = atoi(status);
	if (num == -1)
		perror("exit:");
	exit(num);
}