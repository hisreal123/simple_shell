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
	int stat = 0, count = 0, num = 0;
	char **arg;

	arg = malloc(sizeof(char *) * 101);
	if (arg == NULL)
	{
		free(arg);
		free(args);
		free(cmd);
		return;
	}

	if (strcomp(args[0], "exit") == 0)
	{
		stat = atoi(args[1]);
		exit(stat);
	}

	if (strcomp(args[0], "ls") == 0)
		args[0] = "/bin/ls";
	if (strcomp(args[0], "pwd") == 0)
		args[0] = "/bin/pwd";
	if (strcomp(args[0], "cd") == 0)
	{
		chdir(args[1]);
		free(arg);
		return;
	}
	while (args[num] != NULL)
	{
		if (strcomp(args[num], ";") != 0)
		{
			arg[count] = strdup(args[num]);
			count++, num++;
		}
		else if (strcomp(args[num], ";") == 0)
		{
			arg[count] = NULL;
			fork_child(arg, loop, cmd, argv, envp);
			count = 0, num++;
		}
	}
	arg[count] = NULL;
	fork_child(arg, loop, cmd, argv, envp);
}
