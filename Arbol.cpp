#include "Arbol.h"
#include "string.h"
#include<iostream>
Arbol::Arbol(){root = NULL;}

Arbol::Arbol(NODO *r){
	root=r;
}

void Arbol::setRoot(NODO *r){
	root=r;
}

NODO* Arbol::getRoot(){
	return root;
}

NODO Arbol::rootTree(){
	if(root)
		return *root;
	else{
		throw"arbol vacio"; 
		return NULL;
	}
}

bool Arbol::isEmpty(){
	return root==NULL;
}

NODO* Arbol::getLeftSubTree(){
	if(root)
		return root->getLeft();
	else{
		throw"arbol vacio"; return NULL;
	}
}

NODO* Arbol::getRightSubTree(){
	if(root)
		return root->getRight();
	else{
		throw"arbol vacio";return NULL;
	}
}

NODO* Arbol::add(NODO* leftSubTree, DataType Data, NODO* rightSubTree){
	return new NODO(leftSubTree, Data, rightSubTree);
}

void Arbol::preOrder(NODO *r){
	if(r!=NULL){
		r->visit();
		preOrder(r->getLeft());
		preOrder(r->getRight());
	}
}

void Arbol::preOrder(){
	preOrder(root);
	std::cout<<std::endl;
}

void Arbol::enOrder(NODO *r){
	if(r!=NULL){
		enOrder(r->getLeft());
		r->visit();
		enOrder(r->getRight());
	}
}

void Arbol::enOrder(){
	enOrder(root);
	std::cout<<std::endl;
}

void Arbol::postOrder(NODO *r){
	if(r!=NULL){
		postOrder(r->getLeft());
		postOrder(r->getRight());
		r->visit();
	}
}

void Arbol::postOrder(){

	postOrder(root);
 	std::cout<<std::endl;
	
}

void Arbol::DeleteTreePost(){
	DeleteTreePost(root);
	root=NULL;
}

void Arbol::DeleteTreePost(NODO *r){
	if(r!=NULL){
		DeleteTreePost(r->getLeft());
		DeleteTreePost(r->getRight());
		
		r->setLeft(NULL);
		r->setRight(NULL);
		
		delete r;
		r=NULL;
	}	
}

NODO* Arbol::insert(NODO* root, DataType value){
	if(root==NULL)
		root = new NODO(value);
	else if(value < root->getData()){
		NODO *lt; lt=insert(root->getLeft(), value);
		root->setLeft(lt);
	}
	else if(value > root->getData()){
		NODO *rt; rt=insert(root->getRight(), value);
		root->setRight(rt);
	}
	else
		throw "NODO duplicado";
	return root;
}

void Arbol::insert(DataType data){
	root=insert(root, data);
}

NODO* Arbol::Delete(NODO* root, DataType data){
	if(root == NULL)
		throw "NO SE HA ENCONTRADP EL NODO CON LA CLAVE";
	else if(data < root->getData()){
		NODO* lt;
		lt=Delete(root->getLeft(), data);
		root->setLeft(lt);
	}
	else if(data > root->getData()){
		NODO* rt;
		rt=Delete(root->getRight(),data);
		root->setRight(rt);
	}
	
	else{//NODO ENCONTRADO
	NODO* q;
	q=root;
	if(q->getLeft()==NULL)
		root=q->getRight();
	else if(q->getRight()==NULL)
		root=q->getLeft();
	else
		q=replace(q);
	}
	return root;
}

void Arbol::Delete(DataType value){
	root=Delete(root,value);
}

NODO* Arbol::replace(NODO* act){
	NODO *a, *p=act;
	
	a=act->getLeft();
	
	while(a->getRight() != NULL){
		p=a;
		a=a->getRight();
	}
	
	act->setData(a->getData());
	
	if(p==act)
		p->setLeft(a->getLeft());
	else
		p->setRight(a->getLeft());
		
	return a;
}


