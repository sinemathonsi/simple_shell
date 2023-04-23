#include "main.h"

int word_count(char *input)
{
	int num_of_words = 0, i;

	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] != ' ')
		{
			num_of_words++;
			while (input[i] != ' ' && input[i] != '\0')
			{
				i++;
			}
			i--;
		}
	}
	return (num_of_words);
}

void parse_inp(char **av, char *input)
{
	int i;
	char *token;

	token = strtok(input, " \n");
	for (i = 0; token != NULL; i++)
	{
		av[i] = malloc(strlen(token) * sizeof(char));
		strcpy(av[i], token);
		token = strtok(NULL, " \n");
	}
	av[i] = NULL;
}

int main(__attribute__((unused)) int ac, char **av)
{
	char *input, **arr;
	int i;

	while (1)
	{
		shell_loop(av);
	}
	for (i = 0; arr[i] != NULL; i++)
	{
		free(arr[i]);
	}
	free(arr);
	free(input);
	return (0);
}
