#include "Peixe.h"
#include "Aquario.h"
#include "Uteis.h"

Peixe::Peixe(string esp, int _ns, int _peso, string COR) {
	ESPECIE = esp;
	NSERIE = _ns;
	PESO = _peso;
	this->COR = COR;
}

Peixe::~Peixe() { cout << "Passei em <" << __FUNCTION__ << ">" << endl; }

bool Peixe::RUN() {
	cout << "Passei em <" << __FUNCTION__ << ">" << endl;
	cout << "Peixe: " << NSERIE << " : " << ESPECIE << " Nadando!" << endl;
	cout << "\t Peso: " << PESO << "\a" << endl;
	PESO -= Uteis::Aleatorio(10, 100) / 50;

	if (PESO < 35)
		Aviso_Tenho_Fome();
	return true;
}

void Peixe::Comer(int g) {
	cout << "Passei em <" << __FUNCTION__ << ">" << endl;
	PESO += Uteis::Aleatorio(1, g);
}

void Peixe::Aviso_Tenho_Fome() {
	Pt_Aquario->Registar_Aviso_Fome(this);

	cout << "Passei em <" << __FUNCTION__ << ">" << endl;
}
void Peixe::Aviso_Quero_Sair() { cout << "Passei em <" << __FUNCTION__ << ">" << endl; }
