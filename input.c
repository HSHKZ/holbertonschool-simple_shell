#include "shell.h"

/**
 * read_input - reads user input
 * Return: input string
 */
char *read_input(void)
{
	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, stdin) == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
