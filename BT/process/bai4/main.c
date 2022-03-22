#include <stdio.h>
#include <stdlib.h>


int main() {
    int a[3];
    a[0] = 10;

    printf("a[0] = %d\n", a[0]);

    printf("access a[4]\n");

    a[4] = 20;

    printf("a[4] = %d\n", a[4]);

    printf("core dump\n");

    return 0;
}
