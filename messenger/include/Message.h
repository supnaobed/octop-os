#ifndef MESSAGE
#define MESSAGE
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define MESSAGE_SIZE 64
typedef struct Message {
	long mtype;
	char buffer[MESSAGE_SIZE];
	int err;
} Message;

void clearMessage(Message* msg);
void setMessage(Message* msg, char* buffer, int len, long mtype);
const char* messageToString(Message* msg);
#endif