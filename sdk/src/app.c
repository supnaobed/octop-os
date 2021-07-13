#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "static/app.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <pthread.h>

#define BUFSIZE 20
#define PERMS 0644
#define CMND_TERM "0"

struct my_msgbuf
{
    long mtype;
    char mtext[BUFSIZE];
};

void * observe_lc(void *input);


enum AppState launch(enum AppState current_state)
{
    if (current_state == TERMINATED)
    {
        return FOREGROUND;
    }
    return current_state;
}

int run(struct App *a)
{
    printf("[+](App %d) start\n", 0);
    a->state = launch(a->state);
    lc_launch(a);

    pthread_t thread_id;
    printf("Before Thread\n");
    pthread_create(&thread_id, NULL, observe_lc, (void *)a);
    while (1)
    {
        printf("await\n");
        sleep(3);
    }
    
    pthread_join(thread_id, NULL);
    printf("After Thread\n");
    return 0;
}

void * observe_lc(void *input)
{
    
    struct App * a;
    a = ((struct App*)input);
    struct my_msgbuf buf;
    int msqid;
    int toend;
    key_t key;

    key = ftok(a->name, getpid());

    if ((msqid = msgget(key, PERMS)) == -1)
    { 
        printf("[-](App %s)", a->name);
        perror("start msqid error");
        exit(1);
    }
    for (;;)
    {
        if (msgrcv(msqid, &buf, sizeof(buf.mtext), 0, 0) == -1)
        {
            printf("[-](App %s)", a->name);
            perror("msqid msgrcv error");
            exit(1);
        }
        if (strcmp(buf.mtext, CMND_TERM) == 0)
        {
            if (a->state != TERMINATED)
            {
                lc_terminate(a);
                msgctl(msqid, IPC_RMID, NULL);
                a->state = TERMINATED;
                return 0;
            }
        }
    }
}

int lc_launch(struct App * a){
    return 0;
}

int lc_terminate(struct App * a){
    return 0;
}