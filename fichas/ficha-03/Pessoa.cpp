#include "Pessoa.h"

Pessoa::Pessoa(string _nome, string _bi) {
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    NOME = _nome;
    BI = _bi;
}

Pessoa::~Pessoa() {
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
}

string Pessoa::get_BI() {
    return BI;
}

void Pessoa::Show() {
    cout << "PESSOA: [" << NOME << "] : [" << BI << "]" << endl;
}
