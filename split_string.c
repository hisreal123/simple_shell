#include "main.h"
/**
 * split_string - func to split a string
 * string: string to be split
 * delim: delimiter to use for interruptions
 * Return: array of strings
*/

char *split_string(char *string, const char *delim)
{
	char *token;

	token = strtk(string, delim);
	return (token);
}

int main(void)
{
	char str[] = "This is a test string";
	char *split;

	printf("%s\n", str);
	split = split_string(str, " ");
	while (split)
	{
		printf("%s\n", split);
		split = split_string(NULL, " ");
	}

	return (0);
}
