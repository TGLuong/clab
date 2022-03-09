#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <sys/un.h>

#define UNIX_SOCK "sock_stream"
#define backlog 5


int main() {
	int server_fd, request_fd, server_len;
	struct sockaddr_un server_addr, client_addr;
	char message[250];

	server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
	if (server_fd == -1) {
		fprintf(stderr, "create socket fail\n");
		exit(EXIT_FAILURE);
	}

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sun_family = AF_UNIX;
	strncpy(server_addr.sun_path, UNIX_SOCK, strlen(UNIX_SOCK));

	if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
		fprintf(stderr, "binding error\n");
		exit(EXIT_FAILURE);
	}

	if (listen(server_fd, backlog) == -1) {
		fprintf(stderr, "listen fail\n");
		exit(EXIT_FAILURE);
	}
	request_fd = accept(server_fd, (struct sockaddr *)&client_addr, &server_len);
	if (request_fd == -1) {
		fprintf(stderr, "accept error\n");
		exit(EXIT_FAILURE);
	}

	while (1) {
		memset(message, 0, sizeof(message));
		read(request_fd, message, sizeof(message));
		printf("client: %s", message);
		printf("server: ");
		fgets(message, sizeof(message), stdin);
		write(request_fd, message, strlen(message));
	}



	return 0;
}
