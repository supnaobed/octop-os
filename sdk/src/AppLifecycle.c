#include "../include/AppDelegate.h"
#include "../include/App.h"
#include "MessageQueue.h"
#include "MessageReceiver.h"
#include "Queue.h"
#include <stdio.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>
#include <semaphore.h>


#define MESSANGER_SHARED 1

sem_t messanger_sem;
MessageReceiver messageReceiver;
struct Queue* queue;

int runLooper(){
    while (1) { }
    return 0;
}

void handleMessage(Message message){
    printf("%s\n", message.buffer);
}

void *MainLifecycle(void *vargp)
{
    int current_message_uid = -1;
    start(&app);
    while (1) {
       enqueueMessages(&messageReceiver, handleMessage);
    }
    return NULL;
}

int runThreads(){
    pthread_t main_thread_id;
    pthread_t messages_thread_id;
    queue = createQueue(10);
    messageReceiver.shared = messanger_sem;
    messageReceiver.shared = MESSANGER_SHARED;
    messageReceiver.queue = queue;
    messageReceiver.key = getpid();
    printf("messageReceiver %d\n", messageReceiver.key);
    sem_init(&messanger_sem, MESSANGER_SHARED, 1);
    pthread_create(&main_thread_id, NULL, MainLifecycle, NULL);
    createReceiverThread(&messageReceiver);
    pthread_join(main_thread_id, NULL);
    return 0;
}

int runLifecycle(struct App * app){
    runThreads();
    runLooper();
    return 0;
}