#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define PERMS 0644

struct my_msgbuf
{
    long mtype;
    char mtext[200];
};

int main(int argc, char **argv)
{
    if (argc < 2) 
    {
        perror("args name");
        exit(1);
    }

    struct my_msgbuf buf;
    int msqid;
    int len;
    key_t key;
    key = ftok("receiver.ipc", 67);

    

    if ((msqid = msgget(key, PERMS)) == -1)
    {
        perror("msgget");
        exit(1);
    }
    buf.mtype = 1;
    strcpy(buf.mtext, argv[1]);
    len = strlen(buf.mtext);
    if (msgsnd(msqid, &buf, len + 1, 0) == -1)
        perror("msgsnd");
    return 0;
}