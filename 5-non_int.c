#include "shell.h"

/**
 * contd - check for more commands
 * @arg: comand
 * Return: 1 if a command executes, else 0
 */

int contd(char **arg)
{
	char cwd[100];

	if (strcomp(arg[0], "pwd") == 0)
	{
		getcwd(cwd, 100);
		printf("%s\n", cwd);
		return (1);
	}
	if (strcomp(arg[0], "setenv") == 0)
	{
		if (setenv(arg[1], arg[2], 1) != 0)
			perror("setenv() failed");

		return (1);
	}
	if (strcomp(arg[0], "unsetenv") == 0)
	{
		if (unsetenv(arg[1]) != 0)
			perror("unsetenv() failed");

		return (1);
	}

	return (0);
}

/**
 * nonin_commands - function to check for specific commands
 * @arg: check it for commands
 * @argv: command used to call shell
 * Return: 0 if no command executes, else
*/

int nonin_commands(char **arg, char *argv)
{
	int stat = 0, num = 0;
	char **env = environ;

	if (strcomp(arg[0], "exit") == 0)
	{
		stat = Ato1(arg[1]);
		if (stat != -1)
			exit(stat);
		else
		{
			printf("%s: 1: exit: Illegal number %s", argv, arg[1]);
			return (4);
		}
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

	if (contd(arg) == 0)
		return (0);
	else
		return (3);
}

/**
 * do_fork - func to fork commands
 * @arg: command to execute
 * @argv: command used to call shell
 * Return: empty
*/

void do_fork(char **arg, char *argv)
{
	int status;
	pid_t child;
	char **env = environ;

	if (strcomp(arg[0], "ls") == 0)
		arg[0] = "/bin/ls";
	if (strcomp(arg[0], "cat") == 0)
		arg[0] = "/bin/cat";

	child = fork();
	if (child == -1)
		return;
	else if (child > 0)
		wait(&status);
	else
	{
		if (execve(arg[0], arg, env) == -1)
		{
			printf("%s: 1: %s: not found\n", argv, arg[0]);
			kill(getpid(), SIGTERM);
		}
	}
}

/**
 * non_interactive - function to process non-in commands
 * @argv: pathname used to call shell
 * Return: empty
*/

void non_interactive(char *argv)
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
			if (nonin_commands(arg, argv) == 0)
				do_fork(arg, argv);
			x = 0, y++;
		}
	}
	arg[x] = NULL;
	if (nonin_commands(arg, argv) == 0)
		do_fork(arg, argv);
	exit(0);
}
