#include "shell.h"

/**
 * main - creating a new shell
 * @argc: argument count
 * @argv: argument vectors
 * @envp: env
 * Return: 0 at the end
*/

int main(int argc, char *argv[], char *envp[])
{
	int check = 0, loop = 1;
	char cwd[100];

	if (isatty(STDIN_FILENO))
	{
		for (;; loop++)
		{
			getcwd(cwd, 100);
			printf("$Hell:%s# ", cwd);
			check = get_input(&loop, argv[0]);

			if (check == -1)
				return (0);
		}
	}

	else
	{
		non_interactive(argv[argc - 1], envp);
	}

	return (0);
}
