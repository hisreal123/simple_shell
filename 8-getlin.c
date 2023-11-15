#include "shell.h"

/**
 * getlin - custom getline function
 * @mem: buffer to store line in
 * @len: length of line
 * @line: line to be read
 * Return: length of fline
 */

size_t getlin(char **mem, size_t *len, FILE *line)
{
	size_t count = 0;
	int fed = 0;

	if (*mem == NULL || *len == 0)
	{
		*len = 100;
		*mem = (char *)malloc(*len);
		if (*mem == NULL)
		{
			perror("Memory allocation error");
			return (-1);
		}
	}

	while ((fed = getc(line)) != EOF)
	{
		if (count < *len - 1)
		{
			*len *= 2;
			*mem = (char *)realloc(*mem, *len);
			if (*mem == NULL)
			{
				perror("Memory allocation error");
				return (-1);
			}
		}
		(*mem)[count++] = (char)fed;

		if (fed == '\n')
			break;
	}

	(*mem)[count] = '\0';
	if (count == 0 && fed == EOF)
		return (-1);

	return (count);
}
