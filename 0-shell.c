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
		non_interactive(envp);
	return (0);
}
