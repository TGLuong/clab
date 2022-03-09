#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

pthread_t thread1, thread2;

static void * thread_handler(void * parg) {
	long *arg = (long*) parg;
	long count = 0;
	for (long i = arg[0]; i <= arg[1]; i++) {
		if (i % 2 == 1) {
			count++;
		}
	}
	long * result = malloc(sizeof(long));
	*result = count;
	return (void*)result;
}

int main() {
	long *count1, *count2;
	int time1, time2;
	long arg1[2], arg2[2];
	time1 = time(NULL);
	arg1[0] = 1;
	arg1[1] = 1500000000;
	arg2[0] = 1500000001;
	arg2[1] = 3000000000;

	pthread_create(&thread1, NULL, thread_handler, &arg1);
	pthread_create(&thread2, NULL, thread_handler, &arg2);
	
	pthread_join(thread1,(void**)&count1);
	pthread_join(thread2, (void**)&count2);

	time2 = time(NULL);

	printf("thoi gian chay: %d\n", time2 - time1);
	printf("tong so chia le : %ld\n", *count1 + *count2);
	return 0;
}
