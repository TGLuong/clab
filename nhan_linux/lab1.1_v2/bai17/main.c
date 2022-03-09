#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
	char string[255] = {0};
	fgets(string, 255, stdin);
	string[strlen(string) - 1] = '\0';
	for (int i = 0; i <= strlen(string) / 2; i++) {
		if (string[i] != string[strlen(string) - 1 -i]) {
			printf("chuoi khong can bang\n");
			return 0;
		}
	}
	printf("chuoi can bang");
	return 0;
}
