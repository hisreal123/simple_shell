#include "main.h"

/**
 * main - function to get ppid
 * Return: always 0
 */

int main(void)
{
	pid_t my_ppid;

	my_ppid = getppid();
	printf("%u\n", my_ppid);
	return (0);
}
