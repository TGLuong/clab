#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

int main(void) {
    clock_t start, end;
    start = clock();
    int fileA = open("fileA.txt", O_RDWR|O_CREAT);
    int fileB = open("fileB.txt", O_RDWR|O_CREAT);
    for(int i = 0; i < 1000000; i++) {
        char string[20];
        sprintf(string, "%d\n", i);
        write(fileA, string, strlen(string));
        write(fileA, "\n", 1);
    }
    close(fileA);
    for(int i = 0; i < 1000000; i++) {
        char string[20];
        sprintf(string, "%d\n", i);
        write(fileB, string, strlen(string));
        write(fileB, "\n", 1);
    }
    close(fileB);
    end = clock();
    printf("thoi gian thuc hien %f\n", ((double)(end - start)/CLOCKS_PER_SEC));
    return 0;
}
