#include <stdio.h>
#include <signal.h>



int main() {
    sigset_t new_set, old_set;

    sigemptyset(&new_set);
    sigaddset(&new_set, SIGINT);
    sigprocmask(SIG_BLOCK, &new_set, &old_set);

    sigprocmask(SIG_SETMASK, NULL, &old_set);

    if (sigismember(&old_set, SIGINT)) {
        printf("sigint bi block\n");
    } else {
        printf("sigint khong bi block\n");
    }
    return 0;
}
