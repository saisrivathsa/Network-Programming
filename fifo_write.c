#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "eric"

int main(){

    char buff[300];
    int fd;

    mknod(FIFO_NAME, S_IFIFO|0666, 0);
    fd = open(FIFO_NAME, O_WRONLY);
    fgets(buff, 50, stdin);
    buff[strlen(buff)-1] = '\0';
    write(fd, buff, 50);
    printf("write complete\n");
    
    return 0;

}