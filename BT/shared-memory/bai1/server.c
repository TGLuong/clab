#include <stdio.h>


#define share_name "shared"

int main () {
    int shm_fd;
    void *ptr;
    
    shm_fd = shm_open(share_name, O_CREATE | O_RDWR, 0666);
    ftruncate(shm_fd, 1000);

    ptr = mmap(0, 1000, PROT_WRITE | PROT_WRITE)

    return 0;
}
