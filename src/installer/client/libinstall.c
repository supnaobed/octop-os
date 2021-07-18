#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h>
#include <linux/limits.h>
#include <unistd.h>
#include "libinstall.h"
#include "utils.h"
#include "unpack.h"

#define MAX_META_LINE_LEN 256

#define META_LINE_PACKAGE 0
#define META_LINE_NAME 1
#define META_LINE_VERSION 2
#define META_LINE_AUTHOR 3

static const char META_NAME[] = "meta";

typedef struct
{
    char *pkg;
    char *name;
    char *version;
    char *author;
} Meta;

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

bool chck_meta(Meta *meta)
{
    if (meta == NULL)
        return false;
    if (meta->pkg == NULL)
        return false;
    return true;
}

int unsafe_read_meta(char *meta_path, Meta *meta)
{
    FILE *f;
    f = fopen(meta_path, "r");
    if (f == NULL)
        return -1;
    char buff[MAX_META_LINE_LEN];
    buff[0] = '\0';
    int i = 0;
    char value[MAX_META_LINE_LEN] = "";
    while (fgets(buff, MAX_META_LINE_LEN, f) != NULL)
    {
        value[0] = '\0';
        strcpy(value, buff);
        switch (i)
        {
        case META_LINE_PACKAGE:
            meta->pkg = value;
            break;
        case META_LINE_NAME:
            meta->name = value;
            break;
        case META_LINE_VERSION:
            meta->version = value;
            break;
        case META_LINE_AUTHOR:
            meta->author = value;
            break;
        default:
            break;
        }
        i++;
    }
    fclose(f);
    return 0;
}

int read_meta(char *app_dir, Meta *meta)
{
    if (!is_valid_path(app_dir))
        return -1;
    char meta_path[PATH_MAX + sizeof(META_NAME) / sizeof(char) + 1];
    int status = concat_path(meta_path, app_dir, META_NAME);
    if (status != 0)
    {
        return status;
    }
    if (!is_valid_path(meta_path))
    {
        return -1;
    }
    struct stat chck;
    if (stat(meta_path, &chck) < 0)
    {
        printf("Error %s not found!", meta_path);
        return -1;
    }

    return unsafe_read_meta(meta_path, meta);
}

int install(char *pkg_path, Config *cfg)
{
    if (!is_valid_path(pkg_path))
    {
        printf("Error! Invalid package path\n");
        return -1;
    }

    if (!check_cfg(cfg))
    {
        printf("Error! Invalid config\n");
        return -1;
    }

    int status;

    if (touch_dir_p(cfg->apps_dir) != 0)
    {
        printf("Error! Can not create apps directory\n");
        return -1;
    }

    if (touch_dir_p(cfg->temp_dir) != 0)
    {
        printf("Error! Can not create temp directory\n");
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

    char temp_unpkg_path[PATH_MAX];
    status = concat_path(temp_unpkg_path, temp_dir_path, temp_unpkg_name);
    if (status != 0)
    {
        return -1;
    }

    unpack(pkg_path, temp_unpkg_path);

    Meta meta;
    status = read_meta(temp_unpkg_path, &meta);
    if (status != 0)
    {
        printf("Error! Can not read meta, or meta is invalid\n");
        return -1;
    }

    char final_pkg_path[PATH_MAX];
    status = concat_path(final_pkg_path, cfg->apps_dir, meta.pkg);
    if (status != 0)
    {
        printf("Error! Can not generate install package path\n");
        return -1;
    }

    rmrf(final_pkg_path);

    status = mv(temp_unpkg_path, final_pkg_path);
    if (status != 0)
    {
        printf("Error! Can not move unpacked package to apps disrectory\n");
        return -1;
    }
    return 0;
}
