#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <signal.h>


pthread_t thread1, thread2;


void sign1(int sig) {
   printf("thead1\n"); 
}

void sign2(int sig) {
    printf("thead2\n");
}


void *thread_handler1(void *param) {
    signal(SIGINT, sign1);
    sigset_t new_set, old_set;
    sigemptyset(&new_set);

    sigaddset(&new_set, SIGINT);
    sigprocmask(SIG_BLOCK, &new_set, &old_set);

    sigpending(&new_set);

    if (sigismember(&new_set, SIGINT)) {
        printf("sigint is pending\n");
    } else {
        printf("sigint isn't pedding\n");
    }

    sleep(5);

    pthread_kill(thread2, SIGINT);

    sigpending(&new_set);

    if (sigismember(&new_set, SIGINT)) {
        printf("sigint is pending\n");
    } else {
        printf("sigint isn't pedding\n");
    }

    while(1);
    return NULL;
}

void *thread_handler2(void *param) {
    signal(SIGINT, sign2);
    sigset_t new_set, old_set;
    sigemptyset(&new_set);

    sigaddset(&new_set, SIGINT);
    sigprocmask(SIG_BLOCK, &new_set, &old_set);

    sigpending(&new_set);

    if (sigismember(&new_set, SIGINT)) {
        printf("sigint is pending\n");
    } else {
        printf("sigint isn't pedding\n");
    }

    sleep(5);

    pthread_kill(thread1, SIGINT);

    sigpending(&new_set);

    if (sigismember(&new_set, SIGINT)) {
        printf("sigint is pending\n");
    } else {
        printf("sigint isn't pedding\n");
    }
    
    while(1);
    return NULL;
} 

int main() {
    pthread_create(&thread1, NULL, thread_handler1, NULL);
    pthread_create(&thread2, NULL, thread_handler2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    return 0;
}
