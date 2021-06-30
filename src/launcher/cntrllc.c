#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
// Lifecycle control utils

#define APPS_PATH "./apps/"
#define PERMS 0644
#define CMND_LAUNCH "1"
#define CMND_TERM "0"

struct my_msgbuf
{
    long mtype;
    char mtext[200];
};

int launch(char* app_name);

int main(){
    struct my_msgbuf buf;
    int msqid;
    int toend;
    key_t key;

    key = ftok("progfile", 65);

    if ((msqid = msgget(key, PERMS)) == -1)
    { /* connect to the queue */
        perror("msgget");
        exit(1);
    }
    printf("message queue: ready to receive messages.\n");

    for (;;)
    {
        if (msgrcv(msqid, &buf, sizeof(buf.mtext), 0, 0) == -1)
        {
            perror("msgrcv");
            exit(1);
        }
        printf("recvd: \"%s\"\n", buf.mtext);
        if (strcmp(buf.mtext, CMND_LAUNCH) == 0)
        {
            continue;
        }

        if (strcmp(buf.mtext, CMND_TERM) == 0)
        {
            continue;
        }
        launch(buf.mtext);
    }
}

int launch(char* app_name) {
    char app_path[30];

    strcpy(app_path, APPS_PATH);
    strcat(app_path, app_name);
    
    printf("[+]App in %s.\n", app_path);
    int status = system(app_path);
    printf("[+]App %d is \n", status);
    return 0;
}

