#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <linux/limits.h>
#include <unistd.h>
#include "libinstall.h"
#include "utils.h"
#include "unpack.h"

bool check_cfg(Config *cfg)
{
    if (cfg == NULL)
    {
        return false;
    }
    else
    {
        return is_valid_path(cfg->apps_dir) && is_valid_path(cfg->temp_dir);
    }
}

int extract_temp_pkg_name(char *pkg_path, char *out)
{
    if (out == NULL || pkg_path == NULL)
        return -1;

    /* check if string is empty */
    if (pkg_path[0] == '\0')
        return -1;

    char d = '/';        /* delimiter */
    char *di = pkg_path; /* pointer to last found delimiter */
    char *c = pkg_path;
    while (c != NULL && c[0] != '\0')
    {
        putchar(c[0]);
        if (c[0] == d)
        {
            di = c;
        }
        c = c + 1;
    }

    if (di == NULL)
    {
        return -1;
    }

    /* Drop archive extension if exists */
    d = '.';
    int i = 0;
    int len = strlen(di);
    int last_d = len;
    while (di[i] != '\0')
    {
        if (di[i] == d)
        {
            last_d = i;
        }
        i++;
    }
    strncat(out, di, last_d);
    return 0;
}



int install(char *pkg_path, Config *cfg)
{
    if (!is_valid_path(pkg_path))
    {
        printf("Error! Invalid package path");
        return -1;
    }

    if (!check_cfg(cfg))
    {
        printf("Error! Invalid config");
        return -1;
    }

    int status;

    if (touch_dir_p(cfg->apps_dir) != 0)
    {
        printf("Error! Can not create apps directory");
        return -1;
    }

    if (touch_dir_p(cfg->temp_dir) != 0)
    {
        printf("Error! Can not create temp directory");
        return -1;
    }

    char abs_pkg_path[PATH_MAX];
    if (absolute_path(pkg_path, abs_pkg_path) != 0)
    {
        return -1;
    }

    char temp_unpkg_name[PATH_MAX];
    extract_temp_pkg_name(abs_pkg_path, temp_unpkg_name);

    char temp_dir_path[PATH_MAX];
    if (absolute_path(cfg->temp_dir, temp_dir_path) != 0)
    {
        return -1;
    }

    /* Where +1 means delimiter between temp_unpkg_name and temp_dir_path */
    if (strlen(temp_unpkg_name) + strlen(temp_dir_path) + 1 > PATH_MAX)
    {
        return -1;
    }

    char d[] = "/";
    char temp_unpkg_path[PATH_MAX];
    temp_unpkg_path[0] = '\0';
    strcat(temp_unpkg_path, temp_dir_path);
    strcat(temp_unpkg_path, d);
    strcat(temp_unpkg_path, temp_unpkg_name);

    unpack(pkg_path, temp_unpkg_path);

    return 0;
}
