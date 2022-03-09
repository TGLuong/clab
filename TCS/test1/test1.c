#include <stdio.h>


int main(int argc, char *argv[]) {
	int n;
	while (1) {
		scanf("%d", &n);
		if (n == 42) break;
		printf("%d\n", n);
	}
	return 0;
}
