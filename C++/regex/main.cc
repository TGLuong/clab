#include <iostream>
#include <regex>

using namespace std;


int main() {
    regex date_regex("^[0-9]{1,2}:[0-9]{1,2}:[0-9]{1,2} [0-9]{1,2}/[0-9]{1,2}/[0-9]{4}$");

    if (regex_match("1:000:0 1/2/2022", date_regex)) {
        cout << "1 match" << endl;
    }
    return 0;
}
