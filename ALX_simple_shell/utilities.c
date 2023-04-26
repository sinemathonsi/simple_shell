#include "main.h"

/**
 * word_count - counts number of words in input to allocate to av
 * @input: string to count words from
 * Return: number of words in string using ' ' and '\0' a delimiters
 */
int word_count(char *input)
{
	int num_of_words = 0, i;

	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] != ' ') /* when hits space increment till next space */
		{
			num_of_words++;
			while (input[i] != ' ' && input[i] != '\0')
			{
				i++;
			}	 /* when loop ends input[i] will be on ' ' or '\0' */
			i--; /* for loop will increment i again moving it past '\0' */
		}		 /* decrement to prevent seg fault */
	}
	return (num_of_words);
}

/**
 * parse_inp - uses strtok to sep and add strings to av
 * @av: argv to add strings to
 * @input: characters from stdin
 */
void parse_inp(char **av, char *input)
{
	int i;
	char *token;

	token = my_strtok(input, " \n");
	for (i = 0; token != NULL; i++)
	{
		/* copy each string into argv at i index */
		av[i] = malloc(_strlen(token) * sizeof(char));
		_strcpy(av[i], token);
		token = my_strtok(NULL, " \n");
	}
	av[i] = NULL; /* null terminte argv */
}

/**
 * stringcmp - compare string for matching
 * @s1: 1st string
 * @s2: second string
 * Return: Matched (1), Not mathed (0)
 */
int stringcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (0);
		}
		else if (s1[i + 1] != '\0' && s2[i + 1] == '\0')
		{ /* strings arent equal, loop breaking ret 1, prevent that */
			return (0);
		}
		else if (s1[i + 1] == '\0' && s2[i + 1] != '\0')
		{ /* strings arent equal, loop breaking ret 1, prevent that */
			return (0);
		}
	}
	return (1);
}