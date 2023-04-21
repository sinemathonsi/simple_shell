#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int main(void)
{
	int bufsize = BUFF_SIZE, read_ret;
	char *buffer;

	buffer = malloc(bufsize * sizeof(char));
	read_ret = read(STDIN_FILENO, &buffer, BUFF_SIZE);
	if (read_ret == 6)
		perror("Erro: ");

	printf("Got: \n");
	free(buffer);

	return (0);
}