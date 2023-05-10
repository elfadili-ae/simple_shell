#include <stdio.h>
#include <string.h>
#include <signal.h>

int main()
{
	char *buffer;
	size_t size;
	ssize_t line;

	while (1)
	{
		printf("$ ");
		line = getline(&buffer, &size, stdin);
		if (line == -1)
		{
			printf("Failed\n");
			continue;
		}
		if (strcmp(buffer, "exit\n") == 0)
			break;
		printf("%s", buffer);
	}
		return (0);
}
