#include <stdio.h>

void call_back() {
    printf("hello\n");
}


// void hand_call(void func()) {
//     void fun_ptr[10];

// }

typedef void (*handler)(void);

int main() {
    // hand_call(call_back);

    void (*handle)(void) = call_back;

    handle(); 

    return 0;
}