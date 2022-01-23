#ifndef SOCKET_SERVER
#define SOCKET_SERVER
#include <string.h>
#include <stdio.h>

typedef struct SocketServer {
} SocketServer;

void Run(SocketServer* server);

extern int Receive(char *buff, int size);

#endif