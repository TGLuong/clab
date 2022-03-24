#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>


#define SHARED_NAME "shared"

void *ptr;
char name_db[1000][1000];
char value_db[1000][1000];
int current = 0;


void show_db() {
    system("clear");
    printf("+");
    for (int i = 0 ; i < 25; i++) printf("-");
    printf("+\n");
    printf("|%-3s|%-10s|%-10s|\n", "id", "name", "value");
    for (int i = 0; i < current; i++) {
        printf("|%-3d|%-10s|%-10s|\n", i + 1, name_db[i], value_db[i]);
    }
    printf("+");
    for (int i = 0 ; i < 25; i++) printf("-");
    printf("+\n");
}

void insert(char *name, char *value) {
    strncpy(name_db[current], name, strlen(name));
    strncpy(value_db[current], value, strlen(value));
    current++;
}

void edit(char *name, char *value) {
    for (int i = 0; i < current; i++) {
        if (strcmp(name_db[i], name) == 0) {
            memset(value_db[i], 0, sizeof(value_db[i]));
            strncpy(value_db[i], value, strlen(value));
        }
    }
}

void delete(char *name) {
    int i = 0;
    while (i < current) {
        if (strcmp(name_db[i], name) == 0) {
            while (i < current - 1) {
                memset(name_db[i], 0, sizeof(name_db[i]));
                memset(value_db[i], 0, sizeof(value_db[i]));

                strncpy(name_db[i], name_db[i + 1], strlen(name_db[i + 1]));
                strncpy(value_db[i], value_db[i + 1], strlen(value_db[i + 1]));
                i++;
            }
            current--;
        }
        i++;
    }
}

void show(int pid, char *name) {
    memset(ptr, 0, 10);
    for (int i = 0; i < current; i++) {
        if (strcmp(name_db[i], name) == 0) {
            sprintf(ptr, "%s", value_db[i]);
        }
    }
    kill(pid, SIGUSR1);
}

void sigusr1_handler(int sign) {
    char command[100], name[400], value[400];
    int pid;
    sscanf((char *)ptr, "type:%s\n%[^:]:%[^\n]\npid:%d\n", command, name, value, &pid);
    if (strcmp(command, "create") == 0) {
        insert(name, value);
        show_db();
    }
    if (strcmp(command, "edit") == 0) {
        edit(name, value);
        show_db();
    }
    if (strcmp(command, "delete") == 0) {
        delete(name);
        show_db();
    }
    if (strcmp(command, "show") == 0) {
        show(pid, name);
    }
}

void int_handler(int sign) {
    printf("exit\n");
    shm_unlink(SHARED_NAME);
    exit(0);
}

int main () {
    signal(SIGUSR1, sigusr1_handler);
    signal(SIGINT, int_handler);
    printf("pid: %d\n", getpid());
    int shm_fd;
    
    
    shm_fd = shm_open(SHARED_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, 1000);

    ptr = mmap(0, 1000, PROT_WRITE | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    while (1) sleep(1);
    return 0;
}
