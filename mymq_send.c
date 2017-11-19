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
    
    buf.mtype = 1;
    
    key = ftok("eric", 'B');
    msqid = msgget(key, 0666|IPC_CREAT);
    
    printf("Text input:\n");
    int i = 10;

    while(i){
        fgets(buf.mtext, sizeof(buf.mtext), stdin);
        int len = strlen(buf.mtext);
        buf.mtext[len-1]='\0';
        msgsnd(msqid, &buf, len+1, 0);
        printf("Write the next message...\n");
        i--;
    }    

    if(msgctl(msqid, IPC_RMID, NULL)!=-1) 
        printf("Message queue has been deleted\n");

    return 0;
}