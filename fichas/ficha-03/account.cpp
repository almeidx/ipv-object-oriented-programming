#include "account.hpp"

Account::Account(Person *owner) {
	owner = owner;
	cash = 0;
}

Account::~Account() {
	cout << "Passei em <" << __FUNCTION__ << ">" << endl;
	// delete Titular;
}

void Account::deposit(float amount) {
	if (amount >= 0) {
		cash += amount;
	} else {
		cout << "ATENÇÃO: So depositar valores > 0" << endl;
	}
}

void Account::print() {
	cout << "Titular: ";
	owner->print();
	cout << "SALDO: " << cash << endl;
}
