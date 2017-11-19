#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msgbuf {
    long mtype;
    char mtext[200];
};

int main(void)
{
    struct my_msgbuf buf;
    int msqid;
    key_t key;
    
    key = ftok("eric", 'B');
    msqid = msgget(key, 0666|IPC_CREAT);

    int i = 10;

    while(i){
        msgrcv(msqid, &buf, sizeof(buf.mtext), 0, 0);
        printf("Message received: \"%s\"\n", buf.mtext);
        i--;
    }    

    return 0;
}