#include "main.h"

unsigned int is_delim(char c, char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

char *my_strtok(char *src, char *delim)
{
	static char *backup_string;
	char *ret;

	if (!src)
		src = backup_string;

	if (!src)
		return (NULL);

	while (1)
	{
		if (is_delim(*src, delim))
		{
			src++;
			continue;
		}

		if (*src == '\0')
			return (NULL);
		break;
	}

	ret = src;
	while (1)
	{
		if (*src == '\0')
		{
			backup_string = src;
			return (ret);
		}

		if (is_delim(*src, delim))
		{
			*src = '\0';
			backup_string = src + 1;
			return (ret);
		}
		src++;
	}
}
