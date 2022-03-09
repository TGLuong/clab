#include <stdio.h>

void handler(int x, int y) {
	int value = 0, step = 1, check = 0;
	if (x == y || x - y == 2) {
		for (int i = 0; i < x; i++) {
			value += step;
			if (check == 0) {
				check = 1;
				step = 3;
			} else {
				check = 0;
				step = 1;
			}
		}
		if (x == y) {
			printf("%d", value);
		} else {
			printf("%d", value - 2);
		}
	} else {
		printf("No Number\n");
	}
}

int main() {
	int n, x, y;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		handler(x, y);
	}
	return 0;
}
