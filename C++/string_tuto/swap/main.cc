#include <iostream>
#include <string>
using namespace std;
int main() {
    string s1 = "String 1";
    string s2 = "String 2";
    cout << "s1: " << s1 << ", s2: " << s2 << endl;
    s1.swap(s2);
    cout << "swap" << endl;
    cout << "s1: " << s1 << ", s2: " << s2 << endl;   
    return 0;
}
