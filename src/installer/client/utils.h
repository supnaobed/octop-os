#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

int mkdir_p(char *path);

int touch_dir_p(char *path);

bool is_valid_path(char *path);

int absolute_path(char *path, char *out);

#endif /* UTILS_H */