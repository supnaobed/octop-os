#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/proc.h"
#define APPS_PATH "../apps/"

int launch(char *package_id){
    char app_path[30];
    strcpy(app_path, APPS_PATH);
    strcat(app_path, package_id);
    strcat(app_path, "/");
    strcat(app_path, "app");
    printf("%s\n", app_path);
    char *argv_list[] = {NULL};
    int status = execv(app_path, argv_list);
    return status;
}