#include "shell.h"

/**
 * get_env - func to print enviroment
 * @envp: passed enviroment
 * Return: empty
*/

void get_env(char **envp)
{
	while (*envp)
	{
		printf("%s\n", *envp);
		envp++;
	}

	kill(getpid(), SIGTERM);
}
