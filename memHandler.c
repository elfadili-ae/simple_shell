#include "shell.h"

/**
 * _memcpy - copy memory
 * @src: memory area to copy
 * @dest: memory arae destination
 * @n: number of bytes to copy
 * Return: pointer to memory @dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}

/**
 * freeSarray -
 *
 *
 */
void freeSarray(char **Sarray, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		free(Sarray[i]);
		Sarray[i] = NULL;
	}
	free(Sarray);
}
