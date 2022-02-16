#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define NAME_PIPE "name_pipe"

int main(int argc, char *argv[]) {
	char buffer[250];
	int fd;
	mkfifo(NAME_PIPE, 0666);
	
	while (1) {
		printf("message to consumer: ");
		memset(buffer, 0, 250);
		fgets(buffer, 250, stdin);
		
		fd = open(NAME_PIPE, O_WRONLY);
		write(fd, buffer, 250);
		close(fd);

		fd = open(NAME_PIPE, O_RDONLY);
		memset(buffer, 0, 250);
		read(fd, buffer, 250);
		printf("message from consumer: %s\n", buffer);
		close(fd);
	}
	return 0;
}
