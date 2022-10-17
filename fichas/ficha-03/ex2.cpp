#include <iostream>

using namespace std;

#include "Banco.h"

int main() {
    cout << "Hello world!" << endl;

    Banco BES("BES-NOVO BANCO");

    Pessoa *P1 = new Pessoa("Ze", "2343");

    BES.Add(P1);

    Conta *C = new Conta(P1);

    BES.Add(C);
    BES.Show();

    return 0;
}
