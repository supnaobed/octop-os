#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "include/cmd.h"

int args(char * text, Cmd * cmd){
    cmd->package_id = strtok(text," ,-");
    char * commnd_str = strtok(NULL," ,-");
    int command =  atoi(commnd_str); 
    cmd->command = command;
    return 0;
}

int readcmd(Cmd * cmd){
    char *string; 
    size_t size = 10; 
    string = (char*) malloc (size);
    if(string == NULL)
    {
        printf("unable to allocate memory");
        exit(1);
    }
    else
    {
        char **string_pointer = &string; 
    
        size_t characters = getline(string_pointer,&size,stdin);
        string[strcspn(string, "\n")] = 0;
        return args(string, cmd);   
    }
    return 0;
}