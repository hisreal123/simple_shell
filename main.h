#ifndef MAIN_H
#define MAIN_H


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


int child_process(int num_children);
void run_ls_l_tmp(void);


#endif
