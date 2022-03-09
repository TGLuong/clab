#include <iostream>
using namespace std;

class ClassA {
    public:
        void print() { cout << "in class A" << endl; }
};
class ClassB {
    public:
        void print() { cout << "in class B" << endl;}
};
class ClassC : public ClassA, public ClassB {
    public:
        ClassC() {}
        void print() {
            ClassA::print();
        }
};

int main() {
    ClassC c;
    c.print();
    return 0;
}