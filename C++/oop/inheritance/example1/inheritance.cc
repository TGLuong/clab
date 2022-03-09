#include <iostream>
#include <string>

using namespace std;


class Verhical {
    protected:
        string type;
        float weight;
    public:
        Verhical(string type, float weight): type(type), weight(weight) { }
        string toJson() { return "{\n    \"type\": \"" + type + "\",\n    \"weight\": " + to_string(weight) + ",\n}"; }
};

class Car : public Verhical {
    protected:
        int wheel, seats;
        string brand;
    public:
        Car(int whell, int seats, string brand, float weight) : 
            Verhical("Car", weight), wheel(whell), seats(seats), brand(brand) { }
        string toJson() {
            return "{\n    \"whell\": " + to_string(wheel) + ",\n    \"wheats\": " + to_string(seats) + 
                    ",\n    \"branch\": \"" + brand + "\",\n    \"type\": \"" + 
                    Verhical::type + "\",\n    \"weight\": " + to_string(Verhical::weight) + "\n}";
        }
};


int main() {
    Verhical verhical("verhical", 100);
    Car car(4, 7, "santa fe", 500);
    cout << verhical.toJson() << endl;
    cout << car.toJson() << endl;
    return 0;
}