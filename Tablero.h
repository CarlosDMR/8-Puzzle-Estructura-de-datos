#include"Nodo_Puzzle.h"
#include"Arbol.h"
#include"ListaDoble.h"
#ifndef TABLERO_H
#define TABLERO_H
class Tablero
{
	private:
		int** Tx=0;
		int** Tb=0;
		int x=2;
		int y=2;
		int cont=1;
	public:
		Tablero();
		int** TableroFinal();
		int** CrearTablero();
		int** Arriba(int** tb);
		int** Abajo(int** tb);
		int** Izq(int** tb);
		int** Der(int** tb);
		void imprimirtb(int** tb);
		int** Solucion(Tablero A, int** Inicial, Nodo_Puzzle* p, ListaDoble LNE);
};

#endif
