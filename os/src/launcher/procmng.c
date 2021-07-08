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
#define MAX_SIZE 100

typedef struct my_msgbuf
{
    long mtype;
    char mtext[MAX_SIZE];
} message;

int launch(char *app_name);
int send_app_msg(char *app_name, message m);

int main()
{
    struct my_msgbuf buf;
    int msqid;
    int toend;
    key_t key;

    system("touch porcmng.ipc");

    if ((key = ftok("porcmng.ipc", 65)) == -1) {
      perror("ftok");
      exit(1);
   }

    if ((msqid = msgget(key, PERMS)) == -1) {
        perror("[-](Process manager) queue error");
        exit(1);
    }
    printf("[+](Process manager) started\n");
    for (;;)
    {
        if (msgrcv(msqid, &buf, sizeof(buf.mtext), 0, 0) == -1)
        {
            perror("[-](Process manager) enqueue error\n");
            exit(1);
        }
        if (strcmp(buf.mtext, CMND_TERM) == 0)
        {
            continue;
        }

        int p = fork();
        if (p < 0)
        {
            printf("[-](Process manager) fork error\n");
            exit(1);
        }
        else if (p == 0)
        {
            char *app_name = buf.mtext;
            int pid_app = fork();
            if (pid_app == 0)
            {
                int status = launch(app_name);
                if (status < 0){
                    printf("[-](Process manager) launch error\n");
                    kill(pid_app, SIGKILL);
                    continue;
                } 
            }
            else
            {
                for (;;)
                {
                    if (msgrcv(msqid, &buf, sizeof(buf.mtext), 0, 0) == -1)
                    {
                        printf("[-](Process manager)[APP %d]listern lifecycle error\n", pid_app);
                        perror("[-](Process manager) listern lifecycle error\n");
                        exit(1);
                    }
                    if (strcmp(buf.mtext, CMND_TERM) == 0)
                    {

                        message m;
                        m.mtype = 1;
                        strcpy(m.mtext, "0");
                        send_app_msg(app_name, m);

                        printf("[+](Process manager)[APP %d]close app\n", pid_app);
                        kill(pid_app, SIGKILL);
                        continue;
                    }
                }
            }
        }
        else
        {
            printf("[+](Process manager) start new app %d\n", getpid());
        }
    }
}

int send_app_msg(char *app_name, message m)
{
    key_t key;
    int msgid;

    system(app_name);

    key = ftok(app_name, 0);
    msgid = msgget(key, PERMS | IPC_CREAT);
    fgets(m.mtext, MAX_SIZE ,stdin);  
    int status = msgsnd(msgid, &m, sizeof(message), 0);  
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
