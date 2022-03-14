#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>




int main() {
    int fd;
    char message[250];
    strcpy(message, "hello abcd");


    fd = open("data.txt", O_APPEND | O_CREAT | O_RDWR, 0666);
    lseek(fd, 0, SEEK_SET);
    write(fd, message, strlen(message));
    close(fd);
    return 0;
}
