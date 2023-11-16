#include "shell.h"


/**
 * nonin_commands - function to check for specific commands
 * @arg: check it for commands
 * Return: 0 if no command executes, else
*/

int nonin_commands(char **arg)
{
	int stat = 0, num = 0;
	char **env = environ, cwd[100];

	if (strcomp(arg[0], "exit") == 0)
	{
		stat = atoi(arg[1]);
		exit(stat);
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
	if (strcomp(arg[0], "pwd") == 0)
	{
		getcwd(cwd, 100);
		printf("%s\n", cwd);
		return (3);
	}

	return (0);
}




/**
 * non_interactive - function to process non-in commands
 * @envp: passed environment
 * @argv: pathname used to call shell
 * Return: empty
*/

void non_interactive(char *argv, char **envp)
{
	char line[100], ch, *cmd, *args[100] = {NULL};
	int index = 0;
	unsigned long int num = 0;

	while ((read(STDIN_FILENO, &ch, 1) == 1) && index < 99 && ch != '\n')
		line[index++] = ch;
	line[index] = '\0';

	cmd = strtok(line, " ");
	while (cmd && num < sizeof(args) / sizeof(args[0]) - 1)
	{
		args[num] = cmd;
		cmd = strtok(NULL, " ");
		num++;
	}

	if (args[0] == NULL)
		return;
	if (strcomp(args[0], "ls") == 0)
		args[0] = "/bin/ls";
	if (nonin_commands(args) == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			printf("%s: 1: %s: not found\n", argv, args[0]);
			exit(0);
		}
	}
	exit(0);
}
