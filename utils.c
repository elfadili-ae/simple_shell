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
	char *path, **path_token, buff[1024];

	if (stat(filename, &st) != 0)
	{
		_puts("./hsh: ");
		_puts(filename);
		perror("");
		return (NULL);
	}
	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	pathToken = _strtok(path, ":");

	while (pathToken[i] != NULL)
	{
		if (_strlen(pathToken[i]) + 1 + _strlen(cmd) + 1 > sizeof(buf))
			continue;

		_memcpy(buff, pathToken[i], _strlen(pathToken[i]));
		if (access(buf, X_OK) == 0)
		{
			printf("%s\n", buf);
			found = 1;
			break;
		}
		i++;
	}
	freeSarray(pathToken);
	free(path);

	return (NULL);
}
