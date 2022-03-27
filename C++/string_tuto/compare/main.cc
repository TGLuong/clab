#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "Hello World";
    string s2 = "Hello Worl";
    string s3 = "Hallo World";
    string s4 = "Hellz World";
    cout << s1.compare(s2) << endl;
    cout << s1.compare(s3) << endl;
    cout << s1.compare(s4) << endl;
    return 0;
}
