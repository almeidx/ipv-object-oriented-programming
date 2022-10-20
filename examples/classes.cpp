#include "classes.hpp"

Vehicle::Vehicle() {
	year = 2022;
	brand = "???";
}

Vehicle::Vehicle(int year_, string brand_) {
	year = year_;
	brand = brand_;
}

Vehicle::~Vehicle() { cout << "Vehicle " << brand << " destroyed" << endl; }

void Vehicle::Show() {
	cout << "Year: " << year << endl;
	cout << "Brand: " << brand << endl;
}

int main() {
	Vehicle v1;
	Vehicle v2(2021, "Audi");
	Vehicle *v3 = new Vehicle(2023, "BMW");

	v1.Show();
	v2.Show();
	v3->Show();

	delete v3;

	return 0;
}
