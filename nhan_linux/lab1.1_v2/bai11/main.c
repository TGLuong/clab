#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char *argv[]) {
	char string[255] = {0};
	int len = 0;
	fgets(string, 255, stdin);
	for (int i = 0; i < strlen(string) / 2; i++) {
		char buffer = string[i];
		string[i] = string[strlen(string) - 1 - i];
		string[strlen(string) - 1 - i] = buffer;
	}
	printf("chuoi la : %s\n", string);
	return 0;
}
