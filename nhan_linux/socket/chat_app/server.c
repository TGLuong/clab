#include <pthread.h>
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdint.h>

#define PORT_NUM 4000
#define LISTEN_BACKLOG 10

int register_list[10];
int register_size = 0;
char *user_list[10];
char *password_list[10];


void regist_service(int sockfd, char *user_name, char *password) {
	char *new_user = malloc(strlen(user_name));
	char *newpass = malloc(strlen(password));
	
	strncpy(new_user, user_name, sizeof(new_user));
	strncpy(newpass, password, sizeof(newpass));

	register_list[register_size] = sockfd;
	user_list[register_size] = new_user;
	password_list[register_size] = newpass;
	register_size++;
}

void broadcast(char *content, int user_fd) {
	char buffer[1000], name[100];
	uint16_t sent_byte;

	for (int i = 0; i < register_size; i++) {
		if (register_list[i] == user_fd) {
			strncpy(name, user_list[i], strlen(user_list[i]));
			break;
		}
	}

	memset(buffer, 0, sizeof(buffer));
	sprintf(buffer, "name:%s, content:%s", name, content);
	sent_byte = strlen(buffer);

	for (int i = 0; i < register_size; i++) {
		if (register_list[i] != user_fd) {
			write(register_list[i], &sent_byte, sizeof(sent_byte));
			write(register_list[i], buffer, sent_byte);	
		}
	}
}

int login_handler(int client_fd) {
	uint16_t receive_byte;
	char buffer[10000], user_name[100], password[100];
	printf("hand login from %d\n", client_fd);
	read(client_fd, &receive_byte, sizeof(receive_byte));
	memset(buffer, 0, sizeof(buffer));
	read(client_fd, buffer, receive_byte);
	sscanf(buffer, "user_name:%[^, ], password:%[^, ]", user_name, password);
	if (strcmp(password, "abc123") != 0) {
		printf("%s login fail\n", user_name);
		return 0;
	}
	printf("%s login sucess\n", user_name);
	regist_service(client_fd, user_name, password);
	return 1;
}


void *socket_handler(void *fun_arg) {
	int *client_fd = (int*)fun_arg, login_result;
	uint16_t sent_byte, receive_byte;
	char buffer[1000], type[100], content[1000];

	printf("accept client: %d\n", *client_fd);
	login_result = login_handler(*client_fd);
	if (login_result) {
		sprintf(buffer, "authorized");
		sent_byte = strlen(buffer);

		write(*client_fd, &sent_byte, sizeof(sent_byte));
		write(*client_fd, buffer, sent_byte);	

		while (1) {
			memset(buffer, 0, sizeof(buffer));
			memset(type, 0, sizeof(type));
			memset(content, 0, sizeof(content));

			read(*client_fd, &receive_byte, sizeof(receive_byte));
			read(*client_fd, buffer, receive_byte);

			sscanf(buffer, "type:%[^,], content:%[^,]", type, content);
			if (strcmp(type, "destroy") == 0) {
				break;
			}
			broadcast(content, *client_fd);
		}
	} else {
		sprintf(buffer, "unauthorized");
		sent_byte = strlen(buffer);
		write(*client_fd, &sent_byte, sizeof(sent_byte));
		write(*client_fd, buffer, sent_byte);
	}

	close(*client_fd);
}

int main() {
	int server_fd, len, otp;
	struct sockaddr_in server_addr, client_addr;

	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd == -1) {
		fprintf(stderr, "create socket error\n");
		exit(0);
	}

	memset(&server_addr, 0 , sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT_NUM);
	server_addr.sin_addr.s_addr = INADDR_ANY;
	otp = 1;
	setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &otp, sizeof(otp));

	if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
		fprintf(stderr, "binding error\n");
		exit(0);
	}

	if (listen(server_fd, LISTEN_BACKLOG) == -1) {
		fprintf(stderr, "listen error\n");
		exit(0);
	}

	printf("listening at port %d\n", PORT_NUM);

	while (1) {
		int *pclient_fd = malloc(sizeof(int));
		pthread_t thread;
		*pclient_fd = accept(server_fd, (struct sockaddr *)&client_addr, &len);
		if (*pclient_fd == -1) {
			fprintf(stderr, "accept error\n");
			exit(0);
		}
		pthread_create(&thread, NULL, socket_handler, pclient_fd);
	}

	return 0;
}
