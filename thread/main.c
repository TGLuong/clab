#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_t thread_1, thread_2;

typedef struct {
	char name[30];
	char msg[30];
} s_data;

static void *thr_handler(void *param) {
	pthread_t tid = pthread_self();
	s_data *data = (s_data*)param;
	if(pthread_equal(tid, thread_1)) {
		printf("thread 1\n");
	} else {
		printf("thread 2\n");
		printf("data : name = %s, message = %s\n", data->name, data-> msg);
	}
}

int main(void) {
	int res;
	s_data data;
	strcpy(data.name, "gia luong");
	strcpy(data.msg, "message");
	if(res = pthread_create(&thread_1, NULL, &thr_handler, NULL)) {
		printf("thread 1: error num = %d", res);
		return -1;
	}
	if(res = pthread_create(&thread_2, NULL, &thr_handler, &data)) {
		printf("thread 2: error num = %d", res);
		return -1;
	}
	while(1);
	return 0;
}
