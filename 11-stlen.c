#include "shell.h"

/**
 * stlen - custom strlen function
 * @str: string to check
 * Return: length of string
 */

int stlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}
