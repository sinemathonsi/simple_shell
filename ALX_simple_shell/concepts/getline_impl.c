#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFF_SIZE 5

int main(void)
{
	int bufsize = BUFF_SIZE, read_ret, read_buf_idx = 0;
	char *buffer;

	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
		printf("buffer malloc failed\n");

	while (1)
	{
		read_ret = read(STDIN_FILENO, buffer + read_buf_idx, BUFF_SIZE);

		if (read_ret == 0 || buffer[read_buf_idx] == '\n')
			break;

		if (read_ret == BUFF_SIZE)
		{
			bufsize += BUFF_SIZE;
			read_buf_idx += read_ret;
			if (read_ret == 0 || buffer[read_buf_idx - 1] == '\n')
				break;
			buffer = realloc(buffer, bufsize * sizeof(char));
		}
	}
	printf("Read: %s\n", buffer);

	free(buffer);

	return (0);
}