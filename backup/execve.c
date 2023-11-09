#include "main.h"

/**
 * main - function to execute a new program
 * @argc: argument count
 * @argv: argument variable strings
 * Return: empty
*/

void main(int argc, char *argv[], char *envp[])
{
	if (argc < 2)
	{
		printf("Oops, Error\nFormat is: %s File-path"
				" extra-arguments\n", argv[0]);
		return;
	}

	printf("\nOpening %s...\n\n", argv[1]);

	if (execve(argv[1], &argv[1], envp) == -1)
		printf("Execve error\n");
}
