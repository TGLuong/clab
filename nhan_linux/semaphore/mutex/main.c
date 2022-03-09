#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t thread1, thread2;
pthread_mutex_t mutex1;

int val = 0;

void *thread_handler(void *argv) {
	int *index = (int*)argv;
	while (1) {
		pthread_mutex_lock(&mutex1);
		val++;
		printf("in thread %d, val = %d\n", *index, val);
		sleep(1);
		pthread_mutex_unlock(&mutex1);
		sleep(1);
	}
}

int main(int argc, char *argv[]) {
	int x = 1, y = 2;
	pthread_mutex_init(&mutex1, NULL);
	pthread_create(&thread1, NULL, thread_handler, &x);
	pthread_create(&thread2, NULL, thread_handler, &y);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	return 0;
}
