#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>

using namespace std;

class Person {
	public:
		string name;
		string city;
		uint8_t age;

		Person(string _name, string _city, uint8_t _age) {
			name = _name;
			city = _city;
			age = _age;
		}

		~Person() {
			cout << "Person " << name << " destroyed" << endl;
		}

		void print() {
			cout << "Name: " << name << endl;
			cout << "City: " << city << endl;
			cout << "Age: " << (int)age << endl;
		}
};

#endif // PESSOA_HPP
