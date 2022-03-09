#include <stdio.h>
#include <sys/stat.h>

int main(void) {
    printf("%d\n",S_IFMT);
    printf("%x\n",S_IEXEC);
    printf("%x\n",S_IFBLK);
    printf("%x\n",S_IFCHR);
    printf("%x\n",S_IFDIR);
    printf("%x\n",S_IFIFO);

    return 0;
}