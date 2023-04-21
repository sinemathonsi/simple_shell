#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sig_handler(int sig)
{
	return;
}

int main(void)
{
	signal(SIGINT, sig_handler);
	while (1)
	{
		printf("Hello worlds!\n");
	}
}