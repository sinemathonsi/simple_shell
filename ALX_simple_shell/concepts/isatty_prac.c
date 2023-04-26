#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av)
{
	int tty;

	tty = isatty(STDIN_FILENO);
	printf("tty: %d\n", tty);

	return (0);
}