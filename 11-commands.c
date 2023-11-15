#include "shell.h"

/**
 * commands - function to check for specific commands
 * @arg: check it for commands
 * Return: 0 if no command executes, else
*/

int commands(char **arg)
{
	int stat = 0, num = 0;
	extern char **environ;
	char **env = environ, cwd[100];

	if (strcomp(arg[0], "exit") == 0)
	{
		stat = atoi(arg[1]);
		exit(stat);
	}
	if (strcomp(arg[0], "cd") == 0)
	{
		_chdir(arg[1]);
		free(arg);
		return (1);
	}
	if (strcomp(arg[0], "env") == 0)
	{
		while(env[num] != NULL)
		{
			printf("%s\n", env[num]);
			num++;
		}
		free(arg);
		return (2);
	}
	if (strcomp(arg[0], "pwd") == 0)
	{
		getcwd(cwd, sizeof(cwd));
		printf("%s\n", cwd);
		return (3);
	}

	return (0);
}
