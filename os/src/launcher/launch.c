#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define PERMS 0644
typedef struct my_msgbuf
{
    long mtype;
    char mtext[200];
} message;

typedef struct broadcast_sender{
    int id;
    int msqid;
    char *name;
    key_t *key;
} broadcast;

int create(broadcast *b){
    int msqid;
    int len;
    key_t key;

    key = ftok(b->name, b->id);

    if ((msqid = msgget(key, PERMS | IPC_EXCL | IPC_CREAT)) == -1)
    {
        perror("msgget");
        exit(1);
    }
    b->msqid = msqid;
    b->key = &key;
    return 0;
}

int send(broadcast *b, message m){
    int status;
    if ((status = msgsnd((*b).msqid, &m, sizeof(long) + (strlen(m.mtext) * sizeof(char)) + 1, IPC_NOWAIT)) < 0)
    {
        perror("[-](Process manager)");
        exit(1);
    }
    printf("status is %d\n", status);
    return status;
}

int resend(broadcast *from, broadcast* to) {
    message buf;
    if (msgrcv((*from).msqid, &buf, sizeof(buf.mtext), 0, 0) == -1)
    {
        perror("[-](Process manager) listern lifecycle error\n");
    }
        
    message m;
    m.mtype = 1;
    strcpy(m.mtext, buf.mtext);
    send(to, m);
    return 0;
}

void close(broadcast *b){
    if (msgctl((*b).msqid, IPC_RMID, NULL) == -1)
    {
        perror("msgctl");
        exit(1);
    }
    printf("message queue: done sending messages.\n");
}

int receive_messages(broadcast *b)
{
    broadcast receiver;
    receiver.id = 67;
    receiver.name = "receiver.ipc";
    system("rm -rf receiver.ipc");
    system("touch receiver.ipc");
    create(&receiver);
    for (;;)
    {
        resend(&receiver, b);
    }
    return 0;
}

int main(void)
{   
    broadcast b;
    b.id = 65;
    b.name = "procmng.ipc";
    system("rm -rf procmng.ipc");
    system("touch procmng.ipc");
    create(&b);
    receive_messages(&b);
    close(&b);
    return 0;
}


