#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>


int main(int argc, char* argv[]) {
    pid_t chill;
    chill = fork();
    if(chill >= 0) {
        if(chill == 0 ) {
            printf("in chill\n");
            char buff;
            int file = open("./log/hello.txt", O_RDONLY);
            printf("file : %d\n",file);
            int eof;
            while(file != -1) {
                eof = read(file, &buff, 1);
                if(eof != 0) {
                    printf("%c", buff);
                } else {
                    printf("\n");
                    close(file);
                    break;
                }
            }

        } else {
            printf("in parrent\n");
            int file = open("./log/hello.txt", O_CREAT | O_WRONLY , 0666);
            printf("file: %d\n", file);
            char *buff = "tran gia luong";
            write(file, buff, strlen(buff));
            close(file);
        }
    } else {
        printf("can't create chill\n");
    }
    return 0;
}
