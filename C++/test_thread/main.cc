#include <thread>
#include <iostream>
using namespace std;


void foo() {
    cout << "in foo" << endl;
}

void bar(int x) {
    cout << "in bar: " << x << endl;
}

int main() {
    thread first(foo);
    thread second(bar, 0);
    first.join();
    second.join();
    return 0;
}
