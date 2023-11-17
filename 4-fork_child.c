#include "shell.h"

/**
* fork_child - function to execute child process
* @arg: passed argument
* @args: main passed argument
* @cmd: command line array
* @loop: number of times program has run
* @argv: command used to call shell
* Return: empty
*/

void fork_child(char **arg, char **args, char *cmd, int *loop, char *argv)
{
	pid_t child;
	int status = 0;

	char **env = environ;

	if (strcomp(arg[0], "ls") == 0)
		arg[0] = "/bin/ls";

	/* clear function added */
	/* \033[H\033[2J is ANSI escape code */
	if (strcomp(arg[0], "clear") == 0)
	{
		write(STDOUT_FILENO, "\033[H\033[2J", 7);
		return;
	}


	if (args[0] == NULL)
	return;

	child = fork();
	if (child == -1)
		return;
	else if (child > 0)
		wait(&status);
	else
	{
		if (execve(arg[0], arg, env) == -1)
		{
			printf("%s: %d: %s: no such file or directory\n", argv, *loop, arg[0]);
			free(arg);
			free(args);
			free(cmd);
			kill(getpid(), SIGTERM);
		}
	}

}
