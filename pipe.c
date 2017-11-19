#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(void)
{
	int pfd[2];
	char buff[100];
	pipe(pfd);

	//Don't exchange 1 and 0
	printf("Write file descriptor of pipe is #%d\n", pfd[1]);
	write(pfd[1], "this is eric", 13);
	
	printf("reading from the file decriptor #%d\n", pfd[0]);
	read(pfd[0], buff, 13);
	
	printf("Read \"%s\" \n", buff);
	
	return 0;

}

