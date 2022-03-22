#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
   vector<int> vect = {1,3,2,5,6,4,8,7};
   partition(vect.begin(), vect.end(), [](int x){ return x % 2 == 0; });
   bool result = is_partitioned(vect.begin(), vect.end(), [](int x){ return x % 2 == 0; });

   cout << result << endl;

   for(int &x: vect) cout << x << " ";
   cout << endl;
}

