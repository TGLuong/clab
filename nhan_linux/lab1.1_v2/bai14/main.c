#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {
	char string[255] = {0};
	char findChar;
	int len = 0;
	fgets(string, 255, stdin);
	printf("nhap ky tu can tim : ");
	scanf("%c", &findChar);
	for (int i = 0; i < strlen(string); i++) {
		if (string[i] == findChar) {
			printf("vi tri dau tien : %d\n", i);
			exit(EXIT_SUCCESS);
		}
	}
	printf("khong tim thay ky tu\n");
	return 0;
}
