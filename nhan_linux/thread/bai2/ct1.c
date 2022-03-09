#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>


void create_file(int i) {
	char file_name[10], buffer[10];
	int fd;
	sprintf(file_name, "file%d.txt", i);
	fd = open(file_name, O_CREAT|O_RDONLY, S_IRWXU);
	for (int j = 1; j <= 5000000; j++) {
		sprintf(buffer, "%d\n", j);
		write(fd, buffer, strlen(buffer));
	}
	close(fd);
}

int main(int argc, char * argv[]) {
	int time1, time2;
	
	time1 = time(NULL);

	for (int i = 1; i <= 10; i++) {
		printf("file %d\n", i);
		create_file(i);
	}

	time2 = time(NULL);

	printf("thoi gian thuc hien: %ds\n", time2 - time1);
	return 0;
}
