#include "shell.h"

/**
 * fork_child - function to execute child process
 * @arg: passed argument
 * @loop: number of times program has run
 * @argv: command used to call shell
 * Return: empty
*/

void fork_child(char **arg, int *loop, char *argv)
{
	pid_t child;
	int status = 0;
	char **env = environ;

	if (strcomp(arg[0], "ls") == 0)
		arg[0] = "/bin/ls";

	child = fork();
	if (child == -1)
	{
		free(arg);
		return;
	}

	else if (child > 0)
		wait(&status);

	else
	{
		if (execve(arg[0], arg, env) == -1)
		{
			printf("%s: %d: %s: no such file or directory\n", argv, *loop, arg[0]);
			free(arg);
			kill(getpid(), SIGTERM);
		}
	}
}
