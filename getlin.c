#include "shell.h"

/**
 * getlin - custom getline function
 * @mem: buffer to store line in
 * @len: length of line
 * line: line to be read
 * Return: length of fline
 */

size_t getlin(char **mem, size_t *len, FILE *line)
{
	size_t count = 0;
	int fed = 0;

	if (*line == NULL || *len == 0)
	{
		*len = 100;
		*line = (char *)malloc(*len);
		if (*line == NULL)
			return (-1);
	}

	while ((fed = getc(line)) != EOF)
	{
		if (count < *len - 1)
		{
			*len *= 2;
			*line = (char *)realloc(*line, *len);
			if (*line == NULL)
				return (-1);
		}
	(*line)[i++] = (char)fed;

	if(fed == '\n')
		break;
	}

	(*line)[count] = '\0';
	if (count == 0 && fed == EOF)
		return (-1);

	return (count);
}
