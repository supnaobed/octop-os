#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include "app.h" 

#define BUFSIZE 1000

int read_args(struct App *a){
    
    FILE *fp = fopen("lifecicle", "r"); 

    char buff[BUFSIZE];

    while(fgets(buff, BUFSIZE - 1, fp) != NULL) {
        if (buff[8] == "1") {
            lc_launch(a);
        }
        if (buff[8] == "2") {
            lc_terminate(a);
        }
    }
    fclose(fp); 
    return 0;
}

int lc_launch(struct App * a){
    return 0;
}

int lc_terminate(struct App * a){
    return 0;
}

int run(struct App *a){
    while(1){
        read_args(a);
    }
}



