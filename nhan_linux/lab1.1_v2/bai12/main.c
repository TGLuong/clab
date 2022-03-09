#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int isNumber(char c) {
	if (c >= 48 && c <= 57) {
		return 1;
	} else {
		return 0;
	}
}

int isCharacter(char c) {
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
		return 1;
	} else {
		return 0;
	}
}

int countWord(char *string) {
	int i = 0, count = 0;
	while (i < strlen(string)) {
		if (isNumber(string[i]) || isCharacter(string[i])) {
			count++;
			while (string[i] != ' ') i++;
		} else {
			i++;
		}
	}
	return count;
}

int main(int argc, char *argv[]) {
	char string[255] = {0};
	int len = 0;
	fgets(string, 255, stdin);
	printf("so ky tu chuoi la : %d\n", countWord(string));
	return 0;
}
