#include "main.hpp"

int main() {
	histograma(123);

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
	int n1;

	for (int line = 9; line > 0; line--) {
		n1 = invert_number(n);

		while (n1 > 0) {
			if (n1 % 10 >= line) {
				cout << "* ";
			} else {
				cout << "- ";
			}

			n1 /= 10;
		}

		cout << endl;
	}

	// Pretty-print number at the bottom
	n1 = invert_number(n);
	while (n1 > 0) {
		cout << n1 % 10 << " ";
		n1 /= 10;
	}

	cout << endl;
}

int invert_number(int n) {
	int inverted = 0;

	while (n > 0) {
		inverted = inverted * 10 + n % 10;
		n /= 10;
	}

	return inverted;
}

// Other implementation using strings
void histograma_string(int n) {
	string str = to_string(n);

	for (int line = 9; line > 0; line--) {
		for (auto &c : str) {
			int val = (int)(c - '0');

			if (line > val) {
				cout << "- ";
			} else {
				cout << "* ";
			}
		}

		cout << endl;
	}

	for (auto &c : str) {
		cout << c << " ";
	}

	cout << endl;
}
