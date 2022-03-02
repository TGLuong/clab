#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>



int main() {
	int shmid;
	key_t key = ftok("shmfile", 65);
	char *str, *message = "Gialuong";

	shmid = shmget(key, 1024, 0666 | IPC_CREAT);
	str = (char*) shmat(shmid, (void*)0, 0);
	sprintf(str, "%s", message);
	printf("data write to shm: %s\n", message);
	shmdt(str);
	return 0;
}
