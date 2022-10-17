#ifndef BANCO_H
#define BANCO_H

#include <iostream>
#include <string>
#include <list>

#include "Pessoa.h"
#include "Conta.h"

using namespace std;

class Banco {
    list<Pessoa *> LP;
    list<Conta *> LC;
    string NOME;

    public:
        Banco(string _nome = "??");
        virtual ~Banco();
        void Show();
        void ShowClientes();
        void ShowContas();
        void Add(Pessoa *P);
        void Add(Conta *C);
        bool RemoverConta(Conta *C);
        Conta *PesquisarContaMaisGordinha();
        list<Conta *> *ContasSaldoInferior(float valor);
        void ExportarXML(string nf);
        void LimparBanco();
        Pessoa *PesquisarPessoa(string bi);
        void Depositar(string bi, float dep);
};

#endif // BANCO_H
