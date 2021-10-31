#ifndef CMD
#define CMD

#define CMDSTOP 0
#define CMDSTART 1
#define CMDPAUSE 2
#define CMDRESUME 3


typedef struct Cmd
{
    char * package_id;
    int command;
} Cmd;

int readcmd(Cmd * cmd);

#endif