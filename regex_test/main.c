#include <regex.h>
#include <stdio.h>



int main() {
    regex_t regex;
    int status;

    // create regex
    status = regcomp(&regex, "[^0-9]", 0);
    if (status == 0) {
        printf("create regex success\n");
    }
    
    // so sanh chuoi bang regex
    status = regexec(&regex, "10230", 0, NULL, 0);
    if (status != 0) {
        printf("10230 la so\n");
    } else {
        printf("10230 co chu trong chuoi\n");
    }

    status = regexec(&regex, "102a0", 0, NULL, 0);
    if (status != 0) {
        printf("102a0 la so\n");
    } else {
        printf("102a0 co chu trong chuoi\n");
    }   
}
