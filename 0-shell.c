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
	int check = 0, loop = 1, index = 0;
	char *cmd, line[100], ch, *args[2] = {NULL};

	if (isatty(STDIN_FILENO))
	{
		for (;; loop++)
		{
			check = get_input(&loop, argv[0], envp);

			if (check != 0)
				exit(check);
		}
	}

	else
	{
		while ((read(STDIN_FILENO, &ch, 1) == 1) && ch != '\n' && index < 99)
			line[index++] = ch;
		line[index] = '\0';

		cmd = line;
		args[0] = cmd;

		if (execve(cmd, args, envp) == -1)
		{
			perror("execve failed");
			printf("%s: 1: %s: not found\n", argv[argc - 1], cmd);
			return (-1);
		}
	}
	return (0);
}
