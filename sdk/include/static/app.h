#ifndef APP_H
#define APP_H
#include "static/robmov.h"

enum AppState {
    TERMINATED,
    FOREGROUND,
    BACKGROUND
};

struct App {
    char *name;
    struct Robot *robot;
    enum AppState state;
    void *lc_launch;
    void *lc_terminate;
};

int run(struct App * a);

#endif /* APP_H */