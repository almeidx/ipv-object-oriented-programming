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

			cout << "Person " << _name << " created" << endl;
		}

		~Person() {
			cout << "Person " << name << " destroyed" << endl;
		}

		void print() {
			cout << "Name: " << name << endl << "City: " << city << endl << "Age: " << (int)age << endl;
		}

		bool operator==(const Person &p) {
			return name == p.name && city == p.city && age == p.age;
		}

};

#endif // PESSOA_HPP
