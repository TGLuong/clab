#include <stdio.h>
#include <pthread.h>

pthread_t thread_1;

static void *thread_handler(void *param) {
    while (1) {
        printf("hello\n");
    }
}

int main(int argc, char *argv[]) {
    int rev;
    if(rev = pthread_create(&thread_1, NULL, &thread_handler, NULL)) {
        printf("err");
    } 
    return 0;
}