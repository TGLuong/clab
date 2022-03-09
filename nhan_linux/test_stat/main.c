#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>


int main() {
	struct stat buffer;
	int fd, status;

	status = stat("test_file.txt", &buffer);

	printf("%d\n", status);
	printf("st_dev %ld\n", buffer.st_dev);
	printf("st_ino %ld\n", buffer.st_ino);
	printf("st_mode %o\n", buffer.st_mode);
	printf("st_nlink %ld\n", buffer.st_nlink);
	printf("st_uid %u\n", buffer.st_uid);
	printf("st_gid %u\n", buffer.st_gid);
	printf("st_rdev %ld\n", buffer.st_rdev);
	printf("st_size %ld\n", buffer.st_size);
	printf("st_blksize %ld\n", buffer.st_blksize);
	printf("st_blocks %ld\n", buffer.st_blocks);


	return 0;
}
