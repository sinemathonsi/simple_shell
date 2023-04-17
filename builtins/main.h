#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

extern char **environ;

/**
 * struct builtin_funcs - structure to hold and find builtin funcs
 * @func_names: names of builtin func on cmd line
 * @func: function ponter to builtin functions
 */
typedef struct builtin_funcs
{
	char *func_names;
	void (*func)(char *);
} builtins;

/* gets user input and reallocates as memory is needed */
int get_user_input(char **input);

/* built in function finder */
int which_func(char *input, char *arg);

/* builtins funcs */
void print_the_env(char *input);		 /* prints the environmet variables, needs work */
void shell_exit(char *args); /* shell exit function trial */
void set_env_var(char *arg); /* trying to set new env var */

/* helpers */
unsigned int count_words(char *input);
int stringcmp(char *s1, char *s2);

#endif
