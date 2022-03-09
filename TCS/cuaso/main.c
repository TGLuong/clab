#include <string.h>
#include <stdio.h>

void hander(int testcase, int m, int n) {
	int width = 5 * n + 1, height = 5 * m + 1, result[5];
	char matrix[height][width];

	memset(result, 0, sizeof(result));
	getchar();
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			scanf("%c", &matrix[i][j]);
		}
		getchar();
	}
	for (int i = 1; i < 5 * m + 1; i = i + 5) {
		for (int j = 1; j < 5 * n + 1; j = j + 5) {
			int count = 0;
			for (int k = 0; k < 4; k++) {
				if (matrix[i + k][j] == '*') count++;
			}
			result[count]++;
		}
	}
	printf("#%d ", testcase + 1);
	for (int i = 0; i < 5; i++) {
		printf("%d ", result[i]);
	}
	printf("\n");
}


int main() {
	int n_ex, m, n;
	scanf("%d", &n_ex);
	for (int k = 0;k < n_ex; k++) {
		scanf("%d%d", &m, &n);
		hander(k, m, n);
	}
	return 0;
}
