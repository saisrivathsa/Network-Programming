#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/wait.h>

void catcher(int signum) {
        printf("signal %d\n", signum);
}
int main (void){
        sigset_t newmask, oldmask;
        signal(SIGUSR1, catcher);
        sigemptyset(&newmask);
        sigaddset(&newmask, SIGUSR1);
        sigprocmask(SIG_SETMASK, &newmask, &oldmask);
        printf("set sigmask\n");
        kill(getpid(), SIGUSR1);
        printf("one\n");
        kill(getpid(), SIGUSR1);
        printf("two\n");
        kill(getpid(), SIGUSR1);
        printf("three\n");
        sigprocmask(SIG_SETMASK, &oldmask, NULL);
        printf("mask removed \n");
        wait(NULL);
}
