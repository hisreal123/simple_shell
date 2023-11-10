#include "shell.h"

/**
 * exit_status - function to exit with a status number
 * @value: value of exit status
 * Return: value of status
*/

int exit_status(char *value)
{
	int stat = 0;

	stat = atoi(value);

	return (stat);
}
