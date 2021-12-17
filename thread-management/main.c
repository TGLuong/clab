#include <stdio.h>
#include <pthread.h>

pthread_t thread_1, thread_2, thread_3;


void *thread_handler_1(void *param) {
    printf("hello thread 1\n");
}

void *thread_handler_2(void *param) {
    printf("hello thread 2\n");
}

void *thread_handler_3(void *param) {
    printf("hello thread 3\n");
}

int main(int argc, char *argv[]) {
    pthread_create(&thread_1, NULL, &thread_handler_1, NULL);
    pthread_create(&thread_2, NULL, &thread_handler_2, NULL);
    pthread_create(&thread_3, NULL, &thread_handler_3, NULL);
    while(1);
}