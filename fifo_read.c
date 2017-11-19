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
    fd = open(FIFO_NAME, O_RDONLY);
    read(fd, buff, 13);
    printf("Read this from fifo \"%s\" \n", buff);
    
    return 0;

}