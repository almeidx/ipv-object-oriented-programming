#include "Conta.h"

Conta::Conta(Pessoa *t) {
    Titular = t;
    SALDO = 0;
}

Conta::~Conta() {
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    //delete Titular;
}

void Conta::Depositar(float v) {
    if (v >= 0) {
        SALDO += v;
    } else {
        cout << "ATENÇÃO: So depositar valores > 0" << endl;
    }
}
