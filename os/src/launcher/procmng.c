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
#define MAX_SIZE 200

typedef struct my_msgbuf
{
    long mtype;
    char mtext[MAX_SIZE];
} message;

int launch(char *app_name);
int send_app_msg(char *app_name, message m, int pid);

int main()
{
    struct my_msgbuf buf;
    int msqid;
    int toend;
    key_t key;

    if ((key = ftok("procmng.ipc", 65)) == -1)
    {
        perror("ftok");
        exit(1);
    }

    if ((msqid = msgget(key, PERMS)) == -1)
    {
        perror("[-](Process manager) queue error");
        exit(1);
    }
    if (msgrcv(msqid, &buf, sizeof(buf.mtext), 0, 0) == -1)
    {
        perror("[-](Process manager) listern lifecycle error\n");
        exit(1);
    }
    printf("[+](Process manager) started\n");
    char *app_name = "";
    int pid_app;
    int msqid_app = 0;
    for (;;)
    {
        if (msgrcv(msqid, &buf, sizeof(buf.mtext), 0, 0) == -1)
        {
            perror("[-](Process manager) listern lifecycle error\n");
            exit(1);
        }
        if (strcmp(buf.mtext, CMND_TERM) == 0 && msqid_app != 0 && strcmp(app_name, "") != 0)
        {

            message m;
            m.mtype = 23;
            strcpy(m.mtext, "0");
            send_app_msg(app_name, m, msqid_app);
            sleep(3);
            printf("[+](Process manager)[APP %d]close app\n", pid_app);
            kill(pid_app, SIGKILL);
            continue;
        }

        else
        {
            app_name = buf.mtext;
            key_t key;
            key = ftok(app_name, 0);
            if ((msqid_app = msgget(key, IPC_CREAT | 0666)) < 0)
            {
                perror("[-](Process manager)");
                exit(1);
            }
            int p = fork();
            if (p == 0)
            {
                int app_id = getpid();
                printf("[+](Child manager) start new app %d\n", app_id);
                int status = launch(app_name);

                if (status < 0)
                {
                    printf("[-](Process manager) launch error\n");
                    kill(app_id, SIGKILL);
                    continue;
                }
            }
            else
            {
                pid_app = p;
                printf("[+](Process manager) start new app %d\n", p);
            }
        }
    }
}

int send_app_msg(char *app_name, message m, int msqid)
{
    int status;
    if ((status = msgsnd(msqid, &m, sizeof(long) + (strlen(m.mtext) * sizeof(char)) + 1, IPC_NOWAIT)) < 0)
    {
        perror("[-](Process manager)");
        exit(1);
    }
    return status;
}

int launch(char *app_name)
{
    char app_path[30];
    strcpy(app_path, APPS_PATH);
    strcat(app_path, app_name);
    char *argv_list[] = {NULL};
    int status = execv(app_path, argv_list);
    return status;
}
