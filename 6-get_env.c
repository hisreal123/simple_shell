#include "shell.h"

/**
 * get_env - func to print enviroment
 * @envp: passed enviroment
 * Return: empty
*/

char **get_env(char **env)
{
	getenv(env);

	return (env);
}
