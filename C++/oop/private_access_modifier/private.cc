#include <iostream>

class Private {
    private:
        int a = 0, b = 0;
    public:
        Private(int a, int b) { this->a = a; this->b = b;}
};
class Child : public Private {
    public:
        Child(int a, int b): Private(a, b) { }
        int sum() { return Private::a + Private:: b; }
};

int main() {
    Child obj(10, 20);
    std::cout << obj.sum() << std::endl;
    return 0;
}