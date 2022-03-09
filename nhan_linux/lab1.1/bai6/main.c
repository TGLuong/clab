#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hasValue(int **matrix, int x, int y) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (matrix[i][j] < 2015 && matrix[i][j] % 2 == 0) {
				return 1;
			}
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
	int **matrix = (int**)malloc(3 * sizeof(int));
	matrix[0] = (int*) malloc(3 * sizeof(int));
	matrix[0][0] = 0;
	matrix[0][1] = 1;
	matrix[0][2] = 2;
	matrix[1] = (int*) malloc(3 * sizeof(int));
	matrix[1][0] = 4;
	matrix[1][1] = 5;
	matrix[1][2] = 6;
	matrix[2] = (int*) malloc(3 * sizeof(int));
	matrix[2][0] = 6;
	matrix[2][1] = 7;
	matrix[2][2] = 8;

	if (hasValue(matrix, 3, 6)) {
		printf("co phan tu\n");
	} else {
		printf("khong co phan tu\n");
	}
	return 0;
}
