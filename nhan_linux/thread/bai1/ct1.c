#include <stdio.h>
#include <time.h>


int main() {
	int second1, second2, count = 0;
	second1 = time(NULL);
	for (long i = 1; i < 3000000000; i++) {
		if (i % 2 == 1) count++;
	}
	second2 = time(NULL);
	printf("tong so le la %d\n", count);
	printf("tong thoi gian: %d\n", second2 - second1);
	return 0;
}
