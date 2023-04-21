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

char *found_path(char *cmd);
void exec_cmd(char *cmd_with_path, char **av);

int word_count(char *input);
void parse_inp(char **av, char *input);
void sig_handler(int signal);

void shell_loop(char **av);

#endif