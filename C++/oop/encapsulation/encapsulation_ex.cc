#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Car {
	private:
		string color, name;
	public:
		Car(string color, string name) {
			this->color = color;
			this->name = name;
		}

		void setColor(string color) { this->color = color; }
		
		string getColor() { return this->color; }

		void setName(string name) { this->name = name; }

		string getName() { return this->name; }

		string toString() { return "car name: " + this->name + "\ncar color: " + this->color; }
};

int main() {
	Car lexus("white", "lexus");
	cout << lexus.toString() << endl;
	return 0;
}
