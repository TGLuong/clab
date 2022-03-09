#include <iostream>

class ExampleClass1 {
    public:
        int a;
        int getA() { return a; }
};
class ExamleClass2 : ExampleClass1 {
    public:
        int b;
        int getB() { return b; }
};


class Class1 {
    public:
        int a;
        Class1(int a) : a(a) { }
};

class Class2 : Class1 {
    public:
        int c, d;
        Class2(int c, int d): c(c), d(d) { }
};

int main() {
    Class2 class2(1, 2);
}