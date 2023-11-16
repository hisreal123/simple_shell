#include "shell.h"

/**
 * strdup_ - custom strdup function
 * @str: string to duplicate
 * Return: duplicated string, else null
*/

char *strdup_(const char *str)
{
	int x = 0, num = 0;
	char *nstr;

	if (str == NULL)
		return (NULL);

	while (str[num] != '\0')
		num++;

	nstr = malloc(sizeof(char *) * num + 1);
	if (nstr == NULL)
		return (NULL);

	for (; x < num; x++)
		nstr[x] = str[x];
	nstr[x] = '\0';

	return (nstr);
}

/**
 * fork_execute - function to make child and execute command
 * @loop: number of times the program has run
 * @cmd: command line array
 * @args: command array
 * @argv: pathname used to call shell
 * Return: 0 on success, -1 if foced exit
*/

void fork_execute(int *loop, char *cmd, char **args, char *argv)
{
	int count = 0, num = 0;
	char **arg;

	arg = malloc(sizeof(char *) * 1024);
	if (arg == NULL)
	{
		free(arg);
		return;
	}

	while (args[num] != NULL)
	{
		if (strcomp(args[num], ";") != 0)
		{
			arg[count] = args[num];
			count++, num++;
		}
		else if (strcomp(args[num], ";") == 0)
		{
			arg[count] = NULL;
			if (commands(arg, args, cmd, loop, argv) == 0)
				fork_child(arg, args, cmd, loop, argv);
			count = 0, num++;
		}
	}
	arg[count] = NULL;
	if (commands(arg, args, cmd, loop, argv) == 0)
		fork_child(arg, args, cmd, loop, argv);
	free(arg);
}
