#include <iostream>
using namespace std;

class A {
    public:
        int a;
        A() { cout << "A is created" << endl; }
};

class B : virtual public A {
    public:
        B() { cout << "B is created" << endl; }
};

class C : virtual public A {
    public:
        C() { cout << "C is created" << endl; }
};

class D : public B, public C {
    public:
        D() { cout << "D is created" << endl; }
};

int main() {
    D d;
    return 0;
}