#ifndef PROC
#define PROC

#define STPAUSED 1
#define STRESUMED 0
#define STSTOPED 0


typedef struct Proc
{
    char * package_id;
    int pid;
    int state;
} Proc;

int find_index(struct Proc *procs, int count, char * package_id);

#endif
