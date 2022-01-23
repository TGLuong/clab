#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char *argv[]) {
	int fds[2];
	char buffer[250];
	
	if (pipe(fds) == -1) {
		printf("create pile error\n");
		exit(EXIT_FAILURE);
	}

	write(fds[1], "hello!", sizeof("hello!"));

	memset(buffer, 0, sizeof(buffer));
	read(fds[0], buffer, sizeof("hello!"));
	printf("%s\n", buffer);


	return 0;
}
