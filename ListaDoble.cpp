#include "ListaDoble.h"
#include<iostream>
ListaDoble::ListaDoble()
{
}
void ListaDoble::insertarPorCabeza(int** entrada){
	Nodo_Puzzle* nuevo;
	nuevo=new Nodo_Puzzle(entrada);
	nuevo->ponerAdelante(primero);
	if(primero!=NULL)
		primero->ponerAtras(nuevo);
	primero=nuevo;
}

void ListaDoble::insertarUltimo(Nodo_Puzzle* Padre, int** entrada)  {
    if ( primero == NULL ){
        insertarPorCabeza(entrada );
        ultimo = primero;       
        primero->setPadre( Padre );
      return;
    }
        
        
    Nodo_Puzzle* n = new Nodo_Puzzle(  entrada  );
    n->setPadre( Padre );
    ultimo->ponerAdelante( n );
    n->ponerAtras( ultimo );
        
    ultimo = n;
}

Nodo_Puzzle* ListaDoble::buscarLista(int** destino)  {
   Nodo_Puzzle* indice;
        
   for(indice = primero; indice != NULL; indice = indice->adelanteNodo() )
       if(Compara(destino, indice->datoNodo()))
        	return indice;
      
  return NULL;
} 

bool ListaDoble::Compara( int** Valor, int** Almacenado ){
    for ( int x = 0; x < 3;  x++ )
      for ( int y = 0;  y < 3;  y++ )
        if ( Valor[x][y] != Almacenado[x][y] )
          return false;
        
        
  return true;
}

Nodo_Puzzle* ListaDoble::buscarPosicion(int posicion){
  Nodo_Puzzle* indice;
  
  int i;
  
  if(posicion<=0)
    return NULL;
        
  indice = primero;
  for (i = 1;  (i < posicion) && (indice != NULL);  i++)
    indice = indice -> adelanteNodo();
    
  return indice;
}

bool ListaDoble::estaVacia(){
	Nodo_Puzzle *aux;
	aux=primero;
	if(aux==NULL){
		std::cout<<"VACIA";
		return true;
		
	}
	else
		return false;
}

void ListaDoble::Imprimir(){
	Nodo_Puzzle *aux;
	aux=primero;
	while(aux!=NULL){
		std::cout<<" "<<aux->datoNodo();
		aux=aux->adelanteNodo();
	}
}



void ListaDoble::Remover(){
	Nodo_Puzzle* actual=primero;
	if(actual!=NULL){
		//Distingue entre nodo cabezara y resto de la lista
		if(actual==primero && primero==ultimo){
			ultimo=NULL;
			primero=actual->adelanteNodo();
			if(actual->adelanteNodo() != NULL){
				actual->adelanteNodo()->ponerAtras(NULL);
				actual->ponerAdelante(NULL);
			}
		//	delete actual;
		}
		if(actual==primero){
			primero=actual->adelanteNodo();
			if(actual->adelanteNodo() != NULL){
				actual->adelanteNodo()->ponerAtras(NULL);
				actual->ponerAdelante(NULL);
			}
		//	delete actual;
		}
		
	}
}

int** ListaDoble::getCabezaNodo(){
	if(primero!=NULL){
		return primero->datoNodo();
	}
	else
		return NULL;
}
