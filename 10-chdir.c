#include "shell.h"

/**
 * _chdir - function to change directory
 * @path: directory path
 * Return: empty
*/

void _chdir(const char *path)
{
	static char *last;
	char current[1024];

	getcwd(current, 1024);

	if (strcomp((char *)path, "-") == 0)
	{
		*path = *last;
		chdir(path);
		printf("%s\n", *path);
		*last = *current;
		return;
	}
	if (strcomp((char *)path, "") == 0)
		path = "$HOME";

	if (chdir(path) != 0)
	{
		printf("directory does not exist\n");
		return;
	}
	else
		chdir(path);
	*last = (char *)path;
}
