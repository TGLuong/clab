#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>



float sumNegative(float **matrix, int x, int y) {
	float sum = 0;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (matrix[i][j] < 0) {
				sum += matrix[i][j];
			}
		}
	}
	return sum;
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

	printf("count = %f\n", sumNegative(matrix, 3, 3));

	return 0;
}
