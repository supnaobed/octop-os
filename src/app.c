#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include "app.h"
#include <string.h>

#define BUFSIZE 8

int read_args(struct App *a);


int run(struct App *a){
    while(1){
        read_args(a);
    }
}

enum AppState launch(enum AppState current_state){
    if (current_state == TERMINATED) {
        return FOREGROUND;    
    }
    return current_state;
}

int read_args(struct App *a){
    FILE *fp = fopen("lifecicle", "r"); 

    char buff[BUFSIZE];
    while(fgets(buff, BUFSIZE - 1, fp) != NULL) {
        if (strcmp(buff, "1") == 0) {
            if (a->state == TERMINATED) {
                a->state = launch(a->state);
                lc_launch(a);
            }
        }
        if (strcmp(buff, "2") == 0) {
            if (a->state != TERMINATED) {
                a->state = FOREGROUND;
                lc_terminate(a);
            }
           
        }
    }
    fclose(fp); 
    return 0;
}
