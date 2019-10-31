#include "Tablero.h"
#include"Arbol.h"
#include"string.h"
#include"ListaDoble.h"
#include <iostream>
Tablero::Tablero()
{
	int x=2;
	int y=2;
	int cont=1;
}


int** Tablero::TableroFinal(){
	Tx=0;
	Tx= new int*[3];
	for(int i=0; i<3; i++){
		Tx[i]=new int[3];
	for(int j=0; j<3; j++){
			Tx[i][j]=cont;			
			cont++;	
		}
	}
	Tx[y][x]=0;
	return Tx;
}

int** Tablero::CrearTablero(){
	int r=0;
	Tx=new int*[3];
	for(int i=0; i<3; i++){
		Tx[i]=new int[3];
		for(int j=0; j<3; j++){
			std::cin>>r;
			Tx[i][j]=r;	
			if(r==0){
				y=i;
				x=j;
			}
		}
	}

	return Tx;
}

void Tablero::imprimirtb(int** Tb){
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
			std::cout<<"["<<Tb[i][j]<<"]";
		}
	std::cout<<"\n";
	}
}



int** Tablero::Arriba(int** Tb){
	if(y>=1){
		Tb[y][x] = Tb[y-1][x];
		Tb[y-1][x]=0;
		y--;
		return Tb;
	}
	else{
		return NULL;
	}
}

int** Tablero::Abajo(int** Tb){
	if(y<=1){
		Tb[y][x] = Tb[y+1][x];
		Tb[y+1][x]=0;
		y++;
		return Tb;
	}
	else{
		return NULL;
	}
}

int** Tablero::Der(int** Tb){	
	if(x<=1){
		Tb[y][x] = Tb[y][x+1];
		Tb[y][x+1]=0;
		x++;
		return Tb;
	}
	else
		return NULL;
}

int** Tablero::Izq(int** Tb){
	if(x>=1){
		Tb[y][x] = Tb[y][x-1];
		Tb[y][x-1]=0;
		x--;
		return Tb;
	}
	else{
		return NULL;
	}
}



int** Tablero::Solucion(Tablero A,int** Inicial, Nodo_Puzzle* p, ListaDoble LNE){
		int** Aux=NULL;
		Aux=Inicial;
		if(A.Der(Aux)!=NULL){
			LNE.insertarUltimo(p,Aux);
			Inicial=Aux;
			return Inicial;
		}
		if(A.Arriba(Aux)!=NULL){
			LNE.insertarUltimo(p,Aux);
			Inicial=Aux;
			return Inicial;
		}
		if(A.Abajo(Aux)!=NULL){
			LNE.insertarUltimo(p,Aux);
			Inicial=Aux;
			return Inicial;
		}
		if(A.Izq(Aux)!=NULL){
			LNE.insertarUltimo(p,Aux);
			Inicial=Aux;
			return Inicial;
		}
}


