#include "include/static/robmov.h"
#include <stdio.h>

int move_forward(struct Robot * r){
    printf("Now the robot %s is moving FORWARD\n", r->name);
    return 0;
}

int move_backward(struct Robot * r){
    printf("Now the robot %s is moving BACKWARD\n", r->name);
    return 0;
}

int move_right(struct Robot * r){
    printf("Now the robot %s is moving RIGHT\n", r->name);
    return 0;
}

int move_letf(struct Robot * r){
    printf("Now the robot %s is moving LEFT\n", r->name);
    return 0;
}

int rotate_right(struct Robot * r){
    printf("Now the robot %s is rotating RIGHT\n", r->name);
    return 0;
}

int rotate_left(struct Robot * r){
    printf("Now the robot %s is rotating LEFT\n", r->name);
    return 0;
}

int stop(struct Robot * r){
    printf("Now the robot %s is stopped\n", r->name);
    return 0;
}



