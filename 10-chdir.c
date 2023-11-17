#include "shell.h"

/**
 * _chdir - function to change directory
 * @path: directory path
 * Return: empty
*/

void _chdir(const char *path)
{
	char *last;
	char current[1024];

	getcwd(current, 1024);
	last = getenv("OLDPWD");

	if (!path || path[0] == '\0')
		path = getenv("HOME");
	if (strcmp(path, "-") == 0)
	{
		path = last;
		if (chdir(path) != 0)
		{
			perror("chdir failed");
			return;
		}
		printf("%s\n", path);
		setenv("OLDPWD", current, 1);
		getcwd(current, 1024);
		setenv("PWD", current, 1);
		return;
	}

	if (chdir(path) != 0)
	{
		perror("chdir failed");
		printf("directory does not exist\n");
		return;
	}

	setenv("OLDPWD", current, 1);
	getcwd(current, 1024);
	setenv("PWD", current, 1);
}
