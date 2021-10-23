#include <sys/msg.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/ipc.h>
#include <stdio.h>
#include "errno.h"
#include <string.h>
#include "Message.h"

/* Message queue utilities */
int messageQueueGet(key_t key);
int messageQueueCreate(key_t key);
int messageQueueDelete(int qid);

/* Message send: */
int messageQueueSend(int qid, Message *msg);
int messageQueueSend_nowait(int qid, Message *msg);

/* Message Receive */
int messageQueueReceive(int qid, Message *msg, long type);
int messageQueueReceive_nowait(int qid, Message *msg, long type);
