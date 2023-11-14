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

void fork_execute(int *loop, char **args, char *argv)
{
	int stat = 0, count = 0, num = 0;
	char **arg;

	arg = malloc(sizeof(char *) * 101);
	if (arg == NULL)
	{
		free(arg);
		free(args);
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
			if (commands(arg) == 0)
				fork_child(arg, loop, cmd, argv);
			count = 0, num++;
		}
	}
	arg[count] = NULL;
	if (commands(arg) == 0)
		fork_child(arg, loop, argv);
}
