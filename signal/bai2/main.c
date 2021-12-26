#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void siguser1() {
    printf("signal user 1\n");
}

void siguser2() {
    printf("signal user 2\n");
}


int main() {
    printf("PID: %d\n", getpid());
    signal(SIGUSR1, &siguser1);
    signal(SIGUSR2, &siguser2);
    sigset_t new_set, old_set;
    sigprocmask(SIG_SETMASK, NULL, &old_set);
    if(sigismember(&old_set, SIGINT) == 0) {
        printf("blocking SIGINT and sleep 5s\n");
        sigemptyset(&new_set);
        sigaddset(&new_set, SIGINT);
        sigprocmask(SIG_BLOCK, &new_set, &old_set);
        sleep(5);
    }
    sigprocmask(SIG_SETMASK, NULL, &old_set);
    if(sigismember(&old_set, SIGINT) == 1) {
        printf("unblocking SIGINT\n");
        sigemptyset(&new_set);
        sigaddset(&new_set, SIGINT);
        sigprocmask(SIG_UNBLOCK, &new_set, &old_set);
    }
    while(1);
    return 0;
}