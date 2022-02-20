#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>
#include <fcntl.h>

#define PIPE "fifoserver"

int main(int argc, char *argv[]) {
	int fd, service, chat_service = 8;
	uint16_t send_byte, status;
	char message[250], send_buffer[1000], key_request[250], chat_key_request[8], fifo_name[250];

	mkfifo(PIPE, 0666);
	strncpy(chat_key_request, "1a4f\0", 5);

	while (1) {
		fd = open(PIPE, O_RDONLY);
		read(fd, &send_byte, sizeof(send_byte));
		memset(send_buffer, 0, sizeof(send_buffer));
		read(fd, send_buffer, send_byte);
		sscanf(send_buffer, "%s\n%d\n%s\n%[^\n]", fifo_name, &service, key_request, message);
		close(fd);
		fd = open(fifo_name, O_WRONLY);
		if (service == chat_service && strcmp(key_request, chat_key_request) == 0) {
			status = 0;
			printf("%s: %s\n", fifo_name, message);
			write(fd, &status, sizeof(status));
		} else {
			status = 1;
			printf("tu choi dich vu: %s, service: %d - %d, key: %s - %s\n", fifo_name, service, chat_service, key_request, chat_key_request);
			write(fd, &status, sizeof(status));
		}
		close(fd);
	}

	return 0;
}
