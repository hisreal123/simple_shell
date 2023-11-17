#include "shell.h"

/**
 * trim_space - function to remove pre/post string spaces
 * @str: string to trim
 * Return: trimmed string
 */

char *trim_space(char *str)
{
	int len = 0;
	char *end;

	while (str[len] != '\0')
		len++;
	while (isspace(*str))
		str++;

	if (*str == '\0')
		return (NULL);

	end = str + (len - 1);
	while (end > str && isspace(*end))
		end--;

	*(end + 1) = '\0';

	return (str);
}

/**
 * get_input - function to accept input commands
 * @loop: Number of times the program has run
 * @argv: pathname used to call shell
 * Return: empty, exit to quit program
*/

void get_input(int *loop, char *argv)
{
	size_t read, count;
	char *cmd = NULL;

	read = getlin(&cmd, &count, stdin);
	if (read == (size_t)-1 || read == 0)
	{
		free(cmd);
		return;
	}

	if (cmd[read - 1] == '\n')
		cmd[read - 1] = '\0';
	if (stlen(cmd) == 0)
	{
		free(cmd);
		return;
	}

	if (strcomp(cmd, "") == 0)
	{
		free(cmd);
		return;
	}

	if (strcomp(cmd, "exit") == 0)
	{
		free(cmd);
		exit(0);
	}
	if (strcomp(cmd, " ") == 0)
	{
		free(cmd);
		return;
	}
	process_command(loop, cmd, argv);
}
