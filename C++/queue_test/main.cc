#include <iostream>
#include <queue>

using namespace std;



int main() {
    queue<int> my_queue;
    my_queue.push(1);
    my_queue.push(2);

    cout << my_queue.front() << endl;
    my_queue.pop();
    cout << my_queue.front() << endl;
    my_queue.pop();
    cout << my_queue.front() << endl;
    my_queue.pop();
    cout << my_queue.front() << endl;
    return 0;
}
