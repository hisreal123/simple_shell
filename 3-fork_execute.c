#include "shell.h"

/**
 * fork_execute - function to make child and execute command
 * @loop: number of times the program has run
 * @cmd: pointer to the input command
 * @args: command array
 * @argv: pathname used to call shell
 * @envp: environment
 * Return: 0 on success, -1 if foced exit
*/

void fork_execute(int *loop, char *cmd, char **args, char *argv, char **envp)
{
	pid_t child;
	int status, stat = 0;

	child = fork();
	if (child == -1)
	{
		free(cmd);
		free(args);
		return;
	}
	if (strcomp(args[0], "exit") == 0)
	{
		stat = atoi(args[1]);
		exit(stat);
	}
	else if (child == 0)
		fork_child(args, loop, cmd, argv, envp);
	else
		wait(&status);

}
