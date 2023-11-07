#include "main.h"

/**
 * main - function to execute a new program
 * @argc: argument count
 * @argv: argument variable strings
 * Return: empty
*/

void main(int argc, char *argv[])
{
	if (execve("./str", argv, NULL) == -1)
		printf("Execve error");
}
