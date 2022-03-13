#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>


pthread_mutex_t mutex;
int linux_count = 0, microsoft_count = 0;
static sem_t sem_linux, sem_microsoft;


static void *linux_arrive(void *param) {
    pthread_mutex_lock(&mutex);
    linux_count++;
    if (linux_count >= 4) {
        printf("have %d linux, and %d microsoft employee\n", linux_count, microsoft_count);
        sem_post(&sem_linux);
        sem_post(&sem_linux);
        sem_post(&sem_linux);
        linux_count -= 4;
        printf("4 linux employee cross river, %d linux and %d microsoft is waiting\n", linux_count, microsoft_count);
        pthread_mutex_unlock(&mutex);
        return NULL;
    }
    else if (linux_count >= 2 && microsoft_count >= 2) {
        printf("have %d linux, and %d microsoft employee\n", linux_count, microsoft_count);
        sem_post(&sem_microsoft);
        sem_post(&sem_microsoft);
        sem_post(&sem_linux);
        linux_count -= 2;
        microsoft_count -= 2;
        printf("2 linux and 2 microsoft employee cross river, %d linux and %d microsoft is waiting\n", linux_count, microsoft_count);
        pthread_mutex_unlock(&mutex);
        return NULL;
    }
    pthread_mutex_unlock(&mutex);
    sem_wait(&sem_linux);
    return NULL;
}

static void *microsoft_arrive(void *param) {
    pthread_mutex_lock(&mutex);

    microsoft_count++;
    if (microsoft_count >= 4) {
        printf("have %d linux and %d microsoft employee\n", linux_count, microsoft_count);
        sem_post(&sem_microsoft);
        sem_post(&sem_microsoft);
        sem_post(&sem_microsoft);
        microsoft_count -= 4;
        printf("4 microsoft employee cross river, %d linux and %d microsoft is waiting\n", linux_count, microsoft_count);
        pthread_mutex_unlock(&mutex);
        return NULL;
    }
    else if (linux_count >= 2 && microsoft_count >= 2) {
        printf("have %d linux and %d microsoft employee\n", linux_count, microsoft_count);
        sem_post(&sem_linux);
        sem_post(&sem_linux);
        sem_post(&sem_microsoft);
        linux_count -= 2;
        microsoft_count -= 2;
        printf("2 linux and 2 microsoft employee cross river, %d linux and %d microsoft is waiting\n", linux_count, microsoft_count);
        pthread_mutex_unlock(&mutex);
        return NULL;
    }
    pthread_mutex_unlock(&mutex);
    sem_wait(&sem_microsoft);
    return NULL;
}

int main() {
    sem_init(&sem_linux, 0, 4);
    sem_init(&sem_microsoft, 0, 4);
    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i <4; i++) {
        pthread_t thread;
        pthread_create(&thread, NULL, &linux_arrive, NULL);
    }
    for (int j = 0; j < 4; j++) {
        pthread_t thread;
        pthread_create(&thread, NULL, &microsoft_arrive, NULL);
    }
    while (1) sleep(1);
    return 0;
}
