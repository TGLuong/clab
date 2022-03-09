#include <stdio.h>
#include <string.h>

int strrev(char *str) {
	int result;
	for (int i = 0; i < strlen(str) / 2; i++) {
		char c = str[i];
		str[i] = str[strlen(str) - i - 1];
		str[strlen(str) -i -1] = c;
	}
	sscanf(str, "%d", &result);
	return result;
}


int sum_reverse(int m, int n) {
	char buf1[100], buf2[100];
	int num1, num2;
	memset(buf1, 0, sizeof(buf1));
	memset(buf2, 0, sizeof(buf2));
	sprintf(buf1, "%d", m);
	sprintf(buf2, "%d", n);
	num1 = strrev(buf1);
	num2 = strrev(buf2);
	sprintf(buf1, "%d", num1 + num2);
	return strrev(buf1);
}

int main() {
	int n_example, m, n;

	scanf("%d", &n_example);
	for (int i = 1; i <= n_example; i++) {
		scanf("%d%d", &m, &n);
		printf("%d\n", sum_reverse(m, n));
	}
	return 0;
}
