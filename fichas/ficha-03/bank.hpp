#ifndef BANCO_H
#define BANCO_H

#include <iostream>
#include <string>
#include <list>
#include <fstream>

#include "person.hpp"
#include "account.hpp"

using namespace std;

class Bank {
    list<Person *> people;
    list<Account *> accounts;
    string name;

    public:
        Bank(string _name = "??");
        virtual ~Bank();
        void print();
        void show_clients();
        void show_accounts();
        void add_account(Person *person);
        void add_account(Account *account);
        bool remove_account(Account *account);
        Account *get_largest_account();
        list<Account *> *accounts_with_the_least_amount(float amount);
        void export_xml(string filename);
        void wipe_bank();
        Person *search_person(string cc);
        bool deposit(string cc, float dep);
        float bank_total();
        void save_to_file(string filename);
};

#endif // BANCO_H
