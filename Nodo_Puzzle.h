#include "string.h"
#ifndef NODO_PUZZLE_H
#define NODO_PUZZLE_H
typedef int** DataType;
class Nodo_Puzzle
{
	private:
		int** Dato=NULL;
		Nodo_Puzzle* Padre;
		Nodo_Puzzle* adelante;
		Nodo_Puzzle* atras;
	public:
		Nodo_Puzzle(int** Estado);
		int** datoNodo();
		Nodo_Puzzle* getPadre();
		void setPadre(Nodo_Puzzle* p);
		Nodo_Puzzle* adelanteNodo();
		Nodo_Puzzle* atrasNodo();
		void ponerAdelante(Nodo_Puzzle* sgte);
		void ponerAtras(Nodo_Puzzle* ant);
};

#endif
