#include "MessageQueue.h"
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int i;
	int key = 10;
	int qid;
	struct Message msg, msg2;
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
	qid = messageQueueCreate(key);
	printf("message queue returned qid %d\n", qid);
	if(qid == -1){ return -1; }


	/* Create messages: */
	printf("creating message\n%s\n", messageToString(&msg));
	clearMessage(&msg);
	printf("clearing message\n%s\n", messageToString(&msg));

	setMessage(&msg, buffer, MESSAGE_SIZE, mtype);
	printf("Making message with buffer:\n%s\n\n", buffer);

	
	/* Send message: */
	ret = messageQueueSend(qid, &msg);
	printf("Sending message returned %d\n", ret);
	printf("Sent message: %s\n", messageToString(&msg));

	/* Send message: */
	ret = messageQueueSend(qid, &msg);
	printf("Sending message returned %d\n", ret);
	printf("Sent message: %s\n", messageToString(&msg));

	/* Delete queues: */
	// printf("Deleting qid: %d returned %d\n", qid , messageQueueDelete(qid));
	
	return 0;
}