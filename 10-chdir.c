#include "shell.h"

/**
* _chdir - function to change directory
* @path: directory path
* Return: empty
*/


void _chdir(const char *path)
{
	static char *last;

	char current[100];

	getcwd(current, sizeof(current));

	if (!path || path[0] == '\0')
		path = getenv("HOME");

	if (strcmp(path, "-") == 0)
	{
		path = last;
		if (chdir(path) != 0)
		{
			perror("chdir");
			return;
		}
		printf("%s\n", path);

		setenv("PWD", current, 1);

		free(last);
		last = strdup(current);
		return;
	}

	if (chdir(path) != 0)
	{
		perror("chdir");
		return;
	}


	free(last);
	last = strdup(current);

	setenv("PWD", getcwd(current, sizeof(current)), 1);
}


