#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	pid_t pid;
	volatile int flag = 1;
	if(fork()==0) {
		//child
		printf("child : %d", getpid());
		while(flag);
		exit(0);
	}

	printf("parent: %d\n", getpid());
	while(flag);
	exit(0);
}



