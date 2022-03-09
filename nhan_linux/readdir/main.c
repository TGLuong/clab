#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <dirent.h>


int main(int argc, char *argv[]) {
	DIR *dir;
	struct dirent *dp;
	if (argc < 2) {
		printf("chua nhap duong dan\n");
		exit(0);
	}
	dir = opendir(argv[1]);

	while ((dp = readdir(dir)) != NULL) {
		printf("%s\n", dp->d_name);
	}

	return 0;
}
