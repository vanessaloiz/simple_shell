## NAME
Simple Shell Terminal in C Language

 

<h1 align="center">Simple Shell</h1>

 

<p align="center"> </p>

 

## Description

Simple shell interprets and executes basic UNIX commands with arguments.
It is a project assigned with certain requirements and restrictions by Holberton School with the goal of recreating a UNIX shell.
The executable displays a prompt, waits for user input, interprets it and executes if it is valid.

##### Please follow the steps below to compile.
 1. `cd simple_shell`
 2. `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
 3. `./a.hsh`

### Functions
Prototypes | Description
----------- | -------------
**env_cmd** | Function that prints the length of the command (input).
**path_handle** | Function that handles the `PATH` variable and checks for commands.
**_fork** | Function that creates the fork process (child).
**free_func** | Function that frees the memory (buffer).
**_strlen** | Function that tokenizes a string's.
**_strcpy** | Function that copies a string.
**_strtok** | Function that tokenizes a string.
**_atoi** | Converts a character into an integer.
**_cmdcpy** | Function that copy commands.
**_cpyarg** | Function that copies arguments.
**_strcmp** | Function that compares two strings.

### Files
The following files were used to build and run our shell.

* [simple_shell.c](https://github.com/vanessaloiz/simple_shell/blob/master/simple_shell.c)
This is the main function that executes the shell environment.
* [path_func.c](https://github.com/vanessaloiz/simple_shell/blob/master/path_func.c)
Function that handles the `PATH` variable and checks for commands.
* [process_func.c](https://github.com/vanessaloiz/simple_shell/blob/master/process_func.c)
Function that creates the fork process.
* [env_func.c](https://github.com/vanessaloiz/simple_shell/blob/master/env_func.c)
Function that lets you interoperate with the shell.
* [free.c](https://github.com/vanessaloiz/simple_shell/blob/master/free.c)
A file with functions that free the process and arrays.
* [header.h](https://github.com/vanessaloiz/simple_shell/blob/master/header.h)
Header file where prototypes and libraries are stored.
* [help_func.c](https://github.com/vanessaloiz/simple_shell/blob/master/help_func.c) and [help_func1.c](https://github.com/vanessaloiz/simple_shell/blob/master/help_func1.c)
Are files that hold multiple functions needed and/or required to properly run the shell.


### Examples

```
$ ls

This will list files in the current directory

$ ls -la

This will list all files in the current directory in long format

$ echo Hello

This will print out input

$ pwd

This will print the working directory

```

#### Type of interactions:

##### Non-interactive
*Command*
```
echo "/bin/ls" | ./a.hsh
```
*Output*
```
AUTHORS    env_func.c  header.h      hsh                 process_func.c
README.md  free.c      help_func.c   man_1_simple_shell  simple_shell.c
compiler   getline.c   help_func1.c  path_func.c         valgrind

```
<hr>

##### Interactive
*Command*
```
./a.hsh
```
Once the prompt `($)` is on display, you can type in the command line,
enter
**Example input** - `/bin/ls`

*Output*
```
AUTHORS    env_func.c  header.h      hsh                 process_func.c
README.md  free.c      help_func.c   man_1_simple_shell  simple_shell.c
compiler   getline.c   help_func1.c  path_func.c         valgrind

```

## Contributors
Vanessa Loiz and Rafael Narvaez
@cohort-16 SJU-0921 | Holberton School :puerto_rico:
License & Copyright

Simple Shell project was a 15 day assignment delegated to Holberton Students around the world. This Shell Project was created and made with :heart:!i! by Cohort-16 SJU-0921 students.

© [2021] [Vanessa Loiz & Rafael E. Narvaez Cabeza | Holberton School Puerto Rico]
