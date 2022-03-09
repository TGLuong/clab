#include <stdio.h>
#include <math.h>

int is_prime(int i) {
	if (i <= 1) return 0;
	if (i == 2) return 1;
	for (int j = 2; j <= sqrt(i); j++) {
		if (i % j == 0) return 0;
	}
	return 1;
}

void generate_prime(int m, int n) {
	for (int i = m; i <=n ; i++) {
		if (is_prime(i)) {
			printf("%d\n", i);
		}
	}
	printf("\n");
}

int main() {
	int n_example, m, n;

	scanf("%d", &n_example);
	for (int i = 1; i <= n_example; i++) {
		scanf("%d%d", &m, &n);
		generate_prime(m, n);
	}
	return 0;
}
