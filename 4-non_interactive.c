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
	int index = 0, loop = 1, ln = 0, status;
	long unsigned int num = 0;
	pid_t child;

	while ((read(STDIN_FILENO, &ch, 1) == 1) && ch != '\n' && index < 99)
			line[index++] = ch;
	line[index] = '\0';

	cmd = strtok(line, " ");
	while(cmd && num < sizeof(args) / sizeof(args[0]) - 1)
	{
		args[num] = cmd;
		cmd = strtok(NULL, " ");
	}

	for (;; loop++, ln++)
	{
		child = fork();
		if (child == -1)
			return;
		if (execve(args[ln], args, envp) == -1)
		{
			perror("execve failed");
			printf("%s: %d: %s: not found\n", argv, loop, cmd);
			kill(getpid(), SIGTERM);
		}
		else
			wait(&status);
		*args = *(args + 1);
	}
}
