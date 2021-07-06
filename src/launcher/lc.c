#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <signal.h>

// Lifecycle control utils

#define APPS_PATH "./apps/"
#define PERMS 0644
#define CMND_LAUNCH "1"
#define CMND_TERM "0"

struct my_msgbuf
{
    long mtype;
    char mtext[200];
};

int launch(char *app_name);

int main()
{
    struct my_msgbuf buf;
    int msqid;
    int toend;
    key_t key;

    key = ftok("progfile1", 67);

    if ((msqid = msgget(key, PERMS)) == -1)
    {
        perror("msgget");
        exit(1);
    }

    for (;;)
    {
        if (msgrcv(msqid, &buf, sizeof(buf.mtext), 0, 0) == -1)
        {
            perror("msgrcv");
            exit(1);
        }
        if (strcmp(buf.mtext, CMND_TERM) == 0)
        {
            continue;
        }

        int p = fork();
        if (p == 0)
        {
            int p_new = fork();
            if (p_new == 0)
            {
                printf("start\n");
                launch(buf.mtext);
            }
            else
            {
                for (;;)
                {
                    if (msgrcv(msqid, &buf, sizeof(buf.mtext), 0, 0) == -1)
                    {
                        perror("msgrcv");
                        exit(1);
                    }
                    if (strcmp(buf.mtext, CMND_TERM) == 0)
                    {
                        printf("exit %d\n", p_new);
                        kill(p_new, SIGKILL);
                        continue;
                    }
                }
            }
            
        }
        else
        {
        }
    }
}

int launch(char *app_name)
{
    char app_path[30];

    strcpy(app_path, APPS_PATH);
    strcat(app_path, app_name);

    printf("[+]App in %s.\n", app_path);
    char *argv_list[] = {NULL};
    int status = execv(app_path, argv_list);
    printf("[+]App %d is \n", status);
    return 0;
}
