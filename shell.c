#include "main.h"

/**
 * main - new shell program
 * Return: 0 on success, else -1
 */

int main(void)
{
    char *cmd = NULL, *token, **args = NULL;
    int  status, num = 0;
    size_t read, count = 0;
    pid_t child;

    printf("Opening shell...\n");
    sleep(1);

    for (;;)
    {
        printf("($) ");
        if (cmd != NULL)
            free(cmd);
        read = getline(&cmd, &count, stdin);
        if (read == -1)
        {
			perror("Error getting line !!");
            free(cmd);
            return (-1);
        }
        cmd[read - 1] = '\0';

        if (args != NULL)
            free(args);
        args = (char **)malloc(sizeof(char *) * 100);
        if (args == NULL)
        {
            printf("Memory allocation error\n");
            free(args);
            free(cmd);
            return (0);
        }

        if (strcmp(cmd, "exit") == 0)
        {
            printf("Exiting shell...\n");
            free(cmd);
            free(args);
            return (0);
        };

        token = strtok(cmd, " ");
        while (token)
        {
            args[num] = token;
            token = strtok(NULL, " ");
            num++;
        }
        args[num] = NULL;

        child = fork();
        if (child == -1)
            printf("Oops, forking error");
        else if (child == 0)
        {
            if (execve(args[0], args, NULL) == -1)
            {
                printf("Execve error\n");
                return (-1);
            }
        }
        else
        {
            sleep(1);
            sleep(1);
            wait(&status);
            sleep(1);
        }
        num = 0;
    }

	free(cmd);
	free(args);

    return (0);
}