#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "student_type.h"
#include <stdio.h>
#include <signal.h>

#define SHM_NAME "OS1"


int shm_fd;
void *object;
struct sinh_vien sv;

void sign_handler(int sign) {
	memcpy(object, &sv, sizeof(sv));
	printf("copy vao share memory\n");
	exit(0);
}

int main() {
	signal(SIGINT, sign_handler);
	
	shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
	if (shm_fd == -1) {
		printf("create share memory error\n");
		exit(0);
	}
	ftruncate(shm_fd, 1000);

	object = mmap(0, 1000, PROT_WRITE, MAP_SHARED, shm_fd, 0);
	
	printf("nhap ma sinh vien: ");
	fgets(sv.masv, sizeof(sv.masv), stdin);
	sv.masv[strlen(sv.masv) - 1] = 0;
	
	printf("nhap ten sinh vien: ");
	fgets(sv.tensv, sizeof(sv.tensv), stdin);
	sv.tensv[strlen(sv.tensv) - 1] = 0;

	printf("nhap lop sinh vien: ");
	fgets(sv.lop, sizeof(sv.lop), stdin);
	sv.lop[strlen(sv.lop) - 1] = 0;

	while (1) sleep(1);
	return 0;
}
