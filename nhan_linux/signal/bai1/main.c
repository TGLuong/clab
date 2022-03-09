#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sign_int_handle(int sign) {
	printf("hello sign int\n");
}

int main(int argc, char *argv[]) {
	signal(SIGINT, sign_int_handle);
	while(1);
	return 0;
}
