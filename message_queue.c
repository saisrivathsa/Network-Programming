#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <mqueue.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


int main(int argc, char **argv){
	
	mqd_t mqd;
	struct mq_attr attr;
	if (argc != 2) {
		printf("error\n");
		exit(1);
	}
	mqd = mq_open(argv[1], O_RDONLY);
	mq_getattr(mqd, &attr);
	printf("max #msgs = %ld, max#bytes/msg = %ld, ""#currently on queue = %ld\n",attr.mq_maxmsg, attr.mq_msgsize,attr.mq_curmsgs);
	mq_close(mqd);
	exit(0);

}