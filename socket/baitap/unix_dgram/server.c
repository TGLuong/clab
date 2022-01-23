#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>


#define SOCK_FILE "socket"
#define BUFF_SIZE 200

int main(int argc, char * argv[]) {
	struct sockaddr_un server_addr, client_addr;
	int server_fd, len, num_bytes;
	char buffer[BUFF_SIZE];

	server_fd = socket(AF_UNIX, SOCK_DGRAM, 0);
	if (server_fd == -1) {
		printf("create socket error");
		exit(EXIT_FAILURE);
	}

	server_addr.sun_family = AF_UNIX;
	strncpy(server_addr.sun_path, SOCK_FILE, sizeof(SOCK_FILE));

	if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
		printf("bindding error\n");
		exit(EXIT_FAILURE);
	}
	printf("start listening\n");
	while (1) {
		memset(buffer, 0, sizeof(buffer));
		num_bytes = recvfrom(server_fd, buffer, BUFF_SIZE, 0, (struct sockaddr *) &client_addr, &len);
		if (num_bytes == -1) {
			printf("error\n");
			exit(EXIT_FAILURE);
		}
		printf("so byte nhan duoc : %d\n", num_bytes);
		printf("message: %s\n", buffer);
	}


	return 0;
}
