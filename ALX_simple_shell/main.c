#include "main.h"

/**
 * main - Entry point
 * @ac: unused argument
 * @av: 2d array for command line args
 * Return: 0 Success
 */
int main(__attribute__((unused)) int ac, char **av)
{
	char *argv_0_holder = av[0]; /* holds name of program for err msg */
	int i;

	while (1)
	{
		shell_loop(argv_0_holder, av);
	}
	return (0);
}
