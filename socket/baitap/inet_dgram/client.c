#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>




int main(int argc, char *argv[]) {
	struct sockaddr_in server_addr;
	int server_fd;

	server_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (server_fd == -1) {
		printf("create socket error\n");
		exit(EXIT_FAILURE);
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(5000);
	if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) == -1) {
		printf("address invalid\n");
		exit(EXIT_FAILURE);
	}

	if (sendto(server_fd, "haha", 4, 0, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
		printf("send error\n");
		exit(EXIT_FAILURE);
	}
	

	return 0;
}
