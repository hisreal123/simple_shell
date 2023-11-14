#include "shell.h"

/**
 * fork_child - function to execute child process
 * Return: empty
*/

void fork_child(char **args, int *loop, char *cmd, char *argv, char **envp)
{
	pid_t child;
	int status = 0;

	child = fork();
	if (child == -1)
	{
		free(cmd);
		free(args);
		return;
	}

	else if (child > 0)
		wait(&status);

	else
	{
		if (strcomp(args[0], "env") == 0)
			get_env(envp);

		if (execve(args[0], args, envp) == -1)
		{
			printf("%s: %d: %s: no such file or "
					"directory\n", argv, *loop, args[0]);
			free(cmd);
			free(args);
			kill(getpid(), SIGTERM);
		}
	}
}
