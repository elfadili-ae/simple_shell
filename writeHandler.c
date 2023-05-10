#include "shell.h"

/**
 * _puts - print a string followed by a line
 *@str: pointer to a string
 */
void _puts(char *s)
{
	write(1, s, _strlen(s));
	write(1, "\n", 1);
}

/**
* _strlen - calculate the length of a string
* this function uses recursion.
* @s: string
* @j: index
* Return: string length
*/
int _strlen(char *s, int j)
{
	if (s[j] != '\0')
		return (_strlen(s, ++j));
	return (j);
}
