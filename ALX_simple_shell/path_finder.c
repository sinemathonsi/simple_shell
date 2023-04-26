#include "main.h"

/**
 * found_path - finds file dest and returns path to file for execve
 * @cmd: command to find path to
 * Return: path to found command, null if not found
 */
char *found_path(char *cmd)
{
	int stat_ret;
	char *path, *cp_path, *token, *path_srch;
	struct stat buffer;

	if (stat(cmd, &buffer) == 0) /* if absolute path given ret command */
		return (cmd);

	path = getenv("PATH"); /* store entire path var */
	cp_path = _strdup(path);
	token = my_strtok(cp_path, ":\n"); /* seperate each path to bins */
	while (token != NULL)
	{
		path_srch = malloc((_strlen(token) + _strlen(cmd) + 1));
		/* append chars and command to each different path */
		_strcpy(path_srch, token);
		_strcat(path_srch, "/");
		_strcat(path_srch, cmd);

		stat_ret = stat(path_srch, &buffer);
		if (stat_ret == 0)		/* use stat to check if file exists */
			return (path_srch); /* file found */

		token = my_strtok(NULL, ":\n");
	}
	free(path_srch);
	return (NULL); /* file not found */
}