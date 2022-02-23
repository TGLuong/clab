#include "strmap.h"
#include <stdio.h>

int main() {
	StrMap *sm;
	char buffer[250];
	int result;
	sm_put(sm, "Name", "Luong");
	result = sm_get(sm, "Name", buffer, sizeof(buffer));
	printf("result: %d\ndata: %s\n", result, buffer);
	return 0;
}
