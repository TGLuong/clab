#include <iostream>
using namespace std;

class BaseCamera {
    public:
        string getStream() {
            return "base camera";
        }
};
class Canon : public BaseCamera {
    public:
        string getStream() {
            return "canon camera";
        }
};
class Nikon {
    public:
        string getStream() {

            return "Nikon camera";
        }
};


int main() {
    Canon canon;
    Nikon nikon;
    cout << canon.getStream() << endl;
    cout << nikon.getStream() << endl;
    return 0;
}