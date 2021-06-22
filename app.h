#ifndef APP_H
#define APP_H

struct App {
    char name[100];
};

int lc_launch(struct App * a);

int lc_terminate(struct App * a);

#endif /* APP_H */