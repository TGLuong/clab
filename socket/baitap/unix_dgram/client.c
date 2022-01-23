#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>

#define SOCK_FILE "socket"
#define BUFF_SIZE 200

int main(int argc, char *argv[]) {
	struct sockaddr_un server_addr;
	int server_fd;

	server_fd = socket(AF_UNIX, SOCK_DGRAM, 0);
	if (server_fd == -1) {
		printf("create socket error\n");
		exit(EXIT_FAILURE);
	}

	server_addr.sun_family = AF_UNIX;
	strncpy(server_addr.sun_path, SOCK_FILE, sizeof(SOCK_FILE));
	
	int a = sendto(server_fd, "haha", 4, 0, (struct sockaddr *) &server_addr, sizeof(server_addr));
	printf("send %d byte\n", a);
	if (a == -1) {
		printf("error\n");
	}
	return 0;
}
