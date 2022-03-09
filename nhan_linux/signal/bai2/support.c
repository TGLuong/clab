#include <stdlib.h>
#include <signal.h>
#include <stdio.h>


int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("nhap khong du tham so");
	}
	int pid = atoi(argv[1]);
	kill(pid, SIGINT);
	return 0;
}
