#include "AppDelegate.h"
#include "App.h"
#include "Move.h"
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *hard_work(void *vargp){
   int i = 0;
   while (1) {
      printf("update %d\n", i*10);
      sleep(10);
      i++;
   }
}


int start(struct App * app){
   move(100);
   rotate(25);
   printf("start %d\n", getpid());
   pthread_t thread_id;
   pthread_create(&thread_id, NULL, hard_work, NULL);
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