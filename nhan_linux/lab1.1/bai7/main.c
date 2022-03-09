#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int isPrime(int a) {
        if (a <= 1) {
                return 0;
        }
        if (a == 2) {
                return 1;
        }
        for (int i = 2; i <= sqrt(a); i++) {
                if (a % i == 0) {
                        return 0;
                }
        }
        return 1;
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

	int count = 0;
	for (int i = 0; i < 3 ; i++) {
		for (int j = 0; j < 3; j++) {
			if (isPrime(matrix[i][j])) {
				count++;
			}
		}
	}
	printf("count = %d\n", count);

	return 0;
}
