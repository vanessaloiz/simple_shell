#include "header.h"
/**
 * _strlen - Calculate the string length.
 * @buffer: The string variable.
 * Return: Length of string.
 */
unsigned int _strlen(char *buffer) /* Crea la funcion de strlen */
{
	unsigned int len = 0;

	while (buffer[len] != '\0')
		len++;
	return (len);
}

/**
 * _strtok - Create the tokenize input.
 * @str: Input string.
 * Return: Lists of strings.
 */
char **_strtok(char *str) /* Crea la funcion de string tokenize */
{
	char **args;
	char *token;
	int idx;
	unsigned int amt;

	str[_strlen(str) - 1] = '\0'; /* eliminamos el enter character*/
	amt = count_args(str);

	if (amt == 0)
		return (NULL);

	args = malloc((sizeof(char *)) * (amt + 1));
	if (args == NULL)
		return (NULL);

	token = strtok(str, " ");
	for (idx = 0; token != NULL; ++idx)
	{
		args[idx] = malloc(_strlen(token) + 1);
		if (args[idx] == NULL)
		{
			free_arr(args);
			return (NULL);
		}
		_strcpy(args[idx], token, _strlen(token) + 1);
		token = strtok(NULL, " ");
	}
	args[idx] = NULL;
	return (args);
}

/**
 * count_args - Counts the arguments of a given input.
 * @star: Input string of arguments.
 * Return: Number of arguments.
 */
unsigned int count_args(char *star)
{
	unsigned int arg = 0, check = 0, idx;

	for (idx = 0; star[idx] != '\0'; ++idx)
	{
		if (star[idx] != ' ')
			check = 1;
		if ((check && star[idx + 1] == ' ') || (check && star[idx + 1] == '\0'))
		{
			++arg;
			check = 0;
		}
	}
	return (arg);
}

/**
 * _strcpy - Copies a string to a pointer
 * @dest: Destination to copy to.
 * @src: To copy from
 * @amt: The amount to copy.
 * Return: Memory address to destination.
 */
char *_strcpy(char *dest, char *src, int amt)
{
	int idx;

	for (idx = 0; (idx < amt) && (src[idx] != '\0'); idx++)
		dest[idx] = src[idx];
	while (idx < amt)
	{
		dest[idx] = '\0';
		idx++;
	}
	return (dest);
}

/**
 * _atoi - Change to character from integer.
 * @arg: The argument to convert.
 * Return: The integer.
 */
int _atoi(char *arg)
{
	int check = 1, idx = 0, temp;

	if (arg[idx] == '-')
	{
		check = -1;
		idx++;
	}
	for (temp = 0; arg[idx] != '\0'; idx++)
		temp = temp * 10 + arg[idx] - '0';
	return (check * temp);
}
