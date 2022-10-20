#include <iostream>

using namespace std;

class Vehicle {
	string brand;
	int year;

public:
	Vehicle() {
		brand = "Unknown";
		year = 0;

		cout << "Vehicle created" << endl;
	}

	Vehicle(string _brand, int _year) {
		brand = _brand;
		year = _year;

		cout << "Vehicle " << brand << " created" << endl;
	}

	~Vehicle() { cout << "Vehicle " << brand << " destroyed" << endl; }

	void print() {
		cout << "Brand: " << brand << endl;
		cout << "Year: " << year << endl;
	}
};

class SmallVehicle : public Vehicle {
public:
	SmallVehicle(string _brand, int _year) : Vehicle(_brand, _year) {
		cout << "SmallVehicle " << _brand << " created" << endl;
	}

	~SmallVehicle() { cout << "SmallVehicle destroyed" << endl; }
};

int main(void) {
	SmallVehicle sv("Fiat", 2010);

	sv.print();

	return 0;
}
