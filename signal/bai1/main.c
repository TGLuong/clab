#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void signal_handle(int signal) {
    printf("in signal handle num = %d\n", signal);
}

int main() {
    signal(SIGINT, &signal_handle);
    printf("PID: %d\n", getpid());
    while(1);
    return 0;
}