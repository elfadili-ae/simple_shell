#include "shell.h"

/**
 *
 *
 *
 */
char **_strtok(char *str, const char *delim)
{
	char **arrtok;
	int i, j = 0, k, ctok, toklen;

	if (str == NULL || delim == NULL || str[0] == '\0')
		return (NULL);

	ctok = countTok(str, delim);
	arrtok = malloc(sizeof(char*) * (ctok + 2));
	if (arrtok == NULL)
		return (NULL);

	for (i = 0; i < ctok; i++)
	{
		while (str[j] == *delim)
			j++;

		toklen = tokLen(str, delim, j);
		arrtok[i] = malloc(sizeof(char) * (toklen + 1));
		if (arrtok[i] == NULL)
		{
			free(arrtok);
			return (NULL);
		}

		for (k = 0; k < toklen; k++)
		{
			arrtok[i][k] = str[j];
			j++;
		}
		arrtok[i][k] = '\0';
	}
	arrtok[i] = NULL;
	arrtok[i + 1] = NULL;
	return (arrtok);
}

/**
 * countTok - counts number of tokens
 * @str: tokens holder
 * @delim: delimiter
 * Return: number of tokens
 */
int countTok(char *str, const char *delim)
{
	int i, count = 0;

	if (str == NULL || delim == NULL)
		return (0);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == *delim)
			count++;
	}

	return (++count);
}
/**
 * tokLen - calculate the length of the token
 * @str:
 *
 *
 */
int tokLen(char *str, const char *delim, int index)
{
	int len;

	for (len = 0; str[index + len] != '\n'; len++)
	{
		if (str[index + len] == *delim)
			break;
	}
	return (len);
}
