#include "shell.h"

/**
 * change_directory - Changes the current working directory
 * @args: Array of arguments where args[1] is the target directory
 */
void change_directory(char **args)
{
	if (args[1] == NULL)
	{
		if (chdir(getenv("HOME")) != 0)
			perror("cd");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
		}
	}
}
