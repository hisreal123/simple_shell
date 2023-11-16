#include "shell.h"

/**
 * nonin_commands - function to check for specific commands
 * @arg: check it for commands
 * @argv: command used to call shell
 * Return: 0 if no command executes, else
*/

int nonin_commands(char **arg, char **argv)
{
	int stat = 0, num = 0;
	char **env = environ, cwd[100];

	if (strcomp(arg[0], "exit") == 0)
	{
		stat = Ato1(arg[1]);
		if (stat != -1)
			exit(stat);
		else
			printf("%s: 1: exit: Illegal number %s", argv, arg[1]);
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
 * do_fork - func to fork commands
 * @arg: command to execute
 * @argv: command used to call shell
 * @envp: environment
 * Return: empty
*/

void do_fork(char **arg, char **argv, char **envp)
{
	if (strcomp(arg[0], "ls") == 0)
		arg[0] = "/bin/ls";

	if (execve(arg[0], arg, envp) == -1)
	{
		printf("%s: 1: %s: not found\n", argv, arg[0]);
		exit(0);
	}
}

/**
 * non_interactive - function to process non-in commands
 * @envp: passed environment
 * @argv: pathname used to call shell
 * Return: empty
*/

void non_interactive(char *argv, char **envp)
{
	char line[100], ch, *cmd, *args[1024] = {NULL}, *arg[1024] = {NULL};
	int index = 0, x = 0, y = 0;
	unsigned long int num = 0;

	while ((read(STDIN_FILENO, &ch, 1) == 1) && index < 99 && ch != '\n')
		line[index++] = ch;
	line[index] = '\0';
	if (strcmp(line, "exit") == 0)
		exit(0);
	cmd = strtok(line, " ");
	while (cmd && num < sizeof(args) / sizeof(args[0]) - 1)
	{
		args[num] = cmd;
		cmd = strtok(NULL, " ");
		num++;
	}

	if (args[0] == NULL)
		return;
	while (args[y] != NULL)
	{
		if (strcomp(args[y], ";") != 0)
		{
			arg[x] = args[y];
			x++, y++;
		}
		else if (strcomp(args[y], ";") == 0)
		{
			arg[x] = NULL;
			if (nonin_commands(arg, argv))
				do_fork(arg, argv, envp);
			x = 0, y++;
		}
	}
	arg[x] = NULL;
	if (nonin_commands(arg, argv) == 0)
		do_fork(arg, argv, envp);
	exit(0);
}