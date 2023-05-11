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
	int len = 0;

	while (s1[len] != '\0' || s2[len] != '\0')
		len++;
	while (i < len)
	{
		if (s1[i] != s2[i])
			break;
		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 * _strcmp - Compare n bytes from a string
 * @s1: first string
 * @s2: second string
 * Return: 0 (equal) 1 (s1 greater) -1 (s2 greater)
 */

int _strncmp(char *s1, char *s2, size_t n)
{
	int i = 0;
	int len1 = 0, len2 = 0;

	len1 = _strlen(s1);
	len2 = _strlen(s2);

	while (i < n)
	{
		if (s1[i] != s2[i])
			break;
		i++;
	}
	return (s1[i] - s2[i]);
}
