#include "shell.h"

/**
 * process_command - function to process input commands
 * @loop: number of times the program has run
 * @cmd: pointer to the input command
 * @argv: pathname used to call shell
 * @envp: environment
 * Return: 0 on success, -1 if forced exit
*/

int process_command(int *loop, char *cmd, char *argv, char **envp)
{
	char *token = NULL, **args = NULL;
	int num = 0;

	args = (char **)malloc(sizeof(char *) * 100);
	if (args == NULL)
	{
		free(args);
		free(cmd);
		return (-1);
	}

	token = strtok(cmd, " ");
	while (token)
	{
		args[num] = token;
		token = strtok(NULL, " ");
		num++;
	}
	args[num] = NULL;

	if (fork_execute(loop, cmd, args, argv, envp) == -1)
		return (-1);
	
	return (0);
}
