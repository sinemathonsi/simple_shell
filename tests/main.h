#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
 * struct builtin_funcs - structure to hold and find builtin funcs
 * @func_names: names of builtin func on cmd line
 * @func: function ponter to builtin functions
*/
typedef struct builtin_funcs
{
	char *func_names;
	void (*func)(char*, char**);
} builtins;

/* built in function finder */
int which_func(char *input, char *arg, char **env);
/* shell exit function trial */
void shell_exit(char *args, char **env);

/* gets user input and reallocates as memory is needed */
int get_user_input(char **input);

/* prints the environmet variables, needs work */
void print_the_env(char *arg, char **env);

#endif
