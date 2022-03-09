#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	int *array, *array_b;
	int b_len = 0;
	if (argc <= 1) {
		printf("vui long nhap tham so");
		exit(EXIT_FAILURE);
	} else {
		array_b = (int*) calloc(argc - 1, sizeof(int));
		array = (int*) calloc(argc - 1, sizeof(int));
		for (int i = 1; i < argc; i++) {
			array[i - 1] = atoi(argv[i]);
		}
	}
	for (int i = 0; i < argc - 1; i++) {
		if (array[i] % 2 == 1) {
			array_b[b_len] = array[i];
			b_len++;
		}
	}
	for(int i = 0; i < b_len; i++) {
		printf("%4.d", array_b[i]);
	}
	printf("\n");
	return 0;
}
