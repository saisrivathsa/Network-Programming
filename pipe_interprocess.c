#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {

    int pip[2];
    pid_t childpid;
    char str[100]; 
    
    pipe(pip);  
    
    if ( (childpid = fork() ) == 0) {
        close(pip[1]);
        // child closes write end
        read(pip[0], str, 10);
        printf("child read %s\n",str);
        exit(0);
    }
    
    close(pip[0]);
    write(pip[1], "hello how", 10);
    // parent closes read end
    
    waitpid(childpid, NULL, 0);
    exit(0);

}


