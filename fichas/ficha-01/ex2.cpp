#include <iostream>
#include <iterator>
#include <list>
#include <fstream>
#include <sstream>
#include <algorithm>

#define WORDS_FILENAME "words.txt"

using namespace std;

/*
Considere uma lista de strings. Implemente as funcionalidades seguintes:
	a) Declarar uma list de strings;
	b) Implemente uma função para ler de um ficheiro de texto todas as palavras e colocar na lista;
	c) Contar todas as palavras;
	d) Listar as palavras que estão na lista;
	e) Listar ao contrário o conteúdo da lista;
	f) Eliminar uma palavra da lista (dada a palavra);
	g) Eliminar uma palavra da lista (dada uma posição da lista);
	h) Verificar se existem palavras repetidas;
	i) Contar o numero de palavras de tamanho inferior a 5;
	j) Passar todas as palavras da lista para maiúsculas;
	k) Gravar num ficheiro de texto as palavras de tamanho superior a 10.
 */
int main(void) {
	ifstream file(WORDS_FILENAME);
	if (!file.is_open()) {
		cerr << "ERROR: could not open " WORDS_FILENAME << endl;
		return 1;
	}

	// a)
 	list<string> words;

	// b)
	string word;
	while (getline(file, word)) {
		words.push_back(word);
	}

	file.close();

	// c)
	cout << "Total words: " << words.size() << endl;

	// e)
	words.reverse();

	// f)
	words.remove("nemo");

	// g)
	auto it = words.begin();
	advance(it, 2);
	words.erase(it);

	// h)
	list<string> duplicates;
	for (auto &word : words) {
		int amount = count(words.begin(), words.end(), word);
		if (amount > 1) {
			duplicates.push_back(word);
		}
	}
	cout << "Duplicates (" << duplicates.size() << "):" << endl;
	for (auto &word : duplicates) {
		cout << word << endl;
	}

	// i)
	int small_words = count_if(words.begin(), words.end(), [](string &word) {
		return word.size() < 5;
	});
	cout << "Small words: " << small_words << endl;

	// j)
	for_each(words.begin(), words.end(), [](string &word) {
		transform(word.begin(), word.end(), word.begin(), ::toupper);
	});

	// k)
	ofstream big_words_file("words_out.txt", ios::trunc);
	for_each(words.begin(), words.end(), [&big_words_file](string &word) {
		if (word.size() > 10) {
			big_words_file << word << endl;
		}
	});
	big_words_file.close();

	return 0;
}
