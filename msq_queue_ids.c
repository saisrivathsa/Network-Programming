#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(){
	int i, msqid;
	for(i = 0; i < 10; i++) {
    	msqid = msgget(IPC_PRIVATE, 0200 | IPC_CREAT);
    	printf("msqid = %d\n", msqid);
    	//msgctl(msqid, IPC_RMID, NULL);
    }

	exit(0);
}