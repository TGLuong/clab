#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

void funcWait() {
    printf("in funcWait\n");
    wait(NULL);
}

int main(void) {
    pid_t child_id = fork();
    if(child_id == 0) {
        printf("pid = %d\n", getpid());
        sleep(3);
    } else {
        signal(SIGCHLD, funcWait);
        printf("in parrent\n");
        while (1)
        {
            
        }
        
    }
}
