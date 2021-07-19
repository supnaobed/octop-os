#include "static/robmov.h"
#include "static/app.h"
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

    move_letf(a->robot);
    move_forward(a->robot);
    move_right(a->robot);
    move_backward(a->robot);
}

void lc_terminate(void * input){
    printf("URAZA\n");
}