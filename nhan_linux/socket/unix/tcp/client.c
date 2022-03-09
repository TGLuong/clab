#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>


#define SOCK_PATH "sock_stream"

int main() {
	int server_fd;
	struct sockaddr_un server_addr;
	char buffer[250];

	server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
	if (server_fd == -1) {
		fprintf(stderr, "create socket error\n");
		exit(1);
	}
	
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sun_family = AF_UNIX;
	strncpy(server_addr.sun_path, SOCK_PATH, strlen(SOCK_PATH));
	if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
		fprintf(stderr, "connect error\n");
		exit(1);
	}

	while (1) {
		printf("client: ");
		fgets(buffer, sizeof(buffer), stdin);
		write(server_fd, buffer, strlen(buffer));
		read(server_fd, buffer, sizeof(buffer));
		printf("server: %s", buffer);
	}

	return 0;
}
