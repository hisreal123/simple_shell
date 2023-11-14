#include "shell.h"

/**
 * commands - function to check for specific commands
 * @arg: check it for commands
 * Return: 0 if no command executes, else
*/

int commands(char **arg)
{
	int stat = 0;
	char **env, cwd;

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
		get_env(env);
		while(*env)
			printf("%s\n", *env);
		free(arg);
		return (2);
	}
	if (strcomp(args[0], "pwd") == 0)
	{
		getwd(cwd);
		printf("%s", cwd);
		return (3);
	}

	return (0);
}
