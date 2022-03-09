#include <iostream>
using namespace std;
class Base {
    public:
        virtual void print() { cout << "Base class" << endl; }
};
class Derived : public Base {
    public:
        void print() override { cout << "derived class" << endl; }
};
int main() {
    Derived derived;
    Base *base = &derived;
    base->print();
    return 0;
}