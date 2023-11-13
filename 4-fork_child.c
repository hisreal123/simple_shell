#include "shell.h"

/**
 * fork_child - function to execute child process
 * Return: empty
*/

void fork_child(char **args, int *loop, char *cmd, char *argv, char **envp)
{
	if (strcomp(args[0], "env") == 0)
			get_env(envp);
	else
	{
		if (strcomp(args[0], "ls") == 0)
			args[0] = "/bin/ls";
		if (strcomp(args[0], "pwd") == 0)
			args[0] = "/bin/pwd";
		if (execve(args[0], args, envp) == -1)
		{
			printf("%s: %d: %s: no such command, file or "
					"directory\n", argv, *loop, args[0]);
			free(cmd);
			free(args);
			kill(getpid(), SIGTERM);
		}
	}
}
