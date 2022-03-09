#include <stdio.h>
#include <string.h>

long sonen(int n) {
	char buffer[100];
	long sum = 0;

	sprintf(buffer, "%d", n);
	for (int i = 0; i < strlen(buffer); i++) {
		sum += buffer[i] - 48;
	}
	if (sum >= 10) return sonen(sum);
	return sum;
}

int main() {
	int n_ex;
	long n;

	scanf("%d", &n_ex);
	for (int i = 0; i < n_ex; i++) {
		scanf("%ld", &n);
		printf("#%d %ld\n", i+1, sonen(n));
	}
	return 0;
}
