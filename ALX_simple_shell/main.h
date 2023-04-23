#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>

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

char *found_path(char *cmd);

void exec_cmd(char *cmd_with_path, char **av);

/* utilities */
int word_count(char *input);
void parse_inp(char **av, char *input);
int stringcmp(char *s1, char *s2);

void shell_loop(char *argv_0_holder, char **av);

int which_func(char *input, char *arg);

void builtin_exit(char *status);

void builtin_print_env(char *arg);

#endif