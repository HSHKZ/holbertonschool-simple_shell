#include "shell.h"

/**
 * change_directory - Changes the current working directory
 * @args: Array of arguments where args[1] is the target directory
 */
void change_directory(char **args)
{
	const char *home_dir;

	if (args[1] == NULL)
	{
		home_dir = getenv("HOME");
		if (home_dir == NULL)
		{
			fprintf(stderr, "cd: HOME not set\n");
			return;
		}

		if (chdir(home_dir) != 0)
			perror("cd");
	}
	else
	{
		if (chdir(args[1]) != 0)
			perror("cd");
	}
}
