#include "shell.h"

int prompt(data_t *data, int *n, int stream);
char *_which(char *cmd, data_t *data);

/**
 * prompt - get the command from the stream
 * @lptr: pointer to the buffer where to store string
 * @n: pointer to the size of the string
 * @strm: the stream
 * Return: number of characters read | -1 (failed)
 */
int prompt(data_t *data, int *n, int stream)
{
	int val;

	if (isatty(stream))
		_puts("$ ", 1);

	val = _getLine(data, n, stream);

	if (!isatty(stream) && val == 0)
		exit(0);
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
char *_which(char *cmd, data_t *data)
{
	char *path, **pathToken, *buff = NULL;
	int i, size, l1 = _strlen(cmd), l2;

	path = _getenv("PATH=", data);
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
		_memcpy(buff + _strlen(pathToken[i]) + 1, cmd, l1);
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
void Notfound(data_t *data)
{

	_puts(data->progName, 2);
	_puts(": ", 2);
	fflush(stderr);
	print_int(data->cmdCounter, 2);
	_puts(": ", 2);
	_puts(data->cmd[0], 2);
	_puts(": not found\n", 2);
/*	errno = 127;*/

	if (!isatty(STDIN_FILENO))
		exit(127);
}
