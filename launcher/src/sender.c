#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "../include/sender.h"
#include "MessageQueue.h"


int sendmsg(Proc proc, char * msg) {
    int key = proc.pid;
	int qid = messageQueueCreate(key);
	if(qid == -1){ return -1; }

    int mtype=1;
    char buffer[MESSAGE_SIZE];
	struct Message message;
    memset(buffer, 0, MESSAGE_SIZE);
    strcpy(buffer, msg);

    setMessage(&message, buffer, MESSAGE_SIZE, mtype);	
	int ret = messageQueueSend(qid, &message);
    if(qid == -1){ return -1; }
    return 0;
}
