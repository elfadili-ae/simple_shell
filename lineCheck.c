#include "shell.h"

/**
 * isDir - checks if the path is a directory
 * @path: path to check
 * Return: 1 (directory) | 0 (not a directory)
 */
int isDir(char *path)
{
	struct stat st;
	int status = stat(path, &st);

	if (status == 0)
	{
		if (S_ISDIR(st.st_mode))
			return (1);
	}
	return (0);
}
/**
 * _isDigit - check if the string has only digits
 * @s: string to check
 * Return: 1 (digits) | 0 (otherwise)
 */
int _isDigit(char *s)
{
	int i = 0;

	for (; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}
