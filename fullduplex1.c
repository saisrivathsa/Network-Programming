#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/types.h>

int main(){
	int fd[2], childpid;

	char c[6] = "hello";
	pipe(fd);
	if((childpid=fork())==0){
		//
		printf("child called \n");
		printf("child called read\n");
		read(fd[0], &c, 6);
		printf("child done read\n");
		
		printf("child read %s\n", c);
		
		printf("child called write\n");
		write(fd[0], "hello", 6);
		printf("child done write\n");
		
		_exit(0);
	}
	sleep(3);
	printf("parent called \n");

	printf("parent called write\n");
	write(fd[1], "prep ", 6);
	printf("parent done write\n");

	printf("parent called read\n");	
	read(fd[1], &c, 6);
	printf("parent done read\n");

	printf("parent read %s \n", c);

	_exit(0);
}
