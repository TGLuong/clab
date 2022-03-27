#include <iostream>
#include <string>
using namespace std;
int main() {
    string s1 = "hello world";
    cout << "find(\"hello\", 0): " << (string::npos != s1.find("hello", 0)) << endl;
    cout << "find(\"hello\", 5): " << (string::npos != s1.find("hello", 5)) << endl;
    return 0;
}
