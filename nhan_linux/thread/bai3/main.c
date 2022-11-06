#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void * thread_handler(void *param) {
    int *fd = (int *) param;
    char buffer[10];
    for (int i = 1; i < 100000; i++) {
        pthread_mutex_lock(&mutex);
        memset(buffer, 0, sizeof(buffer));
        sprintf(buffer, "%d\n", i);
        write(*fd, buffer, strlen(buffer));
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    int fd;
    pthread_t thread1, thread2;
    fd = open("file.txt", O_CREAT | O_RDWR, 0666);
    pthread_create(&thread1, NULL, thread_handler, &fd);
    pthread_create(&thread2, NULL, thread_handler, &fd);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
