#include "header.h"
/**
 * env_exit - exits with environment command
 * @buffer: input string
 * @args: arguments of input
 * @env: enviromental arguments
 */
void env_exit(char *buffer, char **args, char **env)
{
    free(buffer);
    free_arr(args);
    env_cmd(env);
    exit(EXIT_SUCCESS);
}

/**
 * _error - Prints error messages.
 * @argv: List of init arguments.
 * @arg: list of arguments
 * @amt: ammount
 *
 */
void _error(char **argv, char *arg, int amt)
{
    int temp, len, cpy = amt;
    char err;

    write(STDERR_FILENO, argv[0], _strlen(argv[0]));
    write(STDERR_FILENO, ": ", 2);

    temp = 1;
    for (len = 1; cpy >= 10; ++len)
    {
        cpy /= 10;
        temp *= 10;
    }

    while (len > 1)
    {
        if ((amt / temp) < 10)
        {
            err = (amt / temp + '0');
            write(STDERR_FILENO, &err, 1);
        }
        else
        {
            err = ((amt / temp) % 10 + '0');
            write(STDERR_FILENO, &err, 1);
        }
        --len;
        temp /= 10;
    }

    err = amt % 10 + '0';
    write(STDERR_FILENO, &err, 1);
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, arg, _strlen(arg));
    write(STDERR_FILENO, ": command not found\n", 20);
}

/**
 * env_arr - tokenizes environment array
 * @cmd: command to check
 * @envmnt: environment variable
 * Return: array of direcotries
 */
char **env_arr(char *cmd, char **envmnt)
{
    char **dir_list;
    char *path, *dir;
    unsigned int len, idx;

    path = _env("PATH", envmnt);
    len = dir_check(path);
    dir_list = malloc(sizeof(char *) * (len + 1));
    if (dir_list == NULL)
        return (NULL);

    dir = strtok(path, ":");
    for (idx = 0; dir != NULL; ++idx)
    {
        dir_list[idx] = malloc(sizeof(char) * (_strlen(dir) + _strlen(cmd) + 2));
        if (dir_list[idx] == NULL)
        {
            free_arr(dir_list);
            return (NULL);
        }
        _cmdcpy(dir_list[idx], dir, cmd, _strlen(dir), _strlen(cmd));
        dir = strtok(NULL, ":");
    }
    dir_list[idx] = NULL;

    return (dir_list);
}

/**
 * _env - gets the environment variable
 * @str: string to check
 * @envmnt: environment variable
 * Return: returns env list
 */
char *_env(const char *str, char **envmnt)
{
    char *env;
    char *cpystr;
    unsigned int idx, len;

    len = _envlen(str);
    cpystr = malloc((sizeof(char) * len) + 1);
    if (cpystr == NULL)
        return (NULL);

    _cpyarg(cpystr, str, len);

    idx = 0;
    env = strtok(envmnt[idx], "=");
    while (envmnt[idx])
    {
        if (_strcmp(env, cpystr))
        {
            env = strtok(NULL, "\n");
            free(cpystr);
            return (env);
        }
        ++idx;
        env = strtok(envmnt[idx], "=");
    }

    free(cpystr);
    return (NULL);
}

/**
 * env_cmd - environment command
 * @envmnt:environment variable
 */
void env_cmd(char **envmnt)
{
    unsigned int idx, len;

    idx = 0;
    for (idx = 0; envmnt[idx] != NULL; ++idx)
    {
        len = _strlen(envmnt[idx]);
        write(STDOUT_FILENO, envmnt[idx], len);
        write(STDOUT_FILENO, "\n", 1);
    }
}
