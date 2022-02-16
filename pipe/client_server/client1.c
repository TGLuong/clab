#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SERVER_PIPE "fifoserver"

int main(int argc, char *argv[]) {
	int fd;
	uint_8 byte_send;
	scanf("%d", &byte_send);
	printf("%d", byte_send);
	return 0;
}
