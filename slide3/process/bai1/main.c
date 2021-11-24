#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    pid_t chill_process;
    chill_process = fork();
    if(chill_process>=0) {
        if(chill_process != 0) {
            printf("this is parrent process : id = %d\n", getpid());
        } else {
            printf("this is chill process : id = %d , parrent id = %d\n", getpid(), getppid());
        }
    } else {
        printf("can't create chill process!\n");
    }
    return 0;
}