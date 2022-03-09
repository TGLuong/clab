#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
	char removeSpace[255] = {0};
	char string[255] = {0};
	int len = 0;
	fgets(string, 255, stdin);
	for (int i = 0; i < strlen(string); i++) {
		if (string[i] != ' ') {
			removeSpace[len] = string[i];
			len++;
		}
	}
	printf("chuoi la : %s\n", removeSpace);
	return 0;
}
