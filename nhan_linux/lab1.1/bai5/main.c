#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	float array[3][6] = {
		{5.2, 2.2, 3.6, 4.1, 5.6, 6.8},
		{3.7, 4.7, 5.4, 6.2, 7.1, 8.6},
		{6.2, 7.5, 8.6, 9.7, 10.1, 11.1}
	};
	float min = array[0][0], max = array[0][0];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++) {
			if (array[i][j] > max) {
				max = array[i][j];
			}
			if (array[i][j] < min) {
				min = array[i][j];
			}
		}
	}
	printf("min = %f\n", min);
	printf("max = %f\n", max);
	return 0;
}
