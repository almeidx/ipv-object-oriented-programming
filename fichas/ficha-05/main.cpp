#include <iostream>

#include "Aquario.h"
#include "Peixe.h"
#include "Uteis.h"
#include "time.h"

using namespace std;

void Start() { srand(time(NULL)); }

int main() {
	cout << "Hello world!" << endl;
	// Uteis::DELAY(5000);
	// cout << "Fim" << endl;
	// return 0;

	int NSERIE_PEIXE = 500;
	Start();

	Aquario *AQ;
	AQ = new Aquario();

	Peixe *P1 = new Peixe("Sardinha", NSERIE_PEIXE++, 15);
	AQ->ADD(P1);
	P1 = new Peixe("Carapau", NSERIE_PEIXE++, 150);
	AQ->ADD(P1);

	AQ->RUN();

	delete AQ;
	return 0;
}
