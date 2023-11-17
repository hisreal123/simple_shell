#include "shell.h"

/**
 * main - creating a new shell
 * @argc: argument count
 * @argv: argument vectors
 * Return: 0 at the end
*/

int main(int argc, char *argv[])
{
	int loop = 1;
	char cwd[1024];

	if (isatty(STDIN_FILENO))
	{
		for (;; loop++)
		{
			getcwd(cwd, 1024);
			printf("$Hell:%s# ", cwd);
			get_input(&loop, argv[0]);
		}
	}

	else
	{
		non_interactive(argv[argc - 1]);
	}

	return (0);
}
