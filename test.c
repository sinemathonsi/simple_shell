#include "shell.h"

int get_user_input(char **input);
/* prototype is here and not in .h file */

int main(void)
{
	char *input, **p = &input;

	printf("Enter text -> ");
	get_user_input(p);
	printf("%s\n", input);
	free(input);
	return (0);
}
