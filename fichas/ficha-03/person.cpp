#include "person.hpp"

Person::Person(string _name, string _cc) {
	cout << "Passei em <" << __FUNCTION__ << ">" << endl;

	name = _name;
	cc = _cc;
}

Person::~Person() { cout << "Passei em <" << __FUNCTION__ << ">" << endl; }

string Person::get_cc() { return cc; }

void Person::print() { cout << "PESSOA: [" << name << "] : [" << cc << "]" << endl; }

void Person::save_to_file(ofstream &F) { F << "PESSOA: [" << name << "] : [" << cc << "]" << endl; }
