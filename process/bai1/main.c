#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>


int main(void) {
    int status;
    pid_t child_id = fork();
    if(child_id == 0) {
        printf("in child process, pid = %d, ppid = %d\n", getpid(), getppid());
        exit(3);
    } else {
        pid_t rm = wait(&status);
        printf("in parrent process, pid = %d, status = %d\n", getpid(), status);
    }
}