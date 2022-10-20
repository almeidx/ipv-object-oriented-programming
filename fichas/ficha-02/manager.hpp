#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <fstream>
#include <map>

#include "../utils.hpp"
#include "person.hpp"

#define PEOPLE_TXT "people.txt"

class Manager {
	map<string, list<Person *>> cities;

public:
	Manager() { cout << "Manager created" << endl; }

	~Manager() { cout << "Manager destroyed" << endl; }

	bool add_person(string nome, string cidade, int idade) { return add_person(new Person(nome, cidade, idade)); }

	bool add_person(Person *P) {
		cities[P->city].push_back(P);
		return true;
	}

	bool from_file(string nome_ficheiro) {
		ifstream file(nome_ficheiro);
		if (!file.is_open()) {
			return false;
		}

		string line;
		while (getline(file, line)) {
			list<string> tokens = Utils::split(line, ';');

			string city = tokens.front();
			tokens.pop_front();
			string name = tokens.front();
			tokens.pop_front();

			int age;
			if (!tokens.empty()) {
				age = stoi(tokens.front());
			} else {
				age = 18;
			}

			add_person(name, city, age);

			tokens.clear();
		}

		file.close();

		return true;
	}

	void print() {
		for (const auto &pair : cities) {
			list<Person *> people = pair.second;

			for (auto person : people) {
				person->print();
			}
		}
	}

	bool remove(Person *P) {
		cities[P->city].remove(P);
		delete P;
		return true;
	}

	bool remove(string name) {
		for (auto &pair : cities) {
			list<Person *> people = pair.second;

			for (auto person : people) {
				if (person->name == name) {
					remove(person);
					// delete person;
					return true;
				}
			}
		}

		return false;
	}

	bool save_to_file(string filename) {
		ofstream file(filename, ios::trunc);
		if (!file.is_open()) {
			return false;
		}

		for (auto &pair : cities) {
			list<Person *> people = pair.second;

			for (auto person : people) {
				file << person->city << ";" << person->name << ";" << (int)person->age << endl;
			}
		}

		file.close();

		return true;
	}

	Person *search_person(string nome) {
		for (auto &pair : cities) {
			list<Person *> people = pair.second;

			for (auto person : people) {
				if (person->name == nome) {
					return person;
				}
			}
		}

		return NULL;
	}

	string get_most_populated_city() {
		string city;
		int count = 0;

		for (auto &pair : cities) {
			list<Person *> people = pair.second;

			for (auto &person : people) {
				int city_count = 0;
				for (auto &person2 : people) {
					if (person->city == person2->city) {
						city_count++;
					}
				}

				if (city_count > count) {
					city = person->city;
					count = city_count;
				}
			}
		}

		return city;
	}
};

#endif // MANAGER_HPP
