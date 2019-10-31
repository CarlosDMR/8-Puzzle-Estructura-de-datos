#include"string.h"
#include"Nodo_Puzzle.h"
#ifndef LISTADOBLE_H
#define LISTADOBLE_H

class ListaDoble
{
	private:
		Nodo_Puzzle* primero=NULL;
		Nodo_Puzzle* ultimo=NULL;
	public:
		ListaDoble();
		void insertarUltimo(Nodo_Puzzle* Padre, int**);
		Nodo_Puzzle* buscarLista(int** destino);
		bool Compara(int** valor, int** Almacenado);
		Nodo_Puzzle* buscarPosicion(int posicion);
		bool estaVacia();
		void insertarPorCabeza(int** entrada);
		void eliminar(DataType entrada);
		void Imprimir();
		void Remover();	
		void Solucion(Nodo_Puzzle* p);	
		int** getCabezaNodo();
};

#endif
