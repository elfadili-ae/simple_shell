#include "shell.h"

/**
 * intercative -
 *
 *
 */
void interactive(void)
{
	char *buffer;
	size_t size;
	ssize_t line;

	while (1)
	{
		write(1, "$ ", 2);
		line = getline(&buffer, &size, stdin);
		if (line == -1)
		{
			_puts("Failed\n");
			continue;
		}
		if (_strcmp(buffer, EXIT) == 0)
			break;

		_puts(buffer);
	}
	printf("hi there we are here\n");
}

/**
 *
 *
 *
 */
void nonInteractive(void)
{

}
