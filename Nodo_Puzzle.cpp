#include "Nodo_Puzzle.h"

Nodo_Puzzle::Nodo_Puzzle(int** Estado)
{
	Dato=Estado;
	
	adelante = atras = NULL;
}

int** Nodo_Puzzle::datoNodo(){
	return Dato;
}

Nodo_Puzzle* Nodo_Puzzle::getPadre(){
	return Padre;
}

void Nodo_Puzzle::setPadre(Nodo_Puzzle* p){
	Padre=p;
}

Nodo_Puzzle* Nodo_Puzzle::adelanteNodo(){
	return adelante;
}

Nodo_Puzzle* Nodo_Puzzle::atrasNodo(){
	return this->atras;
}

void Nodo_Puzzle::ponerAdelante(Nodo_Puzzle* sgte){
	adelante=sgte;
}

void Nodo_Puzzle::ponerAtras(Nodo_Puzzle* ant){
	atras=ant;
}
