#include <iostream>

struct Example {
	int a, b;
	Example(int v1, int v2): a(v1), b(v2) { }
	int sum() { return a + b; }
};


int main() {
	struct Example a(4, 5);
	std::cout << sizeof(a) << std::endl;
	std::cout << a.sum() << std::endl;
	return 0;
}
