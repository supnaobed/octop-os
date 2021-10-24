#include <pthread.h>
#include <semaphore.h>
#include "../include/MessageReceiver.h"
#include "../include/MessageQueue.h"
#include <stdio.h>

void *Messanger(void *input)
{
    int qid;
    int key = 100;
	struct Message msg;
	char buffer[MESSAGE_SIZE];
	int ret;
	int mtype=1;

	qid = messageQueueGet(key);

    MessageReceiver * mr = (MessageReceiver*)input;
    Queue * queue = mr->queue;
    sem_t *sem = mr->sem;

	if(qid == -1){ return NULL; }
    while (1) {
		ret = messageQueueReceive(qid, &msg, mtype);
        printf("new message\n");
        sem_wait(&sem);
        printf("queue size before %d\n", queue->size);
        enqueue(queue, msg);
        printf("queue size after  %d\n", queue->size);
        sem_post(&sem);
    }
    return NULL;
}

void createReceiverThread(MessageReceiver * r){
    pthread_t messages_thread_id;
    sem_t *sem = r->sem;
    int shared = r->shared;
    sem_init(sem, shared, 1);
    pthread_create(&messages_thread_id, NULL, Messanger, r);
    pthread_join(messages_thread_id, NULL);
}


void enqueueMessages(MessageReceiver* receiver, void (*callback)(Message)){
    sem_t *sem = receiver->sem;
    Queue * queue = receiver->queue;
    while (1) {
        sem_wait(&sem);
        Message * m = dequeue(queue);
        sem_post(&sem);
        if (m == NULL) {
            break;
        }
        callback(*m);
    }
}


