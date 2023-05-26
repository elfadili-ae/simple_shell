#include "shell.h"

/**
 * checkOnlySpaces - check if only spaces
 * @line: data holder
 * Return: 1 (not spaces) | 0 (only spaces)
 */
int checkOnlySpaces(char *line)
{
	int i = 0;

	while (line[i])
	{
		if (line[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

/**
 * rev_string - reverse a string
 *@s: pointer to a string
 */
void rev_string(char *s)
{
	int i;
	char tmp;
	int l = _strlen(s);

	for (i = 0; i < l / 2; i++)
	{
		tmp = s[l - i - 1];
		s[l - i - 1] = s[i];
		s[i] = tmp;
	}
}
