#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/types.h>

int main()
{ 
    int p1[2],p2[2],i;
    char buf[5];
    pipe(p1);
    pipe(p2);
        if(fork()==0)
        {
                printf("\nthis is child(the input text is text)\n");
                close(p1[0]);
                close(p2[1]);
                printf("before write child\n");
                write(p1[1],"hell",5);
                printf("after write child\n");
                printf("before read child\n");
                read(p2[0],buf,5);
                printf("after read child\n");
                write(1,buf,5);
                printf("\nchild is done\n");
        }
        else
        {
                printf("\nthis is parent(the output text is text)\n");
                close(p2[0]);
                close(p1[1]);
                printf("before read parent\n");
                read(p1[0],buf,5);
                printf("After read parent\n");
                printf("before write parent\n");
                write(p2[1],buf,5);
                printf("after write parent\n");
                printf("\nparent is done\n");
        }
        return 0;
}
