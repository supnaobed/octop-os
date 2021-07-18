#include <stdio.h>
#include "app.h"
#include "robmov.h"
#include "../installer/client/libinstall.h"


int main(){
    Config config = {
        "/home/rz/apps",
        "/home/rz/tmp"
    }; 
    int status;
    status = install("/home/rz/test.zip", &config);
    struct Robot r = { "batyr"};
    struct App app = { "matur", &r, TERMINATED};
    run(&app);
}

int lc_launch(struct App *a){
    move_letf(a->robot);
    move_forward(a->robot);
    move_right(a->robot);
    move_backward(a->robot);
    return 0;
}

int lc_terminate(struct App *a){
    printf("URAZA\n");
    return 0;
}