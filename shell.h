#ifndef SHELL_H
#define SHELL_H


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void fork_execute(int *loop, char *cmd, char **args, char *argv, char **envp);
void process_command(int *loop, char *cmd, char *argv, char **envp);
int get_input(int *loop, char *argv, char **envp);
void non_interactive(char *argv, char **envp);
void get_env(char **envp);
int strcomp(char *s1, char *s2);


#endif
