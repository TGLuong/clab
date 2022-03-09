#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {
	char string[255] = {0};
	int len = 0;
	fgets(string, 255, stdin);
	while (string[len] != '\0') {
		len++;
	}
	printf("do dai chuoi la : %d\n", len);
	return 0;
}
