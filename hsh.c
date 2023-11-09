#include "main.h"


/**
 * ls - function to
*/
/**
 * fork_execute - function to make child and execute command
 * @loop: number of times the program has run
 * @cmd: pointer to the input command
 * @args: command array
 * @argv: pathname used to call shell
 * @envp: environment
 * Return: empty
*/

void fork_execute(int *loop, char *cmd, char **args, char *argv, char **envp)
{
	pid_t child;
	int status;

	child = fork();
	if (child == -1)
	{
		free(cmd);
		free(args);
		return;
	}
	else if (child == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			printf("%s: %d: %s: not found\n", argv, *loop, args[0]);
			free(cmd);
			free(args);
		}
	}
	else
	{
		wait(&status);
	}
}


/**
 * process_command - function to process input commands
 * @loop: number of times the program has run
 * @cmd: pointer to the input command
 * @argv: pathname used to call shell
 * @envp: environment
 * Return: empty
*/

void process_command(int *loop, char *cmd, char *argv, char **envp)
{
	char *token = NULL, **args = NULL;
	int num = 0;

	args = (char **)malloc(sizeof(char *) * 100);
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

	fork_execute(loop, cmd, args, argv, envp);
}

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

	printf("($) ");

	read = getline(&cmd, &count, stdin);
	if (read == (size_t)-1)
	{
		free(cmd);
		return (0);
	}

	if (cmd[read - 1] == '\n')
		cmd[read - 1] = '\0';

	if (strcmp(cmd, "") == 0)
	{
		free(cmd);
		return (0);
	}

	if (strcmp(cmd, "exit") == 0)
	{
		free(cmd);
		return (-1);
	}

	process_command(loop, cmd, argv, envp);

	return (0);
}

/**
 * main - creating a new shell
 * @argc: argument count
 * @argv: argument vectors
 * @envp: environment vector
 * Return: 0 if it ends, -1 to stop
*/

int main(int argc, char *argv[], char *envp[])
{
	int check = 0, loop = 1;

	if (argc > 1)
	{
		if (execve(argv[argc], argv, envp) == -1)
			printf("%s: 1: %s: not found\n", argv[argc], *argv);
	}

	else
	{
			for (;; loop++)
		{
			check = get_input(&loop, argv[0], envp);

			if (check == -1)
				return (-1);
		}
	}

	return (0);
}
