#include <iostream>
#include <thread>


void thread_hand1(int n, int m) {
    for (int i = n; i <= m; i++) {
        std::cout << i << std::endl;
    }
}



int main() {
    std::thread thread1(thread_hand1, 10, 20);
    std::thread thread2(thread_hand1, 80, 90);
    std::thread thread3(thread_hand1, 100, 120);
                    

    thread1.join();
    thread2.join();
    thread3.join();
    return 0;
}
