#ifndef SORT_HPP
#define SORT_HPP

#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace chrono;

#define TIMING_FILENAME "timings.csv"

class Sort {
	public:
		static void bubble_sort(int *vec, int size) {
			int i, j, aux;
			long n_swaps = 0;

			// clock_t start = clock();
			auto start = high_resolution_clock::now();

			for (i = 0; i < size; i++) {
				for (j = i + 1; j < size; j++) {
					if (vec[i] > vec[j]) {
						aux = vec[i];
						vec[i] = vec[j];
						vec[j] = aux;
						n_swaps++;
					}
				}
			}

			auto duration = duration_cast<nanoseconds>(high_resolution_clock::now() - start);
			// double seconds = (double)(clock() - start) / CLOCKS_PER_SEC;

			ofstream F(TIMING_FILENAME, ios::app);
			// F << __FUNCTION__ << "," << size << "," << n_swaps << "," << std::fixed << std::setprecision(10) << seconds << endl;
			F << __FUNCTION__ << "," << size << "," << n_swaps << "," << duration.count() << endl;
			F.close();
		}

		static void insertion_sort(int *vec, int size) {
			int i, j, aux;
			long n_swaps = 0;

			// clock_t start = clock();
			auto start = high_resolution_clock::now();

			for (i = 1; i < size; i++) {
				aux = vec[i];
				j = i - 1;

				while (j >= 0 && vec[j] > aux) {
					vec[j + 1] = vec[j];
					j--;
					n_swaps++;
				}

				vec[j + 1] = aux;
			}

			auto duration = duration_cast<nanoseconds>(high_resolution_clock::now() - start);
			// double seconds = (double)(clock() - start) / CLOCKS_PER_SEC;

			ofstream F(TIMING_FILENAME, ios::app);
			// F << __FUNCTION__ << "," << size << "," << n_swaps << "," << std::fixed << std::setprecision(10) << seconds << endl;
			F << __FUNCTION__ << "," << size << "," << n_swaps << "," << duration.count() << endl;
			F.close();
		}
};

#endif // SORT_HPP
