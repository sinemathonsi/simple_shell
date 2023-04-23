#include "main.h"

/**
 * exec_cmd - create new process to execute found command
 * @cmd_with_path: command to execute with excact path
 * @av: arguments passed to command
 */
void exec_cmd(char *cmd_with_path, char **av)
{
	int exec_ret;
	pid_t pid;

	pid = fork();
	if (pid == -1) /* if fork fails */
		perror("Error");

	if (pid == 0)
	{
		exec_ret = execve(cmd_with_path, av, environ);
		if (exec_ret == -1) /* if execve fails */
		{
			perror("Error");
		}
	}
	else
	{
		wait(NULL); /* wait for child to finish */
	}
}