#include "shell.h"

/**
 * openFile - open a file to read from
 * @data: data holder
 * Return: file descriptor
 */
int openFile(data_t *data)
{
	int fd_src;

	fd_src = open(data->argv[1], O_RDONLY);
	if (fd_src == -1)
	{
		_puts(data->progName, 2);
		_puts(": 0: cannot open ", 2);
		_puts(data->argv[1], 2);
		_puts(": No such file",2);
		_puts("\n", 2);
		exit(2);
	}
	return (fd_src);
}

/**
 * closeFile - close a file
 * @data: data holder
 * @fd: integer
 */
void closeFile(data_t *data, int fd)
{
	int stat;

	stat = close(fd);
	if (stat == -1)
	{
		_puts(data->progName, 2);
		_puts(": 0: cannot close ", 2);
		_puts(data->argv[1], 2);
		_puts("\n", 2);
		exit(EXIT_FAILURE);
	}
}
