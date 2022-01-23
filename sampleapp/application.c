#include "AppDelegate.h"
#include "App.h"
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "SocketServer.h"
#include "Platform.h"
#include <stdint.h>

Platform platform;

int Receive(char *buff, int size){
   if (strncmp("MOVE_FORVARD", buff, size)==0) {
      MovingAhead(&platform, 1);
   } 
   if (strncmp("MOVE_LEFT", buff, size)==0) {
      // moving_ahead(&platform, 2);
   }   
   if (strncmp("MOVE_RIGHT", buff, size)==0) {
      // moving_ahead(&platform, 3);
   } 
   if (strncmp("MOVE_BACK", buff, size)==0) {
      StopPlatform(&platform);
   } 
   return 0;
}

void *network(void *vargp){
   SocketServer server;
   Run(&server);
   return 0;
}

int InitMotor(){
   InitPlatform(&platform, 0x10, 0x05);
   return 0;
}

int start(struct App * app){
   InitMotor();
   printf("start %d\n", getpid());
   pthread_t thread_id;
   pthread_create(&thread_id, NULL, network, NULL);
   return 0;
}

int stop(struct App * app){
   printf("stop\n");
   return 0;
}

int execute(struct App * app){
   printf("execute\n");
   return 0;
}


int main(){
   runApp("sample");
   return 0; 
}