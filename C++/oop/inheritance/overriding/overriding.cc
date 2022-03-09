#include <iostream>
using namespace std;

class Parent {
    public:
        int a = 0;
        void print() {
            cout << a << endl;
        }
};

class Child : public Parent {
    public:
        int a = 5;
        void print() {
            cout << a << endl;
        }
};

int main() {
    Parent parent;
    Child child;
    parent.print();
    child.print();
}