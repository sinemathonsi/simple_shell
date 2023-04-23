#include "main.h"

void shell_loop(char **av)
{
	char *input, *path_to_cmd, **arr;
	size_t n = 0;
	ssize_t got_line;
	int words;

	printf("($)");
	got_line = getline(&input, &n, stdin);
	if (got_line == -1)
	{
		putchar('\n');
		exit(0);
	}

	words = word_count(input);
	arr = malloc((words + 1) * sizeof(char *));

	parse_inp(arr, input);
	if (*input == '\n')
		return;

	which_func(arr[0], arr[1]);
	path_to_cmd = found_path(arr[0]);
	if (path_to_cmd == NULL)
		dprintf(STDERR_FILENO, "%s: No such file or directory\n", av[0]);
	else
		exec_cmd(path_to_cmd, arr);
}