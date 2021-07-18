#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <unistd.h>
#include <linux/limits.h>
#include "utils.h"

bool is_valid_path(const char *path)
{
    if (path == NULL)
        return false;
    return strlen(path) < PATH_MAX;
}

int concat_path(char *dest, const char *f1, const char *f2)
{
    if (!(is_valid_path(f1) && is_valid_path(f2)))
    {
        return -1;
    }
    size_t len1, len2;
    len1 = strlen(f1);
    len2 = strlen(f2);
    if (len1 + len2 + 1 > PATH_MAX)
    {
        return -1;
    }
    dest[0] = '\0';
    strcat(dest, f1);
    strcat(dest, "/");
    strcat(dest, f2);
    return 0;
}

/* TODO Native realization */
int mkdir_p(const char *path)
{
    if (!is_valid_path(path))
    {
        return -1;
    }
    size_t len = strlen(path);
    char command[PATH_MAX + 10] = "mkdir -p ";
    /* +1 to include '\0' symbol */
    strncat(command, path, len + 1);
    return system(command);
}

int rmrf(const char *path)
{
    if (!is_valid_path(path))
    {
        return -1;
    }
    char command[PATH_MAX + 7] = "rm -rf ";
    strcat(command, path);
    return system(command);
}

/* TODO Native realization */
int mv(const char *from, const char *to)
{
    if (!is_valid_path(from) || !is_valid_path(to))
    {
        return -1;
    }
    char command[PATH_MAX * 2 + 8] = "mv -T ";
    char devider[] = " ";
    strcat(command, from);
    strcat(command, devider);
    strcat(command, to);
    return system(command);
}

int touch_dir_p(const char *path)
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

int absolute_path(const char *path, char *out)
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