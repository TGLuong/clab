#include <iostream>

class Parent {
    private:
        int a;
    protected:
        int b;
    public:
        int c;
        Parent(int a, int b, int c) : a(a), b(b), c(c) { }
};

class child : private Parent {
    public:
        child(int a, int b, int c) : Parent(a, b, c) { }
};

int main() {

    return 0;
}