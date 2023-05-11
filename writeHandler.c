#include "shell.h"

/**
 * _puts - print a string followed by a line
 *@s: pointer to a string
 */
void _puts(char *s)
{
	write(1, s, _strlen(s));
}

/**
* _strlen - calculate the length of a string
* this function uses recursion.
* @s: string
* Return: string length
*/
int _strlen(char *s)
{
	int j = 0;

	for (j = 0; s[j] != '\0'; j++)
		;

	return (j);
}
