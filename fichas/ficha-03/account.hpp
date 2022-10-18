#ifndef CONTA_H
#define CONTA_H

#include <iostream>
#include <string>
#include <list>

#include "person.hpp"

using namespace std;

class Account {
    Person *owner;
    float cash;

    public:
        Account(Person *owner);
        virtual ~Account();
        void deposit(float amount);
        float get_cash() { return cash; }
        Person *get_owner() { return owner; }
        void print();
};

#endif // CONTA_H
