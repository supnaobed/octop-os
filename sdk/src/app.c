#include "../include/AppDelegate.h"
#include "../include/App.h"
#include "MessageQueue.h"
#include <stdio.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

extern int start(struct App * app);

extern int stop(struct App * app);

extern int execute(struct App * app);

struct App app;

pthread_t thread_id;

int runLooper();

int runMainThread();

int runApp(char *name) {
    app.name = name;
    printf("name is %s\n", name);
    runMainThread();
    runLooper();
    return 0; 
}

int runLooper(){
    while (1) { }
    return 0;
}


void *mainThread(void *vargp)
{
    int qid;
    int key = 10;
	struct Message msg;
	char buffer[MESSAGE_SIZE];
	int ret;
	int mtype=1;

	qid = messageQueueGet(key);
	if(qid == -1){ return NULL; }

    start(&app);
    while (1) {
		ret = messageQueueReceive(qid, &msg, mtype);
        if (msg.mtype == 1) {
            execute(&app);
        }
    }
    stop(&app);
    return NULL;
}

int runMainThread(){
    pthread_create(&thread_id, NULL, mainThread, NULL);
    pthread_join(thread_id, NULL);
    return 0;
}
