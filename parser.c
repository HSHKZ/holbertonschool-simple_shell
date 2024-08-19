#include "shell.h"

/**
 * reallocate_tokens - Reallocates the tokens array to fit more arguments
 * @tokens: The current array of tokens
 * @bufsize: Pointer to the current buffer size
 * @current_size: The current number of tokens
 * Return: The reallocated array of tokens
 */
char **reallocate_tokens(char **tokens, int *bufsize, int current_size)
{
	int j;
	char **new_tokens;

	*bufsize += BUFFER_SIZE;
	new_tokens = realloc(tokens, (*bufsize) * sizeof(char *));
	if (!new_tokens)
	{
		fprintf(stderr, "Allocation error\n");
		for (j = 0; j < current_size; j++)
			free(tokens[j]);
		free(tokens);
		exit(EXIT_FAILURE);
	}
	return (new_tokens);
}

/**
 * parse_command - Parse the command and its arguments
 * @command: The command entered by the user
 * Return: Array of arguments
 */
char **parse_command(char *command)
{
	int bufsize, i, j;
	char **tokens;
	char *token, *command_copy;

	bufsize = BUFFER_SIZE;
	i = 0;
	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}
	command_copy = strdup(command);
	if (!command_copy)
	{
		fprintf(stderr, "Allocation error\n");
		free(tokens);
		exit(EXIT_FAILURE);
	}
	token = strtok(command_copy, " ");
	while (token != NULL)
	{
		tokens[i] = strdup(token);
		if (!tokens[i])
		{
			fprintf(stderr, "Allocation error\n");
			for (j = 0; j < i; j++)
				free(tokens[j]);
			free(tokens);
			free(command_copy);
			exit(EXIT_FAILURE);
		}
		i++;
		if (i >= bufsize)
			tokens = reallocate_tokens(tokens, &bufsize, i);
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;
	free(command_copy);
	return (tokens);
}
