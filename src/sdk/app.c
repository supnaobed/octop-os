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

int read_args(struct App *a);
int observe_lc(struct App *a);

int run(struct App *a)
{
    observe_lc(a);
    return 0;
}

enum AppState launch(enum AppState current_state)
{
    if (current_state == TERMINATED)
    {
        return FOREGROUND;
    }
    return current_state;
}

int read_args(struct App *a)
{
    FILE *fp = fopen("lifecycle", "r");

    char buff[BUFSIZE];
    while (fgets(buff, BUFSIZE - 1, fp) != NULL)
    {
        if (strcmp(buff, "1") == 0)
        {
            if (a->state == TERMINATED)
            {
                a->state = launch(a->state);
                lc_launch(a);
            }
        }
        if (strcmp(buff, "2") == 0)
        {
            if (a->state != TERMINATED)
            {
                lc_terminate(a);
                a->state = TERMINATED;
                exit(1);
            }
        }
    }
    fclose(fp);
    return 0;
}

#define PERMS 0644
#define CMND_LAUNCH "1"
#define CMND_TERM "0"

struct my_msgbuf
{
    long mtype;
    char mtext[200];
};

int observe_lc(struct App *a)
{
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
            if (a->state == TERMINATED)
            {
                a->state = launch(a->state);
                lc_launch(a);
            }
        }

        if (strcmp(buf.mtext, CMND_TERM) == 0)
        {
            if (a->state != TERMINATED)
            {
                lc_terminate(a);
                a->state = TERMINATED;
                exit(1);
            }
        }
    }
    printf("message queue: done receiving messages.\n");
    return 0;
}