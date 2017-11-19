#include<stdio.h>
#include<unistd.h>
 
int main(int argc, char* argv[])
{
    int i;
    printf("%s", argv[1]); 
    printf("I am EXEC.c called by execvp() ");
    printf("\n");
     
    //return 0;
}