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
	int check = 0, loop = 1;
	char *cmd;
	char *args[] = {NULL};

	if (argc > 1)
	{
		cmd = argv[1];
		args[0] = cmd;
		if (execve(cmd, args, envp) == -1)
		{
			perror("execve failed");
			printf("%s: 1: %s: not found", argv[argc - 1], cmd);
		}
	}
	else
	{
			for (;; loop++)
		{
			check = get_input(&loop, argv[0], envp);

			if (check == -1)
				return (-1);
		}
	}

	return (0);
}
