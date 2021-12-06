#include "header.h"
/**
 * _cmdcpy - copies command to dest
 * @dest: where to copy to
 * @src: where to copy from
 * @cmd: command to copy
 * @amt: command length
 * @count: count command
 * Return: destination of copy
 */
char *_cmdcpy(char *dest, char *src, char *cmd, int amt, int count)
{
    int idx, vidx;

    for (idx = 0; (idx < amt) && (src[idx] != '\0'); idx++)
        dest[idx] = src[idx];
    dest[idx] = '/';
    idx++;
    for (vidx = 0; (vidx < count) && cmd[vidx] != '\0'; vidx++, idx++)
        dest[idx] = cmd[vidx];

    dest[idx] = '\0';

    return (dest);
}

/**
 * _cpyarg - copies arguments
 * @dest: destination to copy to
 * @src: where to copy from
 * @amt: length of arg
 * Return: destination pointer
 */
char *_cpyarg(char *dest, const char *src, int amt)
{
    int idx;

    for (idx = 0; idx < amt && src[idx] != '\0'; idx++)
        dest[idx] = src[idx];
    for ( ; idx < amt; idx++)
        dest[idx] = '\0';

    return (dest);
}
/**
 * _envlen - enviroment length
 * @str: dir name
 * Return: length
 */
unsigned int _envlen(const char *str)
{
    unsigned int idx;

    for (idx = 0; str[idx] != '\0'; ++idx)
        ;
    return (idx);
}

/**
 * _strcmp - compares two strings
 * @str1: first string to compare
 * @str2: string to compare to
 * Return: return with success
 */
int _strcmp(char *str1, char *str2)
{
    unsigned int idx = 0;

    for (idx = 0; str1[idx] != '\0'; ++idx)
    {
        if (str1[idx] != str2[idx])
            return (0);
    }

    return (1);
}
