#include "shell.h"

/**
 * fork_execute - function to make child and execute command
 * @loop: number of times the program has run
 * @cmd: pointer to the input command
 * @args: command array
 * @argv: pathname used to call shell
 * @envp: environment
 * Return: empty
*/

void fork_execute(int *loop, char *cmd, char **args, char *argv, char **envp)
{
	pid_t child;
	int status;

	child = fork();
	if (child == -1)
	{
		free(cmd);
		free(args);
		return;
	}
	else if (child == 0)
	{
		if (strcmp(args[0], "ls") == 0)
			args[0] = "/bin/ls";
		if (strcmp(args[0], "pwd") == 0)
			args[0] = "/bin/pwd";
		if (execve(args[0], args, envp) == -1)
		{
			printf("%s: %d: %s: not found\n", argv, *loop, args[0]);
			free(cmd);
			free(args);
		}
	}
	else
	{
		wait(&status);
	}
}
