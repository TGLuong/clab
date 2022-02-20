#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

#define SERVER_PIPE "fifoserver"
#define CLIENT_PIPE "fifoclient2"

void clean_stdin(void) {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int main(int argc, char *argv[]) {
	int fd, service;
	uint16_t send_byte, status;
	char message[250], send_buffer[1000], key_request[8];

	mkfifo(CLIENT_PIPE, 0666);

	service = 8;
	strncpy(key_request, "1a4f", 4);

	while (1) {
		fd = open(SERVER_PIPE, O_WRONLY);
		scanf("%[^\n]", message);
		clean_stdin();
		sprintf(send_buffer, "%s\n%d\n%s\n%s", CLIENT_PIPE, service, key_request, message);
		send_byte = (uint16_t)strlen(send_buffer);
		write(fd, &send_byte, sizeof(send_byte));
		write(fd, send_buffer, send_byte);
		close(fd);
		fd = open(CLIENT_PIPE, O_RDONLY);
		read(fd, &status, sizeof(status));
		if (status == 0) {
			printf("tin hop le\n");
		} else {
			printf("tin khong hop le\n");
		}
		close(fd);
	}

	return 0;
}
