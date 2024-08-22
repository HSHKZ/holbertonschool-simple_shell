#include "shell.h"

/**
 * find_command_in_path - Search for the command in the directories of the PATH
 * @command: The command to search for
 * Return: The full path of the command if found, otherwise NULL
 */
char *find_command_in_path(char *command)
{
	char *path, *path_copy, *dir;
	char full_path[BUFFER_SIZE];
	struct stat st;

	path = _getenv("PATH", environ);
	if (!path)
		return (NULL);

	if (path == NULL)
	{
		perror("PATH");
		return (NULL);
	}

	path_copy = strdup(path);
	if (!path_copy)
	{
		perror("strdup");
		return (NULL);
	}

	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path_copy);
			return (strdup(full_path));
		}
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
