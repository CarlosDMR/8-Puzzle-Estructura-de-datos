#include <iostream>
#include"string.h"
#include"Arbol.h"
#include"ListaDoble.h"
using namespace std;
int** Tx=0;
int y=2;
int x=2;

int** TableroFinal();
int** CrearTablero();
int** ClonarTablero(int** Tb);
void imprimirtb(int** Tb);
int** Arriba(int** Tb);
int** Abajo(int** Tb);
int** Der(int** Tb);
int** Izq(int** Tb);



int main(int argc, char** argv) {
	int** Final;//Matriz Final
	int** Inicial;//Matriz Inicial
	ListaDoble LNE;//Lista de Nodos a Explorar
	ListaDoble LEE;//Lista de Estados Explorados
	int cont=0;
	
	cout<<"Estado Final:"<<endl;
	Final=TableroFinal();//Se define tablero de estado final
	imprimirtb(Final);//Se imprime el tablero con el estado final
	cout<<"Estado Inicial:"<<endl;
	Inicial=CrearTablero();//Se define el tablero inicial
	imprimirtb(Inicial);//Se imprime el tablero con el estado inicial
	
	
	LNE.insertarUltimo(NULL,Inicial);//Se inserta el tablero inicial a la Lista de Nodos a Explorar(Su Padre es Null debido a que es el primer elemento)
	
	while(!LNE.estaVacia()){//Verificamos que la Lista de Nodos a Explorar no se encuentre vacia
		int** ME=0;//Creamos una Matriz Estado
		
		Nodo_Puzzle* p; //=new Nodo_Puzzle(Inicial);
		p=LNE.buscarPosicion(1);//Obtenermos el primer nodo de la LNE
		ME = p->datoNodo();//Obtenermos el dato almacenado
		
		int** Aux=0;//Creamos la matriz temporal		
		Aux = ClonarTablero(ME);//Clonamos en AUX la matrix estado
		
		if (LNE.Compara(Final,ME)){//Comparamos si la matriz estado es igual a la matriz final
			cout<<"Solucion encontrada\n";
			while(p != NULL){//Mientras nuestra matriz tenga padre
				cout<<"Paso #"<<++cont<<endl;
				imprimirtb(p->datoNodo());//Imprimimos la matriz más hija
				p=p->getPadre();//Obtenemos el padre de nuestra matriz
			}
			break;
		}
		
		
		LEE.insertarUltimo(p, ME);//Insertamos nuestra Matriz Estado en la Lista de Estados Explorados	
			if(Abajo(Aux)!=NULL){
				if(LEE.buscarLista(Aux)==NULL){
					LNE.insertarUltimo(p,Aux);
				}
			}
			Aux=ClonarTablero(ME);
			if(Arriba(Aux)!=NULL ){
				if(LEE.buscarLista(Aux)==NULL){
					LNE.insertarUltimo(p,Aux);
				}
			}
			Aux=ClonarTablero(ME);
			if(Izq(Aux)!=NULL){
				if(LEE.buscarLista(Aux)==NULL){
					LNE.insertarUltimo(p,Aux);
				}
			}
			Aux=ClonarTablero(ME);
			if(Der(Aux)!=NULL){
				if(LEE.buscarLista(Aux)==NULL){
					LNE.insertarUltimo(p,Aux);
				}
			}
			
			LNE.Remover();
	}
	return 0;
}

int** TableroFinal(){
	int cont=1;
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

int** CrearTablero(){
	int r=0;
	Tx=new int*[3];
	for(int i=0; i<3; i++){
		Tx[i]=new int[3];
		for(int j=0; j<3; j++){
			cout<<"["<<i<<"]["<<j<<"] = ";cin>>r;
			Tx[i][j]=r;	
			if(r==0){
				y=i;
				x=j;
			}
		}
	}
	cout<<endl;
	return Tx;
}

int** ClonarTablero(int** Tb){

	Tx=new int*[3];
	for(int i=0; i<3; i++){
		Tx[i]=new int[3];
		for(int j=0; j<3; j++){
			Tx[i][j]=Tb[i][j];	
			if(Tb[i][j]==0){
				y=i;
				x=j;
			}
		}
	}

	return Tx;
}


void imprimirtb(int** Tb){
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
			std::cout<<"["<<Tb[i][j]<<"]";
		}
	std::cout<<"\n";
	}
	cout<<"\n";
}



int** Arriba(int** Tb){
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

int** Abajo(int** Tb){
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

int** Der(int** Tb){	
	if(x<=1){
		Tb[y][x] = Tb[y][x+1];
		Tb[y][x+1]=0;
		x++;
		
		return Tb;
	}
	else
		return NULL;
}

int** Izq(int** Tb){
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


