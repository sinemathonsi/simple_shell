#include "main.h"

void chnge_w_dir(char *arg)
{
	char *buffer;
	size_t size;

	chdir(arg);

	buffer = getcwd(buffer, size);
	printf("curr dir: %s", buffer);
}
