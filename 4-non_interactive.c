#include "shell.h"

/**
 * non_interactive - function to process non-in commands
 * @envp: passed environment
 * @argv: pathname used to call shell
 * Return: empty
*/

void non_interactive(char *argv, char **envp)
{
	char line[100], ch, *cmd, *args[2] = {NULL};
	int index = 0;

	while ((read(STDIN_FILENO, &ch, 1) == 1) && ch != '\n' && index < 99)
			line[index++] = ch;
	line[index] = '\0';
	printf("%s", line);

	cmd = line;
	args[0] = cmd;

	if (execve(cmd, args, envp) == -1)
	{
		perror("execve failed");
		printf("%s: 1: %s: not found\n", argv, cmd);
		return;
	}
}
