#include "shell.h"

/**
 * process_command - function to process input commands
 * @loop: number of times the program has run
 * @cmd: command passed
 * @argv: pathname used to call shell
 * Return: 0 on success, -1 if forced exit
*/

void process_command(int *loop, char *cmd, char *argv)
{
	char *token = NULL, **args = NULL;
	int num = 0;

	args = (char **)malloc(sizeof(char *) * 1024);
	if (args == NULL)
	{
		free(args);
		free(cmd);
		return;
	}

	token = strtok(cmd, " ");
	while (token)
	{
		args[num] = token;
		token = strtok(NULL, " ");
		num++;
	}
	args[num] = NULL;

	fork_execute(loop, cmd, args, argv);
	free(args);
	free(cmd);
}
