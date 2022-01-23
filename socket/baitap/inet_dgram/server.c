#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ctype.h>


int main(int argc, char *argv[]) {
	struct sockaddr_in server_addr, client_addr;
	int server_fd, client_fd, len, num_bytes;
	char buffer[200];

	server_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (server_fd == -1) {
		printf("create socket error\n");
		exit(EXIT_FAILURE);
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(5000);
	server_addr.sin_addr.s_addr = INADDR_ANY;

	
	if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
		printf("binding error\n");
		exit(EXIT_FAILURE);
	}

	while (1) {
		memset(buffer, 0, sizeof(buffer));
		num_bytes = recvfrom(server_fd, buffer, 200, 0, (struct sockaddr *) &client_addr, &len);
		printf("nun bytes: %d\n", num_bytes);
		printf("message = %s\n", buffer);
	}

	return 0;
}
