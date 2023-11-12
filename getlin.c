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
	size_t count, op;

	mem = malloc(sizeof(line));

	op = open(line, O_RDONLY);

	if (read(op, mem, count) == -1)
		return (-1);

	return (*len);
}
