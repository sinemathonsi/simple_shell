#include "main.h"

int main(int ac, char **av, char **env)
{
	char *input;
	int check;
	
	printf("Code to test getline\n");
	printf("($)");
	get_user_input(&input);
	printf("You wrote - %s\n\n", input);
	check = which_func(input, "98", env);
	if (check == 0)
	{
		return (0);
	}
	else
	{
		return (-1);
	}
	return (0);
}
