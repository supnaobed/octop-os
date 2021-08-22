#include "include/static/robmov.h"
#include <stdio.h>

int move(struct Robot * r){
    printf("Now the robot %s is moving FORWARD\n", r->name);
    return 0;
}

int stop(struct Robot * r){
    printf("Now the robot %s is stopped\n", r->name);
    return 0;
}



