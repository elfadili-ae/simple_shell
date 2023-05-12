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
	fflush(stdout);
	if (val == 1)
		return (0);

	if (val == -1)
	{
		if (errno == EINVAL)
		{
			perror("Error: invalid argument");
			exit(22);
		}
		else if (errno == ENOMEM)
		{
			perror("Error: failed to allocate memory");
			exit(12);
		}
		else
			_puts("\n");
	}
	return (val);
}

/**
 * _which - find the path of a filename
 * @cmd: filename to find it's path
 * Return: the file's path | NULL (not found)
 */
char *_which(char *cmd)
{
	char *path, **pathToken, *buff = NULL;
	int i, l1 = _strlen(cmd), l2;

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	pathToken = _strtok(path, ":");

	for (i = 0; pathToken[i] != NULL; i++)
	{
		l2 = _strlen(pathToken[i]);
		buff = malloc(sizeof(char) * (l1 + l2 + 1));
		if (buff == NULL)
		{
			freeSarray(pathToken);
			return (NULL);
		}

		_memcpy(buff, pathToken[i], l2);
		buff[_strlen(pathToken[i])] = '/';
		_memcpy(buff + _strlen(pathToken[i]) + 1, cmd, _strlen(cmd));

		if (buff == NULL || buff[0] == '\0')
			return (NULL);
		else if (access(buff, X_OK) == 0)
		{
			freeSarray(pathToken);
			return (buff);
		}
		free(buff);
	}
	freeSarray(pathToken);
	return (NULL);
}
