#ifndef MESSAGE_RECEIVER
#define MESSAGE_RECEIVER
#include <semaphore.h>
#include "Queue.h"

typedef struct MessageReceiver {
	Queue *queue;
	sem_t * sem;
    int shared;
} MessageReceiver;


void createReceiverThread(MessageReceiver* receiver);
void enqueueMessages(MessageReceiver* receiver, void (*callback)(Message));
#endif