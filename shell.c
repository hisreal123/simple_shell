#include "main.h"

/**
 * main - new shell program
 * Return: 0 on success, else -1
 */

int main(void)
{
	char *cmd = NULL;
	int  status;
	size_t read, count = 0;
	pid_t child;

	for (;;)
	{
		printf("($)");

		read = getline(&cmd, &count, stdin);
		if (read = -1)
		{
			free(cmd);
			return (-1);
		}

		child = fork();
		if (child == -1)
			printf("Oops, forking error");
		else if (child == 0)
		{
			if (execve(cmd, &cmd, NULL) == -1)
			{
				printf("Execve error\n");
				return (-1);
			}
		}
		else
			wait(&status);
	}

	return (0);
}
