#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>



int main() {
    int fd = open("data.txt", O_CREAT | O_WRONLY | O_APPEND, 0666);

    if (fd == -1) {
        printf("open file error\n");
        exit(0);
    }

    int copy_fd = dup(fd);

    int dup2_fd = dup2(fd, 100);

    printf("fd = %d, dup = %d, dup2 = %d\n", fd, copy_fd, dup2_fd);

    write(fd, "this is fd.", 11);
    write(copy_fd, "this is copy fd.", 16);
    write(dup2_fd, "this is dup2 fd.", 16);

    return 0;
}
