#include"string.h"

#ifndef NODO_H
#define NODO_H
typedef int** DataType;

class NODO
{
	private:
		DataType Data = NULL;
		NODO* Padre;
		NODO* left;
		NODO* right;
	public:
		NODO(DataType Value);
		NODO(NODO* leftPtr, DataType Value, NODO* rightPtr);
		DataType getData();
		void setData(DataType Value);
		NODO* getPadre();
		NODO* getLeft();
		NODO* getRight();
		void setPadre(NODO* p);
		void setLeft(NODO* leftPtr);
		void setRight(NODO* rightPtr);
		void visit();
};

#endif
