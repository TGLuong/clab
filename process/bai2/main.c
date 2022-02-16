#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
    int B_status, C_status, BB_status, CC_status;
    pid_t B_process, C_process, BB_process, CC_process;
    B_process = fork();
    C_process= fork();
    if(B_process == 0) {
        printf("in B Process, pid = %d\n", getpid());
        exit(0);
    }
    if(C_process == 0) {
        printf("in C Process, pid = %d\n", getpid());
        exit(0);
    }
    pid_t waitB = waitpid(B_process, &B_status, 0);
    printf("in parrent\n");
}
