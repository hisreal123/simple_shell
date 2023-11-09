#include "main.h"

/**
 * main - new shell program
 * Return: 0 on success, else -1
 */

int main(void)
{
	char *cmd = NULL, *token, **args = NULL;
	int  status, num = 0;
	size_t read, count = 0;
	pid_t child;

	printf("Opening shell...\n");
	sleep(1);
	for (;;)
	{
		printf("($$)");
		if (cmd != NULL)
			free(cmd);
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
			args = cmd;
			argv[0] = cmd;
			if (execve(cmd, argv, NULL) == -1)
			{
				printf("Execve error\n");
				free(cmd);
				free(args);
				return (-1);
			}
		}
		else
		{
			sleep(1);
			printf("Loading...\n");
			sleep(1);
			wait(&status);
			sleep(1);
		}
		num = 0;
	}

	return (0);
}
