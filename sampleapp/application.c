#include "AppDelegate.h"
#include "App.h"
#include <stdio.h>


int start(struct App * app){
   printf("start\n");
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