#include "main.h"
/**
 * main - print copy of text on the next line
 * Return: 0 if success, else -1
*/

int main(void)
{
	char *line = NULL;
	size_t count = 0;
	ssize_t read;

	while (1)
	{
		printf("$ ");
		read = getline(&line, &count, stdin);

		if (read == -1)
		{
			free(line);
			return (-1);
		}

		printf("%s", line);
	}
		free(line);
		return (0);
}
