#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


int main() {
    int p1[2], p2[2], pid;
    char buffer[1000];

    pipe(p1);
    pipe(p2);

    pid = fork();

    if (pid == 0) {
        // p1[0] for read
        // p2[1] for write
        printf("in child process\n");
        while (1) {
            memset(buffer, 0, sizeof(buffer));
            read(p1[0], buffer, sizeof(buffer));
            for (int i = 0; i < strlen(buffer); i++) {
                if (islower(buffer[i])) {
                    buffer[i] -= 32;
                }
            }
            write(p2[1], buffer, sizeof(buffer));
        }

    } else {
        // p1[1] for write
        // p2[0] for read
        printf("in parrent process\n");
        while (1) {
            memset(buffer, 0, sizeof(buffer));
            fgets(buffer, sizeof(buffer), stdin);
            write(p1[1], buffer, sizeof(buffer));
            memset(buffer, 0, sizeof(buffer));
            read(p2[0], buffer, sizeof(buffer));
            printf("upper: %s", buffer);
        }
    }


    return 0;
}
