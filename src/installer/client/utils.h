#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

bool is_valid_path(const char *path);

int concat_path(char *dest, const char *f1, const char *f2);

int rmrf(const char *path);

int mkdir_p(const char *path);

int mv(const char *from, const char *to);

int touch_dir_p(const char *path);

int absolute_path(const char *path, char *out);

#endif /* UTILS_H */