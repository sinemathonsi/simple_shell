#include "main.h"

int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i + 1); /* +1 bcoz idx start at 0 */
}

char *_strdup(char *src)
{
	int len, i;
	char *dest;

	len = _strlen(src);
	dest = malloc(len * sizeof(char));
	if (dest == NULL)
		return (NULL);

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

char *_strcpy(char *dest, char *src)
{
	int i;

	if (src == NULL)
		return (NULL);

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

char *_strcat(char *dest, char *to_cat)
{
	int i, j;

	if (dest == NULL)
		return (NULL);

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; to_cat[j] != '\0'; j++)
	{
		dest[i] = to_cat[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
