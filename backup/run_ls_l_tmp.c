#include "main.h"

/**
* run_ls_l_tmp -  a process */

void run_ls_l_tmp() {
    printf("Child PID %d is running ls -l /tmp\n", getpid());
    execlp("ls", "ls", "-l", "/tmp", NULL);
    perror("execlp");
    exit(1);
}