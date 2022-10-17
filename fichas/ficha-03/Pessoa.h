#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Pessoa {
    //list<Conta *> LContas;
    string NOME;
    string BI;
    public:
        Pessoa(string _nome, string _bi);
        virtual ~Pessoa();
        void Show();

       string get_BI();

    protected:

    private:
};

#endif // PESSOA_H
