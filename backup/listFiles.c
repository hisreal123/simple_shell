#include <stdio.h>
#include <unistd.h>

/**
* main - list all files in the dir
* ls, cd, pwd, env
* Return: 0 if success, else -1 */

int listAll(void)
{
	char *lsPath = "/bin/ls";
	char *const args[] = {lsPath, "-l", NULL};
	char *const envp[] = {NULL};

	if (execve(lsPath, args, envp) == -1)
	{
		perror("execve");
		return (1);
	}

	return (0);
}
