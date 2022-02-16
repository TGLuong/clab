#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

#define NAME_PIPE "name_pipe"

int main(int argc, char *argv[]) {
	int fd;
	char buffer[250];

	while(1){
		fd = open(NAME_PIPE, O_RDONLY);
		memset(buffer, 0, 250);
		read(fd, buffer, 250);

		printf("%s\n", buffer);

		close(fd);

		fd = open(NAME_PIPE, O_WRONLY);
		fgets(buffer, 250, stdin);
		write(fd, buffer, strlen(buffer));
		close(fd);

	}	
	return 0;
}
