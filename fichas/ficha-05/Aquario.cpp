#include "Aquario.h"
#include "Uteis.h"

Aquario::Aquario(string _ns) { NSERIE = _ns; }

Aquario::~Aquario() {
	cout << "Passei em <" << __FUNCTION__ << ">" << endl;
	Esvaziar_Limpar();
}

void Aquario::RUN() {
	cout << "Passei em <" << __FUNCTION__ << ">" << endl;
	bool PARAR = false;
	while (!PARAR) {
		for (list<Peixe *>::iterator it = LPeixes.begin(); it != LPeixes.end(); ++it)
			(*it)->RUN();

		Uteis::DELAY(500);
	}
}

void Aquario::ADD(Peixe *P) {
	cout << "Passei em <" << __FUNCTION__ << ">" << endl;
	if (P) {
		P->Ficas_Neste_Aquario(this);
		LPeixes.push_back(P);
	}
}

/** \brief Para pesquisar um peixe
 *
 * \param _ns string
 * \return Peixe*
 * \author FM And alunos
 */
Peixe *Aquario::Pesquisar(string _ns) {
	cout << "Passei em <" << __FUNCTION__ << ">" << endl;
	return NULL;
}

/** \brief Para remover um peixe
 *
 * \param P Peixe*
 * \return bool
 * \date 31/10/2022
 */
bool Aquario::Remover(Peixe *P) {
	cout << "Passei em <" << __FUNCTION__ << ">" << endl;
	return false;
}

bool Aquario::Remover(string ns) {
	cout << "Passei em <" << __FUNCTION__ << ">" << endl;
	return false;
}

void Aquario::Alimentar(int x) { cout << "Passei em <" << __FUNCTION__ << ">" << endl; }

void Aquario::Mover_Brasas() { cout << "Passei em <" << __FUNCTION__ << ">" << endl; }

void Aquario::Esvaziar_Limpar() { cout << "Passei em <" << __FUNCTION__ << ">" << endl; }

void Aquario::Registar_Aviso_Fome(Peixe *P) { LFome.push_back(P); }
