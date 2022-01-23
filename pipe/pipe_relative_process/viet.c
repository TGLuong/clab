#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void func()
{
    wait(NULL);
}

int main()
{
    int pipefd[2];
    int index_read;
    char buff[30] = {0};
    if (pipe(pipefd) < 0) {
        printf("pipe() unsuccessfully\n");
        exit(1);
    }
    pid_t child_pid = fork();

    if (child_pid >= 0) {

        if (child_pid == 0) {
            printf("I'm wibu con \n");
            if (close (pipefd[1]) == -1)
                printf("close pipefd[1] failed");

            while (1)
            {
                //memset(buff, 0, 30);
                index_read = read(pipefd[0], buff, 30);
                if (index_read > 0) {
                    printf("Data receive from process cha : %s\n", buff);
                }
                if(index_read == 0) {
                    printf("Done receive \n");
                    return 0;
                }
            }
        } else {
            printf("I'm wibu cha\n");
            if (close (pipefd[0]) == -1)
                printf("close pipefd[1] failed");
            signal(SIGCHLD, func);

            write(pipefd[1], "hello ae wibu1", sizeof("hello ae wibu1"));
            write(pipefd[1], "hello ae wibu2", sizeof("hello ae wibu2"));
            write(pipefd[1], "hello ae wibu3", sizeof("hello ae wibu3"));

            close(pipefd[1]);
            while(1);
        }
    }

    else {
        printf("fork() failed");
    }
}
