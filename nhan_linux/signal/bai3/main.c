#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>



int partner_id;

void child_handler(int sign) {
	int fd;
	char buffer[255];
	printf("in child\n");
	sleep(1);
	kill(partner_id, SIGINT);
}

void parrent_handler(int sign) {
	printf("in parrent\n");
	sleep(3);
	kill(partner_id, SIGINT);
}

int main(int argc, char *argv[]) {
	int ppid, cid, status;

	cid = fork();
	if (cid == -1) {
		printf("can't create child process\n");
		exit(EXIT_FAILURE);
	}
	if (cid == 0) {
		signal(SIGINT, child_handler);
		printf("child pid: %d\n", getpid());
		partner_id = getppid();
		while (1);
	} else {
		signal(SIGINT, parrent_handler);
		printf("parrent pid: %d\n", getpid());
		partner_id = cid;
		wait(&status);
		while (1);
	}
	return 0;
}
