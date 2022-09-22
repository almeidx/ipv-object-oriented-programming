#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <iostream>

using namespace std;

class Vehicle {
	public:
	int year;
	string brand;
	Vehicle();
	Vehicle(int year_, string brand_);
	~Vehicle();

	void Show();
};


#endif // CLASSES_HPP
