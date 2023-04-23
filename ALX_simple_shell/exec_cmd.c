#include "main.h"

void exec_cmd(char *cmd_with_path, char **av)
{
	int exec_ret;
	pid_t pid;

	pid = fork();
	if (pid == -1)
		perror("Error");

	if (pid == 0)
	{
		exec_ret = execve(cmd_with_path, av, environ);
		if (exec_ret == -1)
		{
			perror("Error");
		}
	}
	else
	{
		wait(NULL);
	}
}