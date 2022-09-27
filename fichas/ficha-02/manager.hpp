#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <iostream>
#include <list>
#include <iterator>
#include <fstream>
#include <sstream>

#include "person.hpp"

#define PEOPLE_TXT "people.txt"

using namespace std;

// https://stackoverflow.com/a/46931770/11252146
list<string> split(const string &s, char delim) {
    list<string> result;
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim)) {
        result.push_back(item);
    }

    return result;
}

class Manager {
	public:
		list<Person> people;
		Manager() {
			cout << "Manager created" << endl;
		}
		~Manager() {
			cout << "Manager destroyed" << endl;
		}

		bool add_person(string nome, string cidade, int idade) {
			Person p(nome, cidade, idade);
			people.push_back(p);
			return true;
		}

		bool add_person(Person *P) {
			people.push_back(*P);
			return true;
		}

		bool from_file(string nome_ficheiro) {
			ifstream file(nome_ficheiro);
			if (!file.is_open()) {
				return false;
			}

			string line;
			while (getline(file, line)) {
				list<string> tokens = split(line, ';');

				string city = tokens.front();
				tokens.pop_front();
				string name = tokens.front();
				tokens.pop_front();

				int age;
				if (!tokens.empty()) {
					age = stoi(tokens.front());
					add_person(name, city, age);
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
			for (auto &person : people) {
				person.print();
			}
		}

		bool remove(Person *P) {
			bool changed = false;
			people.remove_if([&P, &changed](Person &p) {
				if (p.name == P->name && p.city == P->city && p.age == P->age) {
					changed = true;
					return true;
				}
				return false;
			});
			return changed;
		}

		bool remove(string name) {
			for (auto &person : people) {
				if (person.name == name) {
					remove(&person);
					return true;
				}
			}
			return false;
		}

		bool save_to_file(string filename) {
			ofstream file(filename, ios::trunc);
			if (!file.is_open()) {
				return false;
			}

			for (auto &person : people) {
				file << person.city << ";" << person.name << ";" << (int)person.age << endl;
			}

			file.close();

			return true;
		}

		Person *search_person(string nome) {
			for (auto &person : people) {
				if (person.name == nome) {
					return &person;
				}
			}
			return NULL;
		}

		string get_most_populated_city() {
			string city;
			int count = 0;

			for (auto &person : people) {
				int city_count = 0;
				for (auto &person2 : people) {
					if (person.city == person2.city) {
						city_count++;
					}
				}

				if (city_count > count) {
					city = person.city;
					count = city_count;
				}
			}

			return city;
		}
};

#endif // MANAGER_HPP
