#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>


void check_param(int argc, char *argv[]) {
	if (argc <= 1) {
		printf("chua nhap tham so lenh\n");
		exit(0);
	}
	if (strcmp(argv[1], "ls") == 0) {
	
	}
	if (strcmp(argv[1], "create") == 0 || strcmp(argv[1], "remove") == 0 ||
		strcmp(argv[1], "cat") == 0) {
		if (argc < 3) {
			printf("chua nhap ten file\n");
			exit(0);
		}
	}
	
}

void list_file(int argc, char *argv[]) {
	char dir_path[100];
	strcpy(dir_path, ".");
	DIR *d;
	struct dirent *dir;

	if (argc == 3) {
		strcpy(dir_path, argv[2]);
	}
	d = opendir(dir_path);
	if (d) {
		while ( (dir = readdir(d)) != NULL) {
			printf("%s\n", dir->d_name);
		}
		closedir(d);
	} else {
		printf("folder khong ton tai\n");
		exit(0);
	}
}

void create_file(int argc, char *argv[]) {
	int fd;

	fd = open(argv[2], O_CREAT, 0666);
	if (fd == -1) {
		printf("tao file that bai\n");
		exit(0);
	} else {
		printf("tao file %s thanh cong\n", argv[2]);
		exit(0);
	}
}

void remove_file(int argc, char *argv[]) {
	int status;

	status = unlink(argv[2]);

	if (status == -1) {
		printf("error delete file ! file not found\n");
		exit(0);
	} else {
		printf ("success delete file %s \n", argv[2]);
		exit(0);
	}
}

void cat_file(int argc, char *argv[]) {
	int fd;
	char buffer[1000];
	
	fd = open(argv[2], O_RDONLY);
	if (fd == -1) {
		printf("error file not found\n");
		exit(0);
	}

	while (read(fd, buffer, sizeof(buffer)) != 0) {
		printf("%s", buffer);
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	check_param(argc, argv);

	if (strcmp(argv[1], "ls") == 0) {
		list_file(argc, argv);
	}
	if (strcmp(argv[1], "create") == 0) {
		create_file(argc, argv);
	}
	if (strcmp(argv[1], "remove") == 0) {
		remove_file(argc, argv);
	}
	if (strcmp(argv[1], "cat") == 0) {
		cat_file(argc, argv);
	}
	return 0;
}
