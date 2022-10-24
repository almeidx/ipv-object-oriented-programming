#ifndef IMAGEM_H
#define IMAGEM_H

#include <iostream>
#include <string>
using namespace std;

#include "PixelRGB.h"

class Imagem {
	string NOME;
	int W, H;
	//----------
	// PixelRGB *Dados;

public:
	Imagem(string _nome, int _w, int _h);
	virtual ~Imagem();
};

#endif // IMAGEM_H
