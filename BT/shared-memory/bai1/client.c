#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>

#define SHARED_NAME "shared"

void *ptr;

void create(int pid, char *name, char *value) {
    char buffer[900];
    sprintf(buffer, "type:create\n%s:%s\n", name, value);
    sprintf(ptr, "%s", buffer);
    kill(pid, SIGUSR1);
}

void edit(int pid, char *name, char *value) {
    char buffer[900];
    sprintf(buffer, "type:edit\n%s:%s\n", name, value);
    sprintf(ptr, "%s", buffer);
    kill(pid, SIGUSR1);
}

void delete(int pid, char *name) {
    char buffer[900];
    sprintf(buffer, "type:delete\n%s:\n", name);
    sprintf(ptr, "%s", buffer);
    kill(pid, SIGUSR1);
}

void show(int pid, char *name) {
    char buffer[900];
    sprintf(buffer, "type:show\n%s:none\npid:%d\n", name, getpid());
    sprintf(ptr, "%s", buffer);
    kill(pid, SIGUSR1);
    while (1) sleep(1);
}

void respone_show(int sign) {
    printf("value: %s\n", (char*)ptr);
    exit(0);
}

int main(int argc, char * argv[]) {
    signal(SIGUSR1, respone_show);
    int shm_fd, pid;

    pid = atoi(argv[2]);
    printf("client pid: %d\n", getpid());
    shm_fd = shm_open(SHARED_NAME, O_RDWR, 0666);
    ptr = mmap(0, 1000, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    if (strcmp(argv[1], "create") == 0) {
        create(pid, argv[3], argv[4]);
    }
    if (strcmp(argv[1], "edit") == 0) {
        edit(pid, argv[3], argv[4]);
    }
    if (strcmp(argv[1], "delete") == 0) {
        delete(pid, argv[3]);
    }
    if (strcmp(argv[1], "show") == 0) {
        show(pid, argv[3]); 
    }

    return 0;
}
