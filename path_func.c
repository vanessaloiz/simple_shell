#include "header.h"
/**
 * path_handle - Handles the path variable
 * @amt: amount string
 * @args: arguments
 * @argv: starting arguments
 * @buffer: input string
 * @env: environment variables
 */
void path_handle(char **args, char *buffer, char **env, char **argv, int amt)
{
	struct stat Stat;
	char **dir;
	int idx;

	dir = env_arr(args[0], env);

	for (idx = 0; dir[idx] != NULL; ++idx)
	{
		if (stat(dir[idx], &Stat) == 0)
			execve(dir[idx], args, NULL);
	}

	_error(argv, args[0], amt);

	free(buffer);
	free_arr(args);
	free_arr(dir);
	exit(EXIT_SUCCESS);
}

/**
 * dir_check - check for command in directories
 * @path: path to check
 * Return: the directory
 */
unsigned int dir_check(char *path)
{
	unsigned int idx, check, dir;

	for (idx = 0, dir = 0; path[idx] != '\0'; ++idx)
	{
		if (path[idx] != ':')
			check = 1;

		if ((check && path[idx + 1] == ':') || (check && path[idx + 1] == '\0'))
		{
			check = 0;
			++dir;
		}
	}
	return (dir);
}
