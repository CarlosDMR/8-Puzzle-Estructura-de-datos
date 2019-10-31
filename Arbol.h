#ifndef ARBOL_H
#define ARBOL_H
#include"NODO.h"

class Arbol
{
	private:
		NODO *root;
		DataType data;
		void preOrder(NODO *r);
		void enOrder(NODO *r);
		void postOrder(NODO *r);
		void DeleteTreePost(NODO *r);
		NODO* insert(NODO* root, DataType data);
		NODO* Delete(NODO* root, DataType);
		
	public:
		Arbol();
		Arbol(NODO *r);
		void setRoot(NODO *r);
		NODO* getRoot();
		NODO rootTree();
		bool isEmpty();
		NODO* getLeftSubTree();
		NODO* getRightSubTree();
		NODO* add(NODO* leftSubTree, DataType Data, NODO* rightSubTree);
		void preOrder();
		void enOrder();
		void postOrder();
		void DeleteTreePost();
		void insert(DataType value);
		void Delete(DataType value);
		NODO* replace(NODO* act);
};
#endif
