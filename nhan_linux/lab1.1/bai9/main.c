#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>



void sortMatrix(float **matrix, int x, int y) {
	for (int i = 0; i < x - 1; i++) {
		for (int j = 0; j < y; j++) {
			for (int m = i + 1; m < x; m++) {
				for (int n = j; n < y; n++) {
					if (matrix[i][j] > matrix[m][n]) {
						float buffer = matrix[i][j];
						matrix[i][j] = matrix[m][n];
						matrix[m][n] = buffer;
					}
				}
			}
		}
	}
}


int main(int argc, char *argv[]) {
	float **matrix = (float**)malloc(3 * sizeof(int));
	matrix[0] = (float*) malloc(3 * sizeof(int));
	matrix[0][0] = 0;
	matrix[0][1] = 1.1;
	matrix[0][2] = -2.2;
	matrix[1] = (float*) malloc(3 * sizeof(int));
	matrix[1][0] = 4.6;
	matrix[1][1] = -5.2;
	matrix[1][2] = 6.9;
	matrix[2] = (float*) malloc(3 * sizeof(int));
	matrix[2][0] = -6.4;
	matrix[2][1] = 7.3;
	matrix[2][2] = -8.7;

	sortMatrix(matrix, 3, 3);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%3.1f ", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}
