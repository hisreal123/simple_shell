#include "shell.h"

/**
 * more - check for more commands
 * @arg: comand
 * Return: 1 if a command executes, else 0
 */

int more(char **arg)
{
	char cwd[100];

	if (strcomp(arg[0], "pwd") == 0)
	{
		getcwd(cwd, 100);
		printf("%s\n", cwd);
		return (1);
	}
	if (strcomp(arg[0], "setenv") == 0)
	{
		if (setenv(arg[1], arg[2], 1) != 0)
			perror("setenv() failed");

		return (1);
	}
	if (strcomp(arg[0], "unsetenv") == 0)
	{
		if (unsetenv(arg[1]) != 0)
			perror("unsetenv() failed");

		return (1);
	}

	return (0);
}

/**
 * commands - function to check for specific commands
 * @arg: check it for commands
 * @args: main command argument
 * @cmd: command line array
 * @loop: number of times the program has run
 * @argv: command used to call shell
 * Return: 0 if no command executes, else
*/

int commands(char **arg, char **args, char *cmd, int *loop, char *argv)
{
	int stat = 0, num = 0;
	char **env = environ;

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
		{
			printf("%s: %d: exit: Illegal number %s\n", argv, *loop, arg[1]);
			return (4);
		}
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
	if (more(arg) == 0)
		return (0);
	else
		return (3);
}
