#include <iostream>

#include "bank.hpp"

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Bank BES("BES-NOVO BANCO");

    Person *P1 = new Person("Ze", "2343");

    BES.add_account(P1);

    Account *C = new Account(P1);

    BES.add_account(C);
    BES.print();

    BES.deposit("2343", 10);

    P1 = new Person("Goncalo", "12");

    BES.add_account(P1);

    C = new Account(P1);

    BES.add_account(C);
    BES.deposit("12", 100);

    cout << "Capital Total do Bank = " << BES.bank_total() << endl;

    Account *CSalgado = BES.get_largest_account();

    if (CSalgado) {
        CSalgado->print();
        //delete CSalgado; //??????
    }

    BES.save_to_file("ola.txt");

    return 0;
}
