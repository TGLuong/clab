#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(void) {
    struct stat sb;
    stat("./filesystem.txt",&sb);
    switch (sb.st_mode & S_IFMT)
    {
    case S_IFREG:
        printf("regular file");
        break;
    case S_IFDIR:
        printf("directory file");
        break;
    case S_IFIFO:
        printf("pipe file");
    case S_IFCHR:
        printf("character deveice");
    case S_IEXEC:
        printf("exe file");
    default:
        break;
    }
    printf("\nthoi gian chinh sua lan cuoi: %s", ctime(&sb.st_ctime));
    printf("kick thuoc: %jd byte\n",sb.st_size);
    return 0;
}
