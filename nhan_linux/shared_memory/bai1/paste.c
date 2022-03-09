#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include "student_type.h"
#include <signal.h>

#define SHM_NAME "OS1"

int shm_fd;
void *object;

void sign_hand(int s) {
	object = mmap(0, 1000, PROT_READ, MAP_SHARED, shm_fd, 0);
	
	printf("ma sinh vien: %s\n", ((struct sinh_vien *)object)->masv);
	printf("ten sinh vien: %s\n", ((struct sinh_vien *)object)->tensv);
	printf("lop sinh vien: %s\n", ((struct sinh_vien *)object)->lop);
}


void int_hand(int i) {
	shm_unlink(SHM_NAME);
	exit(0);
}

int main() {
	signal(SIGTSTP, sign_hand);
	signal(SIGINT, int_hand);
	shm_fd = shm_open(SHM_NAME, O_RDONLY, 0666);
	if (shm_fd == -1) {
		printf("open share memory error\n");
		exit(0);
	}

	while (1) sleep(1);
	
	

}
