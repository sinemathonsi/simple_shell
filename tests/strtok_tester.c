#include "main.h"

/**
 * num_of_words - find number of words in input
 * @input: sentence to count words
 * Return: words counted
*/
unsigned int num_of_words(char *input)
{
	unsigned int i, words = 0;

	if (input == NULL)
		return (0);
	
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
	return (words);
}

/**
 * init_argv - initialize a 2d array with strings
 * @arr: array to init
 * @input: string to seperate and place in arr
*/
void init_argv(char **arr, char *input)
{
	unsigned int i, j, k = 0;
	char word_holder[1024];

	/* store words into arr */
	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] != ' ')
		{
			/* first store word into word_holder */
			j = 0;
			while (input[i] != ' ' && input[i] != '\0')
			{
				word_holder[j] = input[i];
				j++;
				i++;
			}
			word_holder[j] = '\0';
			i--;
			arr[k] = malloc(strlen(word_holder) * sizeof(char)); /* allocate len of word_holder to arr at index k */
			strcpy(arr[k], word_holder); /* duplicate word_holder into arr */
			k++;
		}
	}
	arr[k] = NULL;
}

/**
 * over here i am trying to replicate strtok
 * i am getting a segmentation fault somewhere
*/
int main(void)
{
	unsigned int i, j, words = 0;
	char *input = NULL;
	char **arr = NULL; /* gonna try to store each word here sp arr is arr of strings */
	char word_holder[1024];

	get_user_input(&input);
	/* find how man words are in the input, using " " as delimiter */
	words = num_of_words(input);
	printf("%u\n", words);

	arr = malloc((words + 1) * sizeof(char *)); /* allocate by number of words */

	/* store words into arr */
	init_argv(arr, input);

	/**
	 * test to check if all words added successfully
	 * i am getting a segmentation fault im not sure where
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
