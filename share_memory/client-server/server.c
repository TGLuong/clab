#include <stdio.h>
#include <sys/mmap.h>
#include <signal.h>
#include <fcntl.h>

#define shm_name "client-server"
#define shm_size 1000

int shmid;
void *pshm;

void *sigint_handler(int sign) {
	printf("in sigin\n");
}

int main(int argc, char *argv[]) {
	
	shmid = shm_open(shm_name, O_CREAT | O_RDWR, 0666);
	ftruncate(shmid, shm_size);
	pshm = mmap(0, PROT_READ, MAP_SHARED, shmid, 0);

	signal(SIGINT, sigint_handler);
	
	while (1) sleep(1);
	return 0;
}
