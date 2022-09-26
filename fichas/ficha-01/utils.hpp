#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <time.h>

using namespace std;

class Utils {
	public:
		static int read_int(string prompt) {
			int value;
			cout << prompt;
			cin >> value;
			return value;
		}

		static void gen_rand_vec(int *vec, int size) {
			for (int i = 0; i < size; i++) {
				vec[i] = rand() % 100;
			}
		}

		static void show_vec(int *vec, int size) {
			for (int i = 0; i < size; i++) {
				cout << vec[i] << " ";
			}

			cout << endl;
		}
};

#endif // UTILS_HPP
