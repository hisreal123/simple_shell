#include "main.h"

/**
* child_process -  a process */

int child_process(int num_children)
{
    for (int i = 0; i < num_children; i++)
    {
        pid_t c_pid = fork();

        if (c_pid == -1)
        {
            perror("Fork failed");
            return (1);
        } else if (c_pid == 0)
        {
            run_ls_l_tmp();
            return (0);
        } else
        {
            int status;
             waitpid(c_pid, &status, 0);

             if (WIFEXITED(status))
             {
                int exit_status = WIFEXITED(status);
                printf("Child %d exited with status %d\n", i + 1, exit_status);
                if (exit_status != 0) {
                    return 1;
                }
             }  else {
                printf("Child %d did not exit normally\n", i + 1);
                return 1;
            }
        }
    }
}