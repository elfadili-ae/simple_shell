#include "shell.h"
/**
 * _getline - get the command from the stream
 * @lptr: pointer to the buffer where to store string
 * @n: pointer to the size of the string
 * @strm: the stream
 * Return: number of characters read | -1 (failed)
 */
ssize_t _getline(char **lptr, size_t *n, FILE *strm)
{
	ssize_t val;

	if (isatty(STDIN_FILENO))
		_puts("$ ");
	val = getline(lptr, n, strm);
	if (val == 1)
		return (0);

	if (val == -1)
	{
		if (errno == EINVAL)
		{
			perror("Error:");
			exit(22);
		}
		else if (errno == ENOMEM)
		{
			perror("Error:");
			exit(12);
		}
	}
	return (val);
}

/**
 * _which - find the path of a filename
 * @cmd: filename to find it's path
 * Return: the file's path | NULL (not found)
 */
char *_which(char *cmd, char **envp)
{
	char *path, **pathToken, *buff = NULL;
	int i, size, l1 = _strlen(cmd), l2;

	path = _getenv("PATH=", envp);
	if (path == NULL)
		return (NULL);

	pathToken = _strtok(path + 5, ":", &size);
	for (i = 0; i < size - 1; i++)
	{
		l2 = _strlen(pathToken[i]);
		buff = malloc(sizeof(char) * (l1 + l2 + 2));
		if (buff == NULL)
		{
			freeSarray(pathToken, size);
			return (NULL);
		}

		_memcpy(buff, pathToken[i], l2);
		buff[_strlen(pathToken[i])] = '/';
		_memcpy(buff + _strlen(pathToken[i]) + 1, cmd, _strlen(cmd));
		buff[l1 + l2 + 1] = '\0';
		if (0 == access(buff, X_OK))
		{
			freeSarray(pathToken, size);
			return (buff);
		}
		free(buff);
	}
	freeSarray(pathToken, size);
	return (NULL);
}
/**
 *
 *
 */
void Notfound(char *argv, char *cmd, int c)
{

	_puts(argv);
	_puts(": ");
	fflush(stdout);
	print_int(c);
	_puts(": ");
	_puts(cmd);
	_puts(": not found\n");
}
