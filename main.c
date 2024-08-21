#include "shell.h"

/**
 * main - Entry point
 * Return: 0 if success
 */
int main(void)
{
	int i;
	char *command;
	char **args;

	while (1)
	{
		prompt();
		command = read_input();

		if (!command)
		{
			break;
		}

		if (command[strlen(command) - 1] == '\n')
			command[strlen(command) - 1] = '\0';

		if (strcmp(command, "exit") == 0)
		{
			free(command);
			break;
		}

		args = parse_command(command);

		if (args[0] != NULL)
			execute_command(args);

		for (i = 0; args[i] != NULL; i++)
			free(args[i]);

		free(command);
		free(args);
	}

	return (0);
}
