#include <stdlib.h>
#include <linux/limits.h>
#include <string.h>
#include "utils.h"
#include "unpack.h"

/* TODO Native realization */
int unpack(const char *pack_path, const char *destination_path)
{
    size_t pack_len = strlen(pack_path);
    size_t destination_len = strlen(destination_path);
    if (pack_len > PATH_MAX || destination_len > PATH_MAX)
    {
        return -1;
    }
    char command[PATH_MAX * 2 + 16] = "unzip -o -q ";
    strcat(command, pack_path);
    strcat(command, " -d ");
    strcat(command, destination_path);
    return system(command);
}