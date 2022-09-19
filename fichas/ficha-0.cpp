#include <iostream>
#include <string>

using namespace std;

void histograma(int n);

int main() {
	histograma(251);

	return 0;
}

/*
	Pretende-se um programa que visualize no ecrã (em modo console) um histograma dado num número inteiro.
		- O número deve ser pedido;
		- Pode/deve gravar para ficheiro (à C) o histograma;
	Exemplos:
		Histograma(251)
		- - -
		- - -
		- - -
		- - -
		- * -
		- * -
		- * -
		* * -
		* * *
		2 5 1
 */
void histograma(int n) {
	string str = to_string(n);

	for (int line = 10; line > 0; line--) {
		for (auto &c : str) {
			cout <<  ' ';
			if (line > (int)c) {
				cout << "- ";
			} else {
				cout << "* ";
			}
		}

		cout << endl;
	}

	cout << n << endl;
}
