#include <iostream>


class PublicAccessModifier {
    public:
        int a = 0, b = 0;

        PublicAccessModifier(int a, int b) {
            this->a = a;
            this->b = b;
        }

        int sum() {
            return a + b;
        } 
};

int main() {
    PublicAccessModifier sum(10, 20);
    std::cout << sum.sum() << std::endl;
    sum.a = 20;
    sum.b = 50;
    std::cout << sum.sum() << std::endl;
    return 0;
}