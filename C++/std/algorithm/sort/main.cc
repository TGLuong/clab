#include <algorithm>
#include <iostream>


bool compare(int a, int b) {
    return a < b ? false : true;
}

int main() {
    int arr[] = {1,3,5,2,7,6};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::sort(arr, arr + n, compare);

    for(int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
