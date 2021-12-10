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
