#include "header.h"
/**
 * _fork - Creates a forked process
 * @args: List of arguments
 * @argv: starting arguments
 * @env: Environment variable list
 * @buffer: User input
 * @amt: While count
 */
void _fork(char **args, char **argv, char **env, char *buffer, int amt)
{
	int child_status;
	pid_t pid;
	struct stat fStat;

	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (args == NULL)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		else if (stat(args[0], &fStat) == 0)
			execve(args[0], args, NULL);
		else if (_strcmp("env", args[0]))
			env_exit(buffer, args, env);
		/*probar con strncmp para comparar los bytes necesarios.*/
		else if (_strcmp("exit", args[0]))
			exitcmd(buffer, args);
		else
			path_handle(args, buffer, env, argv, amt);
	}
	else
	{
		wait(&child_status);
		if (args == NULL)
			free_process(buffer, args);
		else if (_strcmp("exit", args[0]))
			exitcmd(buffer, args);
		else
			free_process(buffer, args);
	}
}

/**
 * exitcmd - Exits the terminal
 * @buffer: the input string to free
 * @args: array to free
 */
void exitcmd(char *buffer, char **args)
{
	int check = 0;

	 /* siempre y cuando args[1] no sea igual a nulo, (ls) solo seria args nulo.*/
	if (args[1] != NULL)
		check = _atoi(args[1]); /* atoi convierte de caracter a integers. */
	free(buffer);
	free_arr(args);
	exit(check);
}
