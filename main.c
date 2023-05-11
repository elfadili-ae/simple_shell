#include "shell.h"

/**
 *
 *
 *
 */
int main(int argc, char *argv[])
{
	if (isatty(STDIN_FILENO))
		interactive(argc, argv);
	else
		printf("non-interactive mode\n");
		/*nonInteractive(argc, argv);*/

	return (0);
}
