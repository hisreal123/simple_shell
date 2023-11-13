#include "shell.h"

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
	long unsigned int num = 0;

	while ((read(STDIN_FILENO, &ch, 1) == 1) && ch != '\n' && index < 99)
			line[index++] = ch;
	line[index] = '\0';

	cmd = strtok(line, " ");
	while(cmd && num < sizeof(args) / sizeof(args[0]) - 1)
	{
		args[num] = cmd;
		cmd = strtok(NULL, " ");
	}

	if (execve(args[0], args, envp) == -1)
	{
		perror("execve failed");
		printf("%s: 1: %s: not found\n", argv, args[0]);
		kill(getpid(), SIGTERM);
	}
}
