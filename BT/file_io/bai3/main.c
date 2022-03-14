#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, const char *argv[]) {
    int fd;
    char charac;

    if (strcmp(argv[2], "w") != 0 && strcmp(argv[2], "r") != 0) {
        printf("nhap tham so sai\n");
        exit(0);
    }
    if (strcmp(argv[2], "w") == 0) {
        if (argc < 4) {
            printf("ban chua nhap du so luong arg\n");
            exit(0);
        }

        fd = open(argv[1], O_CREAT | O_APPEND | O_WRONLY, 0666);
        write(fd, argv[3], strlen(argv[3]));
    } else {
        fd = open(argv[1], O_CREAT | O_RDONLY);
        while (read(fd, &charac, 1) != 0) {
            printf("%c", charac);
        }
        printf("\n");
    }
    close(fd);
    return 0;
}
