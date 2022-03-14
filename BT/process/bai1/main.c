#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int sig) {
    printf("handler sign child\n");
}

void parent() {
    int status;
    

    sigset_t new_set, old_set;
    sigemptyset(&new_set);
    //sigprocmask(SIG_BLOCK, &new_set, &old_set);
    printf("parent wait\n");
    wait(&status);
}

void child() {
    printf("child sleep 5s\n");
    sleep(5);
}

int main() {
    int pid;
    signal(SIGCHLD, sig_handler);
    pid = fork();
    if (pid == 0) {
        parent();
    } else {
        child();
    }

    return 0;
}
