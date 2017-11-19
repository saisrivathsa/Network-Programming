#include <stdio.h>

int main(int argc, char* argv[]){
	printf("argc is %d\n", argc);
        int n = argc;
	while(argc){
                printf("%dth argv is %s \n", n-argc,argv[n-argc]);
                argc--;
        }
	return 0;
}
