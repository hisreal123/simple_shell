#include "shell.h"

/**
 * _chdir - function to change directory
 * @path: directory path
 * Return: empty
*/

void _chdir(const char *path)
{
	static char last[1024];
	char current[1024];

	getcwd(current, 1024);

	if (strcomp((char *)path, "-") == 0)
	{
		chdir(last);
		getcwd(current, 1024);
		setenv("PWD", current, 1);
		printf("%s\n", current);
		strcpy(last, current);
		return;
	}
	if (path == NULL)
		path = "$HOME";

	if (chdir(path) != 0)
	{
		printf("directory does not exist\n");
		return;
	}
	strcpy(last, current);
	getcwd(current, 1024);
	setenv("PWD", current, 1);
}
