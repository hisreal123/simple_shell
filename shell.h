#ifndef SHELL_H
#define SHELL_H


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

extern char **environ;

void fork_execute(int *loop, char **args, char *argv);
void process_command(int *loop, char *cmd, char *argv);
int get_input(int *loop, char *argv);
void non_interactive(char *argv, char **envp);
char **get_env(char **env);
int strcomp(char *s1, char *s2);
int exit_status(char *value);
size_t getlin(char **mem, size_t *len, FILE *line);
void fork_child(char **args, int *loop, char *argv);
char *strtk(char *str, const char *delim);
void _chdir(const char *path);
int commands(char **arg);



#endif
