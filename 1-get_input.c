#include "shell.h"

/**
 * get_input - function to accept input commands
 * @loop: Number of times the program has run
 * @argv: pathname used to call shell
 * @envp: environment
 * Return: 0 on success, -1 to end
*/

int get_input(int *loop, char *argv, char **envp)
{
	size_t read, count;
	char *cmd = NULL;

	printf("($Hell) ");

	read = getline(&cmd, &count, stdin);
	if (read == (size_t)-1)
	{
		free(cmd);
		return (0);
	}

	if (cmd[read - 1] == '\n')
		cmd[read - 1] = '\0';

	if (strcomp(cmd, "") == 0)
	{
		free(cmd);
		return (0);
	}

	if (strcomp(cmd, "exit") == 0)
	{
		free(cmd);
		return (-1);
	}

	if (strcomp((cmd + 0), "exit") == 0)
		return(exit_status((cmd + 1)));

	process_command(loop, cmd, argv, envp);
	return (0);
}
