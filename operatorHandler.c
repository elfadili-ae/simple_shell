#include "shell.h"

/**
 * opSep - separate the operator with spaces
 * @data: data holding the string
 * Return: new sperated line | if none return same string
 */
char *opSep(data_t *data)
{
	int i, j, len, newlen, opCount = 0, jmp;
	char op[] = {'|', '&', ';'}, *nline, *line = data->lineptr;

	len = strlen(line);
	for (j = 0; j < 3; j++)
		for (i = 0; line[i]; i++)
		{
			if (j < 2 && line[i] == op[j] && line[i + 1] == op[j])
				opCount++;
			if (j == 2 && line[i] == op[j])
				opCount++;
		}
	if (opCount == 0)
		return (line);
	newlen = len + opCount * 2;
	nline = malloc(sizeof(char) * (newlen + 1));

	for (i = 0, jmp = 0; i < len; i++)
	{
		if (line[i] == op[0] && line[i + 1] == op[0])
		{
			nline[i + (jmp++)] = ' ', nline[(i++) + jmp] = op[0];
			nline[(i++) + jmp] = op[0], nline[i + (jmp++)] = ' ';
		}
		if (line[i] == op[1] && line[i + 1] == op[1])
		{
			nline[i + (jmp++)] = ' ', nline[(i++) + jmp] = op[1];
			nline[(i++) + jmp] = op[1], nline[i + (jmp++)] = ' ';
		}

		if (line[i] == op[2])
		{
			nline[i + (jmp++)] = ' ', nline[(i++) + jmp] = op[2];
			nline[i + (jmp++)] = ' ';
		}
		nline[i + jmp] = line[i];
	}
	nline[i + jmp] = '\0';
	free(line);
	return (nline);
}

/**
 * commentHandler - handles the comment sign
 * @data: data holder
 */
void commentHandler(data_t *data)
{
	int i;

	for (i = 0; data->lineptr[i] != '\0'; i++)
	{
		if (data->lineptr[i] == '#')
		{
			data->lineptr[i] = '\0';
			return;
		}
	}
}
