#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>




int main() {
    int fd;
    
    fd = open("data.txt", O_APPEND);

    return 0;
}
