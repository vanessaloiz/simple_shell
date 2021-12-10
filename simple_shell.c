#include "header.h"
/**
 * main - A simple shell to pass through commands.
 * @argc: Starting arguments.
 * @argv: Argument array
 * @env: environment array variable
 * Return: Exits with success or failure.
 */
int main(int argc, char **argv, char **env)
{
	char *buffer = NULL; /*buffer lo guarda todo */
	char **args; /* argumentos que esta pasando el usuario */
	size_t bufsize = 0; /* contiene lo que queremos de buffer */
	int input; /* recoge el resultado de getline */
	int check, idx = 0;
	(void)argc; /* undeclaring la variable argc */

	check = isatty(STDIN_FILENO);/* isatty verifica si esta en el terminal */
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

		args = _strtok(buffer); /* lista de argumentos tokenizada */
		_fork(args, argv, env, buffer, idx); /*call de func que ejecuta los cmd*/

		bufsize = 0;/* reset bufsize para empezar el loop */
		if (isatty(STDIN_FILENO))
			write(1, "SHELL@LOIZ-NARVAEZ:$ ", 21);
		buffer = NULL; /* limpiamos la memoria para reiniciar el loop en getline */
	}
	if (input == -1) /* el input falla */
		return (EXIT_FAILURE); /* salimos por error */
	return (EXIT_SUCCESS); /* si todo va bien salimos */
}
