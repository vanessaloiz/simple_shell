#include "header.h"
/**
 * main - A simple shell to pass through commands.
 * @argc: Starting arguments.
 * @argv: Argument array
 * @env: Environment array variable
 * Return: Exits with success or failure.
 */
int main(int argc, char **argv, char **env)

{
	char *buffer; /*buffer lo guarda todo */
	char **args; /* argumentos que esta pasando el usuario */
	size_t bufsize; /* contiene lo que queremos de buffer */
	ssize_t input; /* recoge el resultado de getline */
	int check, idx;
	(void)argc; /* undeclaring la variable argc */

	check = isatty(STDIN_FILENO);
	if (check != '\0')
		write(1, "SHELL@LOIZ-NARVAEZ:$ ", 21);

	while ((input = getline(&buffer, &bufsize, stdin)))
	{
		if (input == EOF)
		{
			free(buffer);
			exit(0); /* Exit with success */
		}
		++idx;

		args = _strtok(buffer);
		_fork(args, argv, env, buffer, idx);

		bufsize = 0;
		if (isatty(STDOUT_FILENO))
			write(STDOUT_FILENO, "SHELL@LOIZ-NARVAEZ:$ ", 21);
		buffer = NULL;
	}
	if (input == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
