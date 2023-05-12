#include "shell.h"

/**
 * _strcmp - Compare two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 (equal) 1 (s1 greater) -1 (s2 greater)
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	if (s1[i] != s2[i])
		return (s1[i] - s2[i]);

	return (0);
}

/**
 * _strcmp - Compare n bytes from a string
 * @s1: first string
 * @s2: second string
 * Return: 0 (equal) 1 (s1 greater) -1 (s2 greater)
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
		{
			return (s1[i] - s2[i]);
		}
	}

	return 0;
}

/**
 * _strcpy - print every other character of a string
 *@src: pointer to a string to copy
 *@dest: pointer destination
 *Return: return dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	int l = _strlen(src);

	for (i = 0; i < l; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
