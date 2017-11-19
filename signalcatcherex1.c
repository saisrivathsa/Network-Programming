#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void catcher(int sig){
        printf("signal received\n");
        sleep(5);
}

int main(){
        int x = getpid();
        printf("%d\n", x);
        signal(SIGINT, catcher);
        printf("sleeping \n");
        sleep(20);
        printf("sleep done\n");
        printf("sleeping \n");
        sleep(20);
        printf("sleep done\n");
        return 0;
}
