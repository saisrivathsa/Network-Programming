#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void catcher(int i){
        printf("hello");
}

int main(){
        signal(SIGINT, catcher);
        printf("in main\n");
        sigset_t newmask, oldmask;
        sigemptyset(&newmask);
        if (sigaddset(&newmask, SIGINT) == 0) printf("ok\n");
        sigprocmask(SIG_SETMASK, &newmask, &oldmask);
        sleep(20);
}
