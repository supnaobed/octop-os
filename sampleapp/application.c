#include "AppDelegate.h"
#include "App.h"
#include <stdio.h>
#include <unistd.h>

int start(struct App * app){
   printf("start\n");
   int i = 0;
   while (1) {
      printf("update %d\n", i);
      sleep(5);
      i++;
   }
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