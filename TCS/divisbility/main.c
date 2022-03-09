#include <stdio.h>



void printf_result(int n, int x, int y) {
	for (int i = 2; i < n; i++) {
		if (i % x == 0 && i % y != 0) {
			printf("%d ", i);
		}
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	int n_exa, n, x, y;

	scanf("%d", &n_exa);

	for (int i = 0; i < n_exa; i++) {
		scanf("%d%d%d", &n, &x, &y);
		printf_result(n, x, y);
	}
	return 0;
}
