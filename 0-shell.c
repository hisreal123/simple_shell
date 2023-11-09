#include "shell.h"

/**
 * main - creating a new shell
 * @argc: argument count
 * @argv: argument vectors
 * @envp: environment vector
 * Return: 0 if it ends, -1 to stop
*/

int main(int argc, char *argv[], char *envp[])
{
	int check = 0, loop = 1, size = 100, index = 0;
	char *cmd, line[size], ch, char *args[] = {NULL};

	if (isatty(STDIN_FILENO))
	{
		for (;; loop++)
		{
			check = get_input(&loop, argv[0], envp);

			if (check == -1)
				return (-1);
		}
	}

	else (argc > 1)
	{
		while ((read(STDIN_FILENO, &ch, 1) == 1) && ch != '\n' && index < size - 1)
			line[index++] = ch;
		line[index] = '\0';

		cmd = line;
		args[0] = cmd;

		if (execve(cmd, args, envp) == -1)
		{
			perror("execve failed");
			printf("%s: 1: %s: not found", argv[argc - 1], cmd);
			return (-1);
		}
	}
	return (0);
}
