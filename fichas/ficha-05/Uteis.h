#ifndef UTEIS_H
#define UTEIS_H

#include <iostream>
#include <string>

#include <math.h>

// #include <time.h> /* clock_t, clock, CLOCKS_PER_SEC */

#ifdef _WIN32
#include "windows.h"
#else
#include "unistd.h"
#endif // _WIN32

using namespace std;

class Uteis {
public:
	Uteis();
	virtual ~Uteis();

	static void DELAY(int ms) {
		// clock_t T0 = clock();
		// clock_t T1 = T0 + ms;
		// while (clock() < T1)
		// 	;

#ifdef _WIN32
		Sleep(ms);
#else
		usleep(ms * 1000); // microseconds
#endif // _WIN32
	}

	static int Aleatorio(int _min, int _max) { return _min + rand() % (_max - _min + 1); }
};

#endif // UTEIS_H
