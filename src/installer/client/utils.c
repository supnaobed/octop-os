#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <unistd.h>
#include <linux/limits.h>
#include "utils.h"

/* TODO Native realization */
int mkdir_p(char *path)
{
    if (!is_valid_path(path))
    {
        return false;
    }
    size_t len = strlen(path);
    char command[PATH_MAX + 9] = "mkdir -p ";
    /* +1 to include '\0' symbol */
    strncat(command, path, len + 1);
    return system(command);
}

int touch_dir_p(char *path)
{
    if (!is_valid_path(path))
    {
        return -1;
    }
    struct stat chck;
    if (stat(path, &chck) < 0)
    {
        return mkdir_p(path);
    }
    return 0;
}

bool is_valid_path(char *path)
{
    if (path == NULL)
        return false;
    return strlen(path) < PATH_MAX;
}

int absolute_path(char *path, char *out)
{
    if (path == NULL || out == NULL)
        return -1;

    char d = '/';
    char delimiter[] = {d, '\0'};
    out[0] = '\0';
    if (path[0] == d)
    {
        strcpy(out, path);
        return 0;
    }
    else
    {
        char cwd[PATH_MAX];
        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
            /* +1 by d (delimiter) */
            if ((strlen(cwd) + strlen(path) + 1) > PATH_MAX)
            {
                return -1;
            }
            strcat(out, cwd);
            /* append delimiter */
            strcat(out, delimiter);
            strcat(out, path);
        }
        else
        {
            return -1;
        }
    }

    return 0;
}