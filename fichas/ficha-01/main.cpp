#include "../utils.hpp"
#include "sort.hpp"

int main(void) {
	srand(time(NULL));

	// int a = Utils::read_int("a: ");
	// cout << "a = " << a << endl;

#define VEC_SIZE 1000

	int vec[VEC_SIZE];
	Utils::gen_rand_vec(vec, VEC_SIZE);

	Sort::bubble_sort(vec, VEC_SIZE);

	int vec2[VEC_SIZE];
	Utils::gen_rand_vec(vec2, VEC_SIZE);

	Sort::insertion_sort(vec2, VEC_SIZE);
}
