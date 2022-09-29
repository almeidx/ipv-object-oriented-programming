#include <iostream>

using namespace std;

class Product {
	public:
		int price;
		string name;

		Product(int _price, string _name) {
			price = _price;
			name = _name;
		}

		~Product() {
			cout << "Product " << name << " destroyed" << endl;
		}

		int operator+(Product p) {
			return price + p.price;
		}
};

int main(void) {
	Product p1(100, "Apple");
	Product p2(200, "Banana");

	cout << p1 + p2 << endl;

	return 0;
}
