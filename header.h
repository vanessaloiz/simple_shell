#ifndef HEADER_H_
#define HEADER_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>

/******** env_func **********/
void env_exit(char *buffer, char **args, char **env);
void _error(char **argv, char *arg, int amt);
void env_cmd(char **envmnt);
char *_env(const char *str, char **envmnt);
char **env_arr(char *cmd, char **envmnt);

/******** free_func **********/
void free_arr(char **arr);
void free_process(char *buffer, char **args);

/******** help_func **********/
unsigned int _strlen(char *buffer);
char **_strtok(char *str);
unsigned int count_args(char *star);
char *_strcpy(char *dest, char *src, int amt);
int _atoi(char *arg);

/******** path_func **********/
void path_handle(char **args, char *buffer, char **env, char **argv, int amt);
unsigned int dir_check(char *path);

/******** process_func *******/
void _fork(char **args, char **argv, char **env, char *buffer, int amt);
void exitcmd(char *buffer, char **args);

/******** help_func1 *********/
char *_cmdcpy(char *dest, char *src, char *cmd, int amt, int count);
char *_cpyarg(char *dest, const char *src, int amt);
unsigned int _envlen(const char *str);
int _strcmp(char *str1, char *str2);

#endif /* HEADER_H_ */
