#include "main.h"

unsigned int count_words(char *input)
{
	unsigned int i, words = 0;

	if (input == NULL)
		return (0);

	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] != ' ')
		{
			words++;
			while (input[i] != ' ' && input[i] != '\0')
			{
				i++;
			}
			i--;
		}
	}
	return (words);
}
