#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define PIPE "fifoserver"

int main(int argc, char *argv[]) {
	int fd;
	uint_8 read_size;
	char buffer[250];

	mkfifo(PIPE, 0666);

	while (1) {
		fd = open(PIPE, O_RDONLY);
		read(fd, &read_size, 2);
		printf("%d\n", read_size);
	}

	return 0;
}
