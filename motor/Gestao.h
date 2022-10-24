#ifndef GESTAO_H
#define GESTAO_H

#include <algorithm>
#include <iostream>
#include <list>
#include <string>

using namespace std;
#include "Admin.h"
#include "MCombustao.h"
#include "MEletrico.h"
#include "Normal.h"
#include "Visitante.h"


class Gestao {
	list<User *> LUsers;
	list<Motor *> LMotores;
	list<Motor *> LMQuentes;

	User *Ut_Atual;

public:
	Gestao(User *ut);
	virtual ~Gestao();
	void EstouQuente(Motor *M);
	void Ligar_Motores();
	void Run();
	void Add(User *X) {
		LUsers.push_back(X);
		Ut_Atual = X;
	}
	void Add(Motor *M);

	void Manutencao();
};

#endif // GESTAO_H
