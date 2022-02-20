#include <stdio.h>


int main() {
	char s[200];

	while (1) {
		scanf("%[^\n]", s);
		printf("%s\n", s);
	}
	return 0;
}
