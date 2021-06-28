#ifndef APP_H
#define APP_H
#include "robmov.h"

enum AppState {
    TERMINATED,
    FOREGROUND,
    BACKGROUND
};

struct App {
    char *name;
    struct Robot *robot;
    enum AppState state;
};

int lc_launch(struct App * a);

int lc_terminate(struct App * a);

int run(struct App * a);

#endif /* APP_H */