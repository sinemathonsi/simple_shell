#include "shell.h"

#define BUFF_SIZE 10

/**
 * get_user_input - gets user input from stdin and stores in input pointer
 * @input: char pointer to store input
 * Return: 0 (Success), -1 (Failure)
*/
int get_user_input(char **input)
{
	/**
	 * Usage:
	 * char *input, **p = &input;
	 * get_user_input(p);
	 */
	unsigned int buffsize = BUFF_SIZE, ind = 0;
	char c;

	*input = malloc(buffsize * sizeof(char));
	if (input == NULL)
	{
		perror("malloc failed");
		return (-1);
	}
	
	while (1)
	{
		c = getchar();
		if (c == EOF || c == '\n')
		{
			(*input)[ind] = '\0';
			break;
		}
		else
		{
			(*input)[ind] = c;
		}

		ind++;
		if (ind > buffsize)
		{
			buffsize += buffsize;
			input = realloc((*input), buffsize * sizeof(char));
			if ((*input) == NULL)
			{
				perror("realloc failed");
				return (-1);
			}
		}
	}
	return (0);
}
