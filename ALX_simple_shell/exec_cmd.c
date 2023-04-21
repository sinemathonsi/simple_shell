#include "main.h"

void exec_cmd(char *cmd_with_path, char **av)
{
	int f_id, exec_ret;


	f_id = fork();
	if (f_id == 0)
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