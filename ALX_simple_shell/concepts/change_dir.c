#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *buffer, *input = "/home";
	size_t n = 200;
	int chdir_ret;

	buffer = getcwd(buffer, n);
	printf("buffer[%s]\n", buffer);

	chdir_ret = chdir(input);
	if (chdir_ret == -1)
		perror("Erro");

	buffer = getcwd(buffer, n);
	printf("buffer[%s]\n", buffer);

	return (0);
}