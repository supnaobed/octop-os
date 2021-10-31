#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "include/cmd.h"
#include "include/proc.h"
#include "include/util.h"

#define MAX_PROC_COUNT 5

int start_p(char * package_id);
int stop_p(char * package_id);
int pause_p(char * package_id);
int resume_p(char * package_id);

Proc procs[MAX_PROC_COUNT];
int proc_num = 0;

int main(int argc, char const *argv[]){
    while(1) {
        Cmd cmd;
        int error = readcmd(&cmd);
        if (error < 0){
            printf("unable read cmd");
            exit(1);
        } else {
            printf("new command %s %d\n", cmd.package_id, cmd.command);
            if (cmd.command == CMDSTART) {
                start_p(cmd.package_id);
            } else if (cmd.command == CMDSTOP){
                stop_p(cmd.package_id);
            } else if (cmd.command == CMDPAUSE){
                pause_p(cmd.package_id);
            } else if (cmd.command == CMDRESUME){
                resume_p(cmd.package_id);
            }
        }
    }
    return 0;
}

int start_p(char * package_id){
    printf("start %s\n", package_id);
    int p = fork();
    if (p == 0){
        return launch(package_id);
    }
    if (proc_num >= MAX_PROC_COUNT) {
        proc_num = 0;
    }
    Proc proc = procs[proc_num];
    if (proc.package_id != NULL){
        stop_p(proc.package_id);
    }
    proc.package_id = package_id;
    proc.state = STRESUMED;
    proc.pid = p;
    printf("start %d\n", p);
    procs[proc_num] = proc;
    proc_num++;
    return p;
} 

int pause_p(char * package_id) {
    printf("pause %s\n", package_id);
    int index = find_index(procs, MAX_PROC_COUNT, package_id);
    if (index < 0) {
        return -1;
    }
    procs[index].state = STPAUSED;
    Proc proc = procs[index];
    printf("pause %s proc: %d\n", proc.package_id, proc.pid);
    kill(proc.pid, SIGSTOP);
    return 1;
}

int resume_p(char * package_id) {
    printf("resume %s\n", package_id);
    int index = find_index(procs, MAX_PROC_COUNT, package_id);
    if (index < 0) {
        return -1;
    }
    procs[index].state = STRESUMED;
    Proc proc = procs[index];
    kill(proc.pid, SIGCONT);
    return 1;
}

int stop_p(char * package_id){
    printf("stop %s\n", package_id);
    int index = find_index(procs, MAX_PROC_COUNT, package_id);
    if (index < 0) {
        return -1;
    }
    procs[index].state = STSTOPED;
    Proc proc = procs[index];

    printf("stop %s proc: %d\n", proc.package_id, proc.pid);
    kill(proc.pid, SIGKILL);
    return 0;
} 

