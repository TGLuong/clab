#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>


void check_param(int argc, char *argv[]) {
	if (argc < 2) {
		printf("\033[0;31m");
		printf("chua nhap lenh\n");
		printf("\033[0m");
		exit(0);
	}
	if (strcmp(argv[1], "ps") == 0) {
		
	}
	if (strcmp(argv[1], "kill") == 0) {
		if (argc < 4) {
			printf("\033[0;31m");
			printf("chua nhap ma lenh\n");
			printf("\033[0m");
		}
	}
}

void list_process(int argc, char *argv[]) {
	DIR *d;
	struct dirent *dir;
	char buffer[100], status_path[1000], process_name[100];
	int status_fd;


	d = opendir("/proc");
	printf(" %-10s%-10s\n", "ID", "Name");
	while ((dir = readdir(d)) != NULL) {
		if(isdigit(dir->d_name[0])) {
			sprintf(status_path, "/proc/%s/status", dir->d_name);
			status_fd = open(status_path, O_RDONLY);
			read(status_fd, buffer, sizeof(buffer));
			sscanf(buffer, "Name:   %s", process_name);
			printf(" %-10s%-10s\n", dir->d_name, process_name);
		}
	}
}

void kill_process(int argc, char *argv[]) {
	int process_id, kill_arg, status;

	process_id = atoi(argv[2]);
	kill_arg = atoi(argv[3]);
	status = kill(process_id, kill_arg);
	if (status == 0) {
		printf("\033[0;32m");
		printf("kill %d success\n", process_id);
		printf("\033[0m");
		exit(0);
	} else {
		printf("\033[0;31m");
		printf("kill fail\n");
		printf("\033[0m");
		exit(0);
	}
}


int main(int argc, char *argv[]) {
	check_param(argc, argv);

	if (strcmp(argv[1], "ps") == 0) {
		list_process(argc, argv);
	}
	if (strcmp(argv[1], "kill") == 0) {
		kill_process(argc, argv);
	}
	return 0;
}
