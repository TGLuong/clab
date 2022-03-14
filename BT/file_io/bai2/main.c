#include <unistd.h>
#include <fcntl.h>

#define FILE "file.txt"

int main() {
    int fd1, fd2;

    fd1 = open(FILE, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR, 0666);
    fd2 = open(FILE, O_RDWR);

    write(fd1, "hello", 6);
    write(fd2, "world", 6);
    lseek(fd2, 0, SEEK_SET);
    write(fd1, "HELLO,", 6);
    write(fd2, "Gidday", 6);
    close(fd1);
    close(fd2);
    return 0;
}
