#ifndef QUEUE
#define QUEUE
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "Message.h"

// A structure to represent a queue
typedef struct Queue {
    int front, rear, size;
    unsigned capacity;
    Message* array;
} Queue;

struct Queue* createQueue(unsigned capacity);
Message* dequeue(struct Queue* queue);
void enqueue(struct Queue* queue, Message item);
#endif

