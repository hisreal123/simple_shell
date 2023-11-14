#include "shell.h"

/**
 * strtk - custom strtok function
 * @str: string
 * @delim: delimiter used to separate string
 * Return: cut string
*/

char *strtk(char *str, const char *delim)
{
	static char *oldtoken = NULL;
	char *token;

	if (str == NULL)
		str = oldtoken;

	while (strchr(delim, *str) && *str)
		str++;

	if (*str == NULL)
		return (NULL);

	*token = str;
	while (*token && !strchr(delim, *token))
		token++;

	if (*token)
	{
		*token = '\0';
		oldtoken = token + 1;
	}
	else
		token = NULL;

	return (str);
}
