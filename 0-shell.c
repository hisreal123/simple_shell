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

	if (argc > 1)
	{
		if (execve(argv[argc], argv, envp) == -1)
			printf("%s: 1: %s: not found\n", argv[argc], *argv);
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
