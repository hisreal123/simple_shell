#include "shell.h"

/**
 * Ato1 - custom atoi function
 * @str: string to be converted
 * Return: length of string, else -1
*/

int Ato1(char *str)
{
	int st = 0;

	if (*str == '-')
		return (-1);

	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			st = st * 10 + (*str - '0');
		else
			return (-1);
		str++;
	}

	return (st);
}
