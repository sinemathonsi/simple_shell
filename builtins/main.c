#include "main.h"

int main(void)
{
	int builtin_ret;
	unsigned int words, i;
	char *input, *tokens, **argv;

	while (1)
	{
		printf("($)");
		get_user_input(&input);
		words = count_words(input);
		argv = malloc((words + 1) * sizeof(char *));
		if (argv == NULL)
		{
			printf("malloc failed\n");
		}
		tokens = strtok(input, " \n");
		for (i = 0; tokens != NULL; i++)
		{
			argv[i] = malloc(strlen(tokens) * sizeof(char));
			if (argv[i] == NULL)
			{
				printf("malloc to indexes failed\n");
			}
			strcpy(argv[i], tokens);
			tokens = strtok(NULL, " \n");
		}
		argv[i] = NULL;
		builtin_ret = which_func(argv[0], argv[1]);
		if (builtin_ret == -1)
		{
			printf("builtin not found: %s\n", argv[0]);
		}
		free(input);
		for (i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
		}
		free(argv[i]);
		free(argv);
	}

	return (0);
}
