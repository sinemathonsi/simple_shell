#include "main.h"

void shell_loop(char *argv_0_holder, char **av, int flag)
{
	char *input, *path_to_cmd;
	size_t n = 0;
	ssize_t got_line;
	int words;

	if (flag != 0)
		printf("($)"); /* print prompt */
	got_line = getline(&input, &n, stdin);
	if (got_line == -1) /* catch eof character */
	{
		if (flag != 0)
			putchar('\n');
		exit(0);
	}
	words = word_count(input);
	av = malloc((words + 1) * sizeof(char *)); /* allocate mem to argv */
	parse_inp(av, input);					   /* fill argv with strings */
	if (*input == '\n')
		return;

	if (which_func(av[0], av[1]) == -1) /* find and execute builtin function */
	{
		path_to_cmd = found_path(av[0]); /* find path to non builtin function */
		if (path_to_cmd == NULL)		 /* command not found */
			dprintf(STDERR_FILENO, "%s: No such file or directory\n", argv_0_holder);
		else
			exec_cmd(path_to_cmd, av); /* execute found command */
	}
	free(input);
	free(path_to_cmd);
}