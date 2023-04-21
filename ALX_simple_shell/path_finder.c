#include "main.h"

char *found_path(char *cmd)
{
	char *path;
	char *cp_path;
	char *token;
	char *path_srch;
	struct stat buffer;

	if (stat(cmd, &buffer) == 0)
	{
		return (cmd);
	}
	
	path = getenv("PATH");
	cp_path = strdup(path);
	token = strtok(cp_path, ":\n");
	while (token != NULL)
	{
		path_srch = malloc((strlen(token) + strlen(cmd) + 2));
		strcpy(path_srch, token);
		strcat(path_srch, "/");
		strcat(path_srch, cmd);
		strcat(path_srch, "\0");

		if (stat(path_srch, &buffer) == 0)
		{
			return (path_srch);
		}
		token = strtok(NULL, ":\n");
	}
	free(path_srch);
	return (NULL);
}