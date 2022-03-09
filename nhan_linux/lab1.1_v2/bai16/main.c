#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int pos(char *str1, char *str2) {
	int i = 0;
	while (i < strlen(str1) - strlen(str2)) {
		if (str1[i] == str2[0]) {
			for (int j = 1; j < strlen(str2); j++) {
				if (str1[i + j] != str2[j]) {
					break;
				}
				if (j == strlen(str2) - 1) {
					return i;
				}
			}
		}
		i++;
	}
	return -1;
}


int main(int argc, char *argv[]) {
	char str1[255], str2[255];
	fgets(str1, 255, stdin);
	str1[strlen(str1) - 1] = '\0';
	fgets(str2, 255, stdin);
	str2[strlen(str2) - 1] = '\0';
	printf("%d\n", pos(str1, str2));
	return 0;
}
