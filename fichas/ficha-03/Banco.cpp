#include "Banco.h"

Banco::Banco(string _nome) {
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    NOME = _nome;
}

Banco::~Banco() {
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    LimparBanco();
}

void Banco::Show() {
    //cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    ShowClientes();
    ShowContas();
}

void Banco::ShowClientes() {
    //cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    cout << "Banco: [" << NOME << "]" << endl;
    list<Pessoa *>::iterator it;
    for (it = LP.begin(); it != LP.end(); ++it)
        (*it)->Show();
}

void Banco::ShowContas() {
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
}

void Banco::Add(Pessoa *P) {
    //cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    if (P) LP.push_back(P);
}

void Banco::Add(Conta *C) {
    //cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    if (C) LC.push_back(C);
}

bool Banco::RemoverConta(Conta *C) {
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    return false;
}

Conta *Banco::PesquisarContaMaisGordinha() {
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    return NULL;
}

list<Conta *> *Banco::ContasSaldoInferior(float valor) {
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;

    list<Conta *> *lc = new list<Conta *>();
    list<Conta *>::iterator itc;

    for (itc = LC.begin(); itc != LC.end(); ++itc) {
        Conta *X = (*itc);
        if (X->Get_Saldo() < valor)
            lc->push_back(X);
    }

    return lc;
}

void Banco::ExportarXML(string nf) {
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
}

void Banco::LimparBanco() {
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    list<Pessoa *>::iterator it;

    for (it = LP.begin(); it != LP.end(); ++it)
        delete (*it);

    LP.clear();

    list<Conta *>::iterator itc;

    for (itc = LC.begin(); itc != LC.end(); ++itc)
        delete (*itc);

    LC.clear();
}

Pessoa *Banco::PesquisarPessoa(string bi) {
    list <Pessoa *>::iterator it;

    for (it = LP.begin(); it != LP.end(); ++it) {
        string comp = (*it)->get_BI();

        if (comp.compare(bi) == 0)
            return (*it);
    }

    return NULL;
}

void Banco::Depositar(string bi, float dep) {
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
}
