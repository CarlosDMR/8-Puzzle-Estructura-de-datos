#include "NODO.h"
#include<iostream>
#include"string.h"
NODO::NODO(DataType Value){
	Data=Value;
	left=right=NULL;
}

NODO::NODO(NODO* leftPtr, DataType Value, NODO* rightPtr){
	Data=Value;
	left=leftPtr;
	right=rightPtr;
}

DataType NODO::getData(){return Data;}

void NODO::setData(DataType Value){ Data=Value; }

NODO* NODO::getPadre(){ return Padre; }

NODO* NODO::getLeft(){ return left; }

NODO* NODO::getRight(){ return this->right; }

void NODO::setLeft(NODO* leftPtr){
	left=leftPtr;
}

void NODO::setRight(NODO* rightPtr){
	right=rightPtr;
}

void NODO::setPadre(NODO* p){
	Padre=p;
}

void NODO::visit(){
	std::cout<<Data<<" ";
}
