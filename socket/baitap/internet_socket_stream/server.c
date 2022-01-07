#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_NUMBER 8000
#define NUM_REQUEST 10


int main(int argc, int argv[]) {
	int server_fd, sock_request, len, opt;
	struct sockaddr_in address, client;
	char message[255], buffer[1000];
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd == -1) {
		printf("create socket error\n");
		exit(EXIT_FAILURE);
	}
	
	opt = 1;
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
		printf("setsockopt error!");
		exit(EXIT_FAILURE);
	}

	address.sin_family = AF_INET;
	address.sin_port = htons(PORT_NUMBER);
	address.sin_addr.s_addr = INADDR_ANY;

	if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) == -1) {
		printf("binding error\n");
		exit(EXIT_FAILURE);
	}

	if (listen(server_fd, NUM_REQUEST) < 0) {
		printf("listen error\n");
		exit(EXIT_FAILURE);
	}
	
	while (1) {
		len = 0;
		printf("new request:\n");
		sock_request = accept(server_fd, (struct sockaddr *) &client, &len);
		if (sock_request == -1) {
			printf("accept error!\n");
		}
		read(sock_request, buffer, 1000);
		puts(buffer);
		char *response = "HTTP/1.1 200";
		write(sock_request, response, strlen(response));
		close(sock_request);
	}

	return 0;
}
