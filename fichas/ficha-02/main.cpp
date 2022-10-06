#include "manager.hpp"

int main(void) {
	Manager m;

	m.from_file(PEOPLE_TXT);
	m.print();

	m.remove("Jose Francisco");

	m.save_to_file("modified.txt");

	Person *p = m.search_person("Joana Monteiro");
	if (p) {
		cout << "Found: " << endl;
		p->print();
	}

	cout << "Most populated city: " << m.get_most_populated_city() << endl;

	return 0;
}
