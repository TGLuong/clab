#include <sys/un.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>

#define SOCK_PATH "socket"


int main(int argc, char *argv[]) {
	struct sockaddr_un server_addr, client_addr;
	int server_fd, new_request;
	int len;
	char buffer[200];

	server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
	if (server_fd == -1) {
		printf("create server_fd error\n");
		exit(EXIT_FAILURE);
	}

	memset(&server_addr, 0, sizeof(struct sockaddr_un));
	server_addr.sun_family = AF_UNIX;
	strcpy(server_addr.sun_path, "socket");

	if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(struct sockaddr_un)) == -1) {
		printf("binding error\n");
		exit(EXIT_FAILURE);
	}
	
	if (listen(server_fd, 10) == -1) {
		printf("listen error\n");
		exit(EXIT_FAILURE);
	}

	printf("listen on %s\n", SOCK_PATH);

	while (1) {
		memset(&client_addr, 0, sizeof(struct sockaddr_un));
		int new_request = accept(server_fd, (struct sockaddr *) &client_addr, &len); 
		if (new_request == -1) {
			printf("accept error\n");
			exit(EXIT_FAILURE);
		}
		printf("accept request\n");
		read(new_request, buffer, 200);
		printf("buffer: %s\n", buffer);
	}
	return 0;
}
