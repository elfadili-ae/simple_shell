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
	if (val == 1 && lptr[0][0] == '\n')
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
	struct stat st;
	char *path, **pathToken, *buff;
	int i = 0, l1 = _strlen(cmd), l2;

	if (stat(cmd, &st) != 0)
	{
		_puts("./hsh: ");
		_puts(cmd);
		perror("");
		return (NULL);
	}
	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	pathToken = _strtok(path, ":");

	while (pathToken[i] != NULL)
	{
		l2 = _strlen(pathToken[i]);
		buff = malloc(sizeof(char) * (l1 + l2 + 2));
		if (buff == NULL)
			return (NULL);

		_memcpy(buff, pathToken[i], l2);
		buff[_strlen(pathToken[i])] = '/';
		memcpy(buff + _strlen(pathToken[i]) + 1, cmd, _strlen(cmd));

		if (access(buff, X_OK) == 0)
			return (buff);

		free(buff);
		i++;
	}

	freeSarray(pathToken);
	free(path);

	return (NULL);
}
