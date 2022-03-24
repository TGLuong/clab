#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <string>

using std::string;


int main() {
    int fd = open("data.txt", O_CREAT | O_RDWR, 0666);
    string s = "jfkjsdfksfjkjdjfsjkakjfdjfjaslfdjsfdkfjskjfdljfskjfjskj9fs";
    std::cout << "sizeof: " << s << " is: " << s.size() << std::endl;
    write(fd, s.data(), sizeof(s.data()));
    close(fd);
    return 0;
}
