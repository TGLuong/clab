#include <iostream>
using namespace std;
    
class Animal {
    public:
        string kind;
        Animal(string kind) : kind(kind) { }
};


class Dog : public Animal {
    public:
        Dog(string kind) : Animal(kind) { }
        void printKind() { cout << "Kind: " + kind << endl; }
};

int main() {
    Dog dog("dog");
    dog.printKind();
    dog.kind = "Cat";
    dog.printKind();
    return 0;
}