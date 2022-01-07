#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>


#define PORT_NUM 8000
#define SERVER_IP "192.168.78.132"

int main(int argc, char *argv[]) {
	int client_sd;
	struct sockaddr_in server_addr;
	char *message = {0};
	
	if(argc < 2) {
		printf("missing message!\n");
		exit(EXIT_FAILURE);
	} else {
		message = argv[1];
	}

	client_sd = socket(AF_INET, SOCK_STREAM, 0);
	if (client_sd == -1) {
		printf("create socket error!\n");
		exit(EXIT_FAILURE);
	}
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT_NUM);

	if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) == -1) {
		printf("Invalid address!\n");
		exit(EXIT_FAILURE);
	}

	if (connect(client_sd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
		printf("Connection failure!\n");
		exit(EXIT_FAILURE);
	}

	send(client_sd, message, strlen(message), 0);
	
	return 0;
}
