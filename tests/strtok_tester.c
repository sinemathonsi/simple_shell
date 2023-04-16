#include "main.h"

int main(void)
{
	unsigned int i, j, k = 0, words = 0;
	char *input = NULL;
	char **arr = NULL; /* gonna try to store each word here sp arr is arr of strings */
	char word_holder[1024];

	get_user_input(&input);
	/* find how man words are in the input, using " " as delimiter */
	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] != ' ')
		{
			words++;
			while (input[i] != ' ')
			{
				i++;
			}
		}
	}

	arr = malloc((words + 1) * sizeof(char)); /* allocate by number of words */

	/* store words into arr */
	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] != ' ')
		{
			/* first store word into word_holder */
			j = 0;
			while (input[i] != ' ') /* there is a BUG here because space is not the only delimeter */
			{
				word_holder[j] = input[i];
				j++;
				i++;
			}
			word_holder[j] = '\0';
		}
		arr[k] = malloc(strlen(word_holder) * sizeof(char)); /* allocate len of word_holder to arr at index k */
		arr[k] = strdup(word_holder); /* duplicate word_holder into arr */
		k++;
	}
	arr[k] = NULL; /* null terminate arr */

	/**
	 * test to check if all words added successfully
	 * it fails because even though i check for each word it still keeps going
	 * space is not the only delimeter i need to check for
	*/
	for (i = 0; arr[i] != NULL; i++)
	{
		printf("arr[%u]: %s\n", i, arr[i]);
	}

	/* free all allocated memory */
	free(input);
	for (j = 0; arr[j] != NULL; j++)
	{
		free(arr[j]);
	}
	free(arr);
	return (0);
}

