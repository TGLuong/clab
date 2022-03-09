#include <iostream>

class Protected {
    protected:
        int a = 0, b = 0;
    public:
        Protected(int a, int b) { this->a = a; this->b = b; }
};

class Child: public Protected {
    public:
        Child(int a, int b) : Protected(a, b) { }       
        int sum() { return Protected::a + Protected::b; }
};


int main() {
    Child obj(10, 20);
    std::cout << obj.sum() << std::endl;
    return 0;
}