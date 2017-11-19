#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
        pid_t pid;
        int status;
       
        if ((pid = fork()) < 0)
               printf("fork error\n\n");
       
        else if (pid == 0){
                printf("child called \n\n");
                //exit(7);
        }
        else{
                printf("pid of parent  is %d\n", pid);
                printf("parent called \n\n");
        }
        
        if(pid==0)
                printf("calling wait in child\n\n");
        else
                printf("calling wait in parent\n\n");
       
        pid_t sample = wait(&status); 
        if (sample != pid)
        {
               printf("wait error\n");
               printf("sample value is %d\n", sample);
               printf("pid in child wait error is %d\n\n", pid);
        }
        else{
                
                if(pid==0)
                        printf("pid in wait child is %d\n\n", pid);
        
                else
                        printf("pid in wait parent is %d\n\n", pid);
                 
        }


        printf("%x\n",status);
        
        exit(0);
}
