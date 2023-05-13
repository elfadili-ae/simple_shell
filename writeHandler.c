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
/**
 *
 *
 *
 */
void print_int(int n)
{
	char buffer[20];
	int i = 0;
	int is_negative = n < 0;

	if (is_negative)
		n = -n;
	do {
		buffer[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (is_negative)
		buffer[i++] = '-';
	while (i > 0)
		write(1, &buffer[--i], 1);
}
