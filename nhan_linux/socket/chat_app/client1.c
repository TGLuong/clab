#include <signal.h>
#include <stdint.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define PORT_NUM 4000
#define SERVER_ADDR "127.0.0.1"

int server_fd;
pthread_t receive_thread, sent_thread;
pthread_mutex_t print_mutex;

static void *receive_message(void *fun_arg) {
	int *server_fd = (int*)fun_arg;
	uint16_t receive_byte;
	char buffer[1000], name[100], content[1000];
	while (1) {
		memset(buffer, 0, sizeof(buffer));
		memset(name, 0, sizeof(name));
		memset(content, 0, sizeof(content));

		read(*server_fd, &receive_byte, sizeof(receive_byte));
		read(*server_fd, buffer, receive_byte);

		sscanf(buffer, "name:%[^,], content:%[^,]", name, content);
		printf("mes from %s: %s\n", name, content);

	}
}

static void *sent_message(void *fun_arg) {
	int *server_fd = (int*)fun_arg;
	uint16_t sent_byte;
	char message[1000], buffer[10000];
	while (1) {
		memset(message, 0, sizeof(message));
		memset(buffer, 0, sizeof(buffer));
		
		fgets(message, sizeof(message), stdin);
		message[strlen(message) - 1] = 0;
		sprintf(buffer, "type:message, content:%s", message);

		sent_byte = strlen(buffer);
		write(*server_fd, &sent_byte, sizeof(sent_byte));
		write(*server_fd, buffer, sent_byte);
	}
}

int login(int server_fd) {
	uint16_t sent_byte, receive_byte;
	char buffer[1000], user_name[100], password[100];

	printf("username: ");
	fgets(user_name, sizeof(user_name), stdin);
	user_name[strlen(user_name) - 1] = 0;
	printf("password: ");
	fgets(password, sizeof(password), stdin);
	password[strlen(password) - 1] = 0;
	sprintf(buffer,"user_name:%s, password:%s", user_name, password);
	sent_byte = strlen(buffer);
	
	write(server_fd, &sent_byte, sizeof(sent_byte));
	write(server_fd, buffer, sent_byte);
	read(server_fd, &receive_byte, sizeof(receive_byte));
	memset(buffer, 0, sizeof(buffer));
	read(server_fd, buffer, receive_byte);
	if (strcmp(buffer, "authorized") == 0) {
		return 1;
	} else { 
		return 0;
	}
}

void hand_sigint(int sig) {
	char buffer[1000];
	uint16_t sent_byte;

	sprintf(buffer, "type:destroy, content:");
	sent_byte = strlen(buffer);

	write(server_fd, &sent_byte, sizeof(sent_byte));
	write(server_fd, buffer, sent_byte);
	exit(0);
}

void init_signal() {
	signal(SIGINT, &hand_sigint);
}

int main() {
	int status, login_status;
	struct sockaddr_in server_addr;

	init_signal();
	
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd == -1) {
		fprintf(stderr, "create socket error\n");
		exit(0);
	}

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT_NUM);
	if (inet_pton(AF_INET, SERVER_ADDR, &server_addr.sin_addr) == -1) {
		fprintf(stderr, "server_addr fail\n");
		exit(0);
	}

	status = connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	if (status == -1) {
		fprintf(stderr, "connect error\n");
		exit(0);
	}

	printf("connect to server!\n");
	login_status = login(server_fd);
	if (login_status) {
		printf("login success\n");
		pthread_create(&receive_thread, NULL, receive_message, &server_fd);
		pthread_create(&sent_thread, NULL, sent_message, &server_fd);
		while (1) sleep(1);
	} else {
		printf("login failure\n");
	}

	return 0;
}
