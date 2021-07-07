#ifndef LIBINSTALL_H
#define LIBINSTALL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *apps_dir;
    char *temp_dir;
} Config;

int install(char* pkg_path, Config *cfg);

#endif /* LIBINSTALL_H */
