#include "static/robmov.h"
#include "static/app.h"
#include <unistd.h>
#include <stdio.h>

void lc_launch(void * input);
void lc_terminate(void * input);

int main(void){
    struct Robot r = { "batyr"};
    struct App app;
    app.name =  "matur";
    app.robot =  &r;
    app.state = TERMINATED;
    app.lc_launch = lc_launch;
    app.lc_terminate = lc_terminate;
    run(&app);
    return 0;
}

void lc_launch(void * input){
    
    struct App * a;
    a = ((struct App*)input);

    move(a->robot);
    sleep(3);
    stop(a->robot);
}

void lc_terminate(void * input){
    printf("URAZA\n");
}