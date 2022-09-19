#include <iostream>
#include <fstream>

void write();
void read();

int main() {
	write();
	read();

	return 0;
}

void write() {
	std::ofstream F("ola.txt", std::ios::app);

	for (int i = 0; i < 10; i++) {
		F << i << std::endl;
	}

	F.close();
}

void read() {
	std::ifstream F("ola.txt");

	int i;

	while (F >> i) {
		std::cout << i << std::endl;
	}

	F.close();
}
