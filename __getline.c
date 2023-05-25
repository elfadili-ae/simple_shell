#include "shell.h"
/**
 * _getLine - read line from the stream
 * @data: data holder
 * @size: size of the line
 * @stream: source to read from
 * Return: character's read | -1 (failed)
 */
int _getLine(data_t *data, int *size, int stream)
{
	int i = 0, rd = 0;
	char c = '\0', *tmp = NULL;

	if (data->lineptr == NULL)
		*size = 0;
	for (i = 0; c != EOF && c != '\n'; i++)
	{
		if (i >= *size)
		{
			*size += BUFFSIZE;
			tmp = _realloc(data->lineptr, *size - BUFFSIZE, *size);
			if (tmp == NULL)
			{
				free(data->lineptr), data->lineptr = NULL;
				return (-1);
			} data->lineptr = tmp;
		}
		fflush(stdout);
		rd = read(stream, &c, 1);
		if (rd == 0)
		{
			if (i == 0)
			{
				freeSarray(data->envp, 64), freeSarray(data->alias, 24);
				free(data->lineptr);
				exit(errno);
			} break;
		}
		if (rd == -1)
		{
			free(data->lineptr), data->lineptr = NULL;
			return (-1);
		}
		if (c == '\n')
		{
			data->lineptr[(i++)] = c;
			break;
		} data->lineptr[i] = c;
	} data->lineptr[i] = '\0';
	return (i);
}
