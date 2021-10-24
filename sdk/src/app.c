#include "../include/AppDelegate.h"
#include "../include/App.h"
#include "MessageQueue.h"
#include "AppLifecycle.h"
#include <stdio.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

extern int start(struct App * app);

extern int stop(struct App * app);

extern int execute(struct App * app);

struct App app;

int runApp(char *name) {
    app.name = name;
    printf("name is %s\n", name);
    runLifecycle(&app);
    return 0; 
}


