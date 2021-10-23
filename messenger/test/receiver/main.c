#include "MessageQueue.h"
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int i;
	int key = 10;
	int qid;
	struct Message msg;
	char buffer[MESSAGE_SIZE];
	int ret;
	int mtype=1;

	/* Fill buffers with data: */
	memset(buffer, 0, MESSAGE_SIZE);
	for( i = 0; i < 26; i++ ){
		buffer[i] = 65 + i;
	}

	/* Create message queues: */
	printf("making msq queue with key %d\n", key);
	qid = messageQueueGet(key);
	printf("message queue returned qid %d\n", qid);
	if(qid == -1){ return -1; }

	/* Receive message: */
	while (1) {
		printf("Receiving message from qid: %d\n", qid);
		ret = messageQueueReceive(qid, &msg, mtype);
		printf("Receiving message returned %d\n", ret);
		printf("Received message: %s\n", messageToString(&msg));	
	}
	
	return 0;
}