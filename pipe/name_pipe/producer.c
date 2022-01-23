#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define NAME_PIPE "name_pipe"

int main(int argc, char *argv[]) {
	char buffer[250];
	int fd;
	mkfifo(NAME_PIPE, 0666);
	
	while (1) {
		printf("message to consumer: ");
		fgets(buffer, 250, stdin);
		
		fd = open(NAME_PIPE, O_WRONLY);
		write(fd, buffer, 250);
		close(fd);

		fd = open(NAME_PIPE, O_RDONLY);
		read(fd, buffer, 250);
		close(fd);
	}
	return 0;
}
