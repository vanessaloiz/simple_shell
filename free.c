#include "header.h"

/**
 * free_arr - Frees arrays.
 * @arr: The array to free
 */
void free_arr(char **arr)
{
    int idx;

    if (arr == NULL)
        return;

    for (idx = 0; arr[idx] != NULL; ++idx)
        free(arr[idx]);
    if (arr[idx] == NULL)
        free(arr[idx]);
    free(arr);
}

/**
 * free_process - frees the process
 * @buffer: input string
 * @args: arguments of string
 */
void free_process(char *buffer, char **args)
{
    free_arr(args);
    free(buffer);
}
