#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

struct stat st = {0};

static int counter;

int make_app_dir(){
    if (stat("./apps", &st)==-1){
        mkdir("./apps", 0700);
        return 0;
    }  
    return -1;
}

int main(){
    make_app_dir();
    counter += 1;
    printf ("Executing %d\n", counter);
    return 0;
}

