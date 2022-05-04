#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>


pthread_t thread1, thread2, thread3, thread4, thread5, thread6, thread7, thread8, thread9, thread10;

void *pthread_handler(void *arg) {
	int *argument;
	int fd;
	char file_name[10], buffer[10];
	argument = (int*)arg;
	sprintf(file_name, "file%d.txt", *argument);
	printf("file name: %s\n", file_name);
	fd = open(file_name, O_CREAT | O_RDWR, S_IRWXU);
	for (int j = 1; j <= 5000000; j++) {
		sprintf(buffer, "%d\n", j);
		write(fd, buffer, strlen(buffer));
	}
	close(fd);
}

void create_thread(int index, pthread_t pthread) {
	pthread_create(&pthread, NULL, pthread_handler, &index);
}
int main() {
	int time1, time2, athread1 = 1, athread2 = 2, athread3 = 3, athread4 = 4, athread5 = 5, athread6 = 6, athread7 = 7, athread8 = 8;
	int athread9 = 9, athread10 = 10;
	time1 = time(NULL);
	pthread_create(&thread1, NULL, pthread_handler, &athread1);
	pthread_create(&thread2, NULL, pthread_handler, &athread2);
	pthread_create(&thread3, NULL, pthread_handler, &athread3);
	pthread_create(&thread4, NULL, pthread_handler, &athread4);
	pthread_create(&thread5, NULL, pthread_handler, &athread5);
	pthread_create(&thread6, NULL, pthread_handler, &athread6);
	pthread_create(&thread7, NULL, pthread_handler, &athread7);
	pthread_create(&thread8, NULL, pthread_handler, &athread8);
	pthread_create(&thread9, NULL, pthread_handler, &athread9);
	pthread_create(&thread10, NULL, pthread_handler, &athread10);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	pthread_join(thread4, NULL);
	pthread_join(thread5, NULL);
	pthread_join(thread6, NULL);
	pthread_join(thread7, NULL);
	pthread_join(thread8, NULL);
	pthread_join(thread9, NULL);
	pthread_join(thread10, NULL);




	time2 = time(NULL);

	printf("tong thoi gian thuc hien: %d\n", time2 - time1);

	return 0;
}
