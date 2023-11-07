#include "main.h"

/**
 * main - fork an example
 * Return: 0 on success
*/

int main(void)
{
	pid_t my_pid;
	pid_t child_pid;

	printf("Before forking");

	child_pid = fork();
	if (child_pid == -1)
	{
		printf("Error with forking\n");
		return (-1);
	}

	printf("After forking\n");
	my_pid = getpid();
	if (child_pid == 0)
		printf("Child fork has PID of %u\n", my_pid);
	else
		printf("Parent fork has PID of %u\n", my_pid);
}
