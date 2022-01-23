#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	struct sockaddr_un server_sock;
	int fd;
	char buffer[200];

	fd = socket(AF_UNIX, SOCK_STREAM, 0);

	memset(&server_sock, 0, sizeof(struct sockaddr_un));
	server_sock.sun_family = AF_UNIX;
	strcpy(server_sock.sun_path, "socket");

	if (connect(fd, (struct sockaddr *) &server_sock, sizeof(struct sockaddr)) != 0) {
		printf("connect to server error!\n");
		exit(EXIT_FAILURE);
	}
	
	memset(buffer, 0, 200);
	strcpy(buffer, "haha");
	printf("sent: %s\n", buffer);
	write(fd, buffer, 200);

	return 0;
}
