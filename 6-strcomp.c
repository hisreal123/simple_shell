#include "shell.h"

/**
 * strcomp - custom strcmp function
 * @s1: main string
 * @s2: string to be compared to
 * Return: 0 if equal, -ve if less, +ve if greater
 */

int strcomp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}
