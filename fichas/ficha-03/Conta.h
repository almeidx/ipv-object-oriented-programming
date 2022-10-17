#ifndef CONTA_H
#define CONTA_H

#include <iostream>
#include <string>
#include <list>

#include "Pessoa.h"

using namespace std;

class Conta {
    Pessoa *Titular;
    float SALDO;
    //list<Pessoa *> LTitulares;

    public:
        Conta(Pessoa *t);
        virtual ~Conta();
        void Depositar(float v);
        float Get_Saldo() { return SALDO; }
};

#endif // CONTA_H
