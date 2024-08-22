#include <stdio.h>
#include <string.h>
#include <stddef.h>

/**
 * _getenv - Retrieves the value of an environment variable.
 * @name: The name of the environment variable to look for.
 *
 * Return: A pointer to the value of the environment variable,
 * or NULL if the environment variable is not found.
 */
char *_getenv(const char *name, char **environ)
{
	char *env;
	int i, len;

	if (name == NULL || environ == NULL)
		return (NULL);

	len = strlen(name);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			env = environ[i] + len + 1;
			return (env);
		}
	}

	return (NULL);
}
