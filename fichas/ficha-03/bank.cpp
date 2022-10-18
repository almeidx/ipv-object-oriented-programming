#include "bank.hpp"

Bank::Bank(string _name) {
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;

    name = _name;
}

Bank::~Bank() {
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;

    wipe_bank();
}

void Bank::print() {
    //cout << "Passei em <" << __FUNCTION__ << ">" << endl;

    show_clients();
    show_accounts();
}

void Bank::show_clients() {
    //cout << "Passei em <" << __FUNCTION__ << ">" << endl;

    cout << "Bank: [" << name << "]" << endl;

    list<Person *>::iterator it;

    for (it = people.begin(); it != people.end(); ++it) {
        (*it)->print();
    }
}

void Bank::show_accounts() {
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
}

void Bank::add_account(Person *person) {
    //cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    if (person) {
        people.push_back(person);
    }
}

void Bank::add_account(Account *account) {
    //cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    if (account) {
        accounts.push_back(account);
    }
}

bool Bank::remove_account(Account *account) {
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;

    return false;
}

Account *Bank::get_largest_account() {
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;

    Account *largest_account = NULL;
    list<Account *>::iterator it;

    for (it = accounts.begin(); it != accounts.end(); ++it) {
        if (!largest_account) {
            largest_account = *it;
        } else {
            Account *X = *it;

            if (X->get_cash() > largest_account->get_cash()) {
                largest_account = X;
            }
        }
    }

    return largest_account;
}

list<Account *> *Bank::accounts_with_the_least_amount(float amount) {
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;

    list<Account *> *acc_list = new list<Account *>();
    list<Account *>::iterator it;

    for (it = accounts.begin(); it != accounts.end(); ++it) {
        Account *A = (*it);

        if (A->get_cash() < amount) {
            acc_list->push_back(A);
        }
    }

    return acc_list;
}

void Bank::export_xml(string filename) {
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
}

void Bank::wipe_bank() {
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;

    list<Person *>::iterator it;

    for (it = people.begin(); it != people.end(); ++it) {
        delete (*it);
    }

    people.clear();

    list<Account *>::iterator it2;

    for (it2 = accounts.begin(); it2 != accounts.end(); ++it2) {
        delete (*it2);
    }

    accounts.clear();
}

Person *Bank::search_person(string cc) {
    list<Person *>::iterator it;

    for (it = people.begin(); it != people.end(); ++it) {
        if ((*it)->get_cc().compare(cc) == 0)
            return *it;
    }

    return NULL;
}

bool Bank::deposit(string bi, float dep) {
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;

    list<Account *>::iterator it;

    for (it = accounts.begin(); it != accounts.end(); ++it) {
        Person *X = (*it)->get_owner();

        if (X->get_cc().compare(bi) == 0) {
            (*it)->deposit(dep);
            return true;
        }
    }

    return false;
}

float Bank::bank_total() {
    float sum = 0;
    list<Account *>::iterator it;

    for (it = accounts.begin(); it != accounts.end(); ++it) {
        sum += (*it)->get_cash();
    }

    return sum;
}

void Bank::save_to_file(string filename) {
    ofstream F(filename);

    if (F.is_open()) {
        F << name << endl;

        for (list<Person *>::iterator it = people.begin(); it != people.end(); ++it) {
            (*it)->save_to_file(F);
        }

        F.close();
    }
}
