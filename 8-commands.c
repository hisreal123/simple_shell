#include "shell.h"

/**
 * commands - function to check for specific commands
 * @arg: check it for commands
 * @args: main command argument
 * @cmd: command line array
 * @loop: number of times the program has run
 * @argv: command used to call shell
 * Return: 0 if no command executes, else
*/

int commands(char **arg, char **args, char *cmd, int *loop, char **argv)
{
	int stat = 0, num = 0;
	char **env = environ, cwd[100];

	if (strcomp(arg[0], "exit") == 0)
	{
		stat = Ato1(arg[1]);
		if (stat != -1)
		{
			free(arg);
			free(args);
			free(cmd);
			exit(stat);
		}
		else
		printf("%s: %d: exit: Illegal number %s", argv, *loop, arg[1]);
	}
	if (strcomp(arg[0], "cd") == 0)
	{
		_chdir(arg[1]);
		return (1);
	}
	if (strcomp(arg[0], "env") == 0)
	{
		while (env[num] != NULL)
		{
			printf("%s\n", env[num]);
			num++;
		}
		return (2);
	}
	if (strcomp(arg[0], "pwd") == 0)
	{
		getcwd(cwd, 100);
		printf("%s\n", cwd);
		return (3);
	}
	return (0);
}
