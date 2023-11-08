#include "main.h"

/**
 * main - new shell program
 * Return: 0 on success, else -1
 */

int main(void)
{
	char *cmd = NULL;
	char *argv[] = {NULL};
	int  status;
	size_t read, count = 0;
	pid_t child;

	cmd = malloc(sizeof(char) * 100);
	if (cmd == NULL)
	{
		printf("Memory allocation Error\n");
		return (-1);
	}

	for (;;)
	{
		printf("($)");

		read = getline(&cmd, &count, stdin);
		if (read == -1)
		{
			free(cmd);
			return (-1);
		}
		cmd[read - 1] = '\0';
		if (cmd[0] == "exit")
			break;

		child = fork();
		if (child == -1)
			printf("Oops, forking error");
		else if (child == 0)
		{
			argv[0] = cmd;
			if (execve(cmd, argv, NULL) == -1)
			{
				printf("Execve error\n");
				return (-1);
			}
		}
		else
			wait(&status);
	}

	free(cmd);
	return (0);
}
