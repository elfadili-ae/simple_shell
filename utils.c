#include "shell.h"
/**
 * _getline - read line from the stream
 * @lptr: pointer to the buffer where to store string
 * @n: pointer to the size of the string
 * @strm: the stream
 * Return: number of characters read | -1 (failed)
 */
ssize_t _getline(char **lptr, size_t *n, FILE *strm)
{
	ssize_t val;

	_puts("$ ");
	val = getline(lptr, n, strm);
	if (val == -1)
	{
		if (errno == EINVAL)
		{
			perror("Error: invalid argument");
			exit (22);
		}
		else if (errno == ENOMEM)
		{
			perror("Error: failed to allocate memory");
			exit(12);
		}
	}
	return (val);
}
