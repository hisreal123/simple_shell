#include "shell.h"

/**
 * _chdir - Change the current working directory.
 * @path: Directory path to change to.
 *
 * Return: void
 *
 * This function changes the current working directory to the specified path.
 * If the path is NULL or empty, it defaults to the home directory.
 * Supports switching to the previous directory using "-" and handles errors,
 * providing informative messages for non-existent directories.
 */


void _chdir(const char *path)
{
    static char *last = NULL;

    char current[100];

    if (!path || path[0] == '\0')
        path = getenv("HOME");

    if (strcmp(path, "-") == 0)
    {
        if (!last)
        {
            printf("No previous directory stored.\n");
            return;
        }

        path = last;
        if (chdir(path) != 0)
        {
            perror("chdir");
            return;
        }

        printf("%s\n", path);
        free(last);
        last = strdup(current);
        return;
    }

    if (chdir(path) != 0)
    {
        perror("chdir");
        printf("Directory '%s' does not exist.\n", path);
        return;
    }

    if (getcwd(current, sizeof(current)) == NULL)
    {
        perror("getcwd");
        return;
    }

    last = strdup(current);
}
