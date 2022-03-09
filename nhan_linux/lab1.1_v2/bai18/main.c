#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char *argv[]) {
	char string[255] = {0};
	char c;
	int i;
	fgets(string, 255, stdin);
	printf("nhap ky tu can thanh doi: ");
	scanf("%c", &c);
	printf("nhap vi tri can thay doi: ");
	scanf("%d", &i);
	if (i < strlen(string) - 1) {
		string[i] = c;
		printf("%s", string);
		return 0;
	}
	return 0;
}
