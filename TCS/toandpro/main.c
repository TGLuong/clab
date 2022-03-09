#include <string.h>
#include <stdio.h>

void flush_stdin() {
	while (getchar() != '\n');
}

void handler(int n, char *buffer) {
	int width = n;
	int height = (strlen(buffer) / n);
	char matrix[height][width];
	int index = 0, check = 0;
	for (int i = 0; i < height; i++) {
		if (check == 0) {
			for (int j = 0; j < width; j++) {
				matrix[i][j] = buffer[index];
				index++;
				check = 1;
			}
		} else {
			for (int j = width - 1; j >= 0; j--) {
				matrix[i][j] = buffer[index];
				index++;
				check = 0;
			}
		}
	}
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			printf("%c", matrix[j][i]);
		}
	}
	printf("\n");
}

int main() {
	int n;
	char buffer[1000];
	while (1) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		flush_stdin();
		fgets(buffer, sizeof(buffer), stdin);
		buffer[strlen(buffer) - 1] = 0;
		handler(n, buffer);
	}
	return 0;
}
