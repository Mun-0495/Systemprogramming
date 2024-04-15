#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char* myargs[] = {"./myspin", "10", NULL};
char* myenvs[] = {NULL};

int main(void) {
	printf("before exec\n");
	if(exceve(myargs[0], myargs, myenvs) < 0) {
		printf("%s: Command not found\n", myargs[0]);
		exit(1);
	}
	printf("after exec\n");
	return 0;
}

