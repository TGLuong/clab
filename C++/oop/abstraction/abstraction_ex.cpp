#include <iostream>
using namespace std;

class AbtractionImp {
    private:
        int a, b;
    public:
        void set(int a, int b) {
            this-> a = a;
            this-> b = b;
        }
        void display() {
            cout << "a = " << a << endl;
            cout << "b = " << b << endl;
        }
};

int main() {
    AbtractionImp ab;
    ab.set(10, 20);
    ab.display();
    return 0;
}