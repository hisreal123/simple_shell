#include "main.h"

/**
 * fork_execute - function to make child and execute command
 * @loop: number of times the program has run
 * @cmd: pointer to the input command
 * @args: command array
 * @argv: pathname used to call shell
 * @envp: environment
 * Return: empty
*/

void fork_execute(int *loop, char *cmd, char **args, char *argv, char *envp)
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
			printf("%s: %d: %s: not found\n", argv, loop, args[0]);
			free(cmd);
			free(args);
			return;
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

void process_command(int *loop, char *cmd, char *argv, char *envp)
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
 * Return: empty
*/

void get_input(int *loop, char *argv, char *envp)
{
	size_t read, count;
	char *cmd = NULL;

	printf("($) ");

	read = getline(&cmd, &count, stdin);
	if (read == -1 || cmd == "")
	{
		free(cmd);
		return;
	}

	cmd[count - 1] = '\0';
	if (strcmp(cmd, "exit") == 0)
	{
		free(cmd);
		return;
	}

	process_command(loop, cmd, argv, envp);
}

/**
 * main - creating a new shell
 * @argc: argument count
 * @argv: argument vectors
 * @envp: environment vector
 * Return: 0 if it ends, -1 for error
*/

int main(int argc, char *argv[], char *envp)
{
	int loop = 0;

	for (;;loop++)
	{
		get_input(&loop, argv[0], envp);
	}
}
