#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "app.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define BUFSIZE 8
#define PERMS 0644
#define CMND_TERM "0"

struct my_msgbuf
{
    long mtype;
    char mtext[200];
};

int observe_lc(struct App *a);


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
    while (1) {
        printf("alife\n");
        sleep(3);
    }
    // a->state = launch(a->state);
    // lc_launch(a);
    // observe_lc(a);
    return 0;
}

int observe_lc(struct App *a)
{
    struct my_msgbuf buf;
    int msqid;
    int toend;
    key_t key;

    key = ftok("progfile", 94);

    if ((msqid = msgget(key, PERMS)) == -1)
    { 
        perror("[-]App start msqid error");
        exit(1);
    }
    for (;;)
    {
        if (msgrcv(msqid, &buf, sizeof(buf.mtext), 0, 0) == -1)
        {
            perror("[-]App lc error");
            exit(1);
        }
        if (strcmp(buf.mtext, CMND_TERM) == 0)
        {
            if (a->state != TERMINATED)
            {
                lc_terminate(a);
                a->state = TERMINATED;
                return 0;
            }
        }
    }
    return 0;
}