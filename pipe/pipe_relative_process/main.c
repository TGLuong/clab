#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int pipe_fds[2];
	int BUFFER_SIZE = 10;
	pid_t child_id;


	if (pipe(pipe_fds) == -1) {
		printf("create pipe error!\n");
		exit(EXIT_FAILURE);
	}

	child_id = fork();

	if (child_id != -1) {
		if (child_id == 0) {
			// in child process
			char buffer[BUFFER_SIZE];

			printf("In child\n");
			
			if (close(pipe_fds[1]) == -1) {
				printf("close write error\n");
			}

			while(read(pipe_fds[0], buffer, BUFFER_SIZE) != 0) {
				printf("%s\n", buffer);
			}

			printf("exit pipe");

		} else {
			// in parrent process
			char buffer[BUFFER_SIZE];

			printf("In parrent\n");
			
			if (close(pipe_fds[0]) == -1) {
				printf("close read error\n");
				exit(EXIT_FAILURE);
			}

			memset(buffer, 0, BUFFER_SIZE);
			strcpy(buffer, "hello");
			for (int i = 0; i < 5; i++) {
				write(pipe_fds[1], buffer, BUFFER_SIZE);
			}

			while(1);
		}
	} else {
		printf("fork error!\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}
