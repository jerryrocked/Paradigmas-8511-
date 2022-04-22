#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <vector>
using namespace std;

class Lista{
	public:
		vector<string> nombres;
    vector<string>::iterator it,it2;
		void InsertarElemento();
		void ListarElementos();
		void BorrarElementoListaPrincipio();
		void BorrarElementosListaFinal();
		void BorrarElementoIntermedio();
};
void Lista::InsertarElemento(){
	string elemento;
	cout<<"Ingresar Nombre: ";
  cin.ignore();
	getline(cin,elemento);
	nombres.push_back(elemento);
  
	
}
void Lista::ListarElementos(){
  int i;
  cout<< "Los Nombres ingresados son: \n";
  for(i=0;i<nombres.size();i++){
    cout<< nombres[i]<< "\n";
    }
  cout<<"\n";
	
}
void Lista::BorrarElementoIntermedio(){
  int i;
  i = nombres.size();
	i = i/2;
  it = nombres.begin()+i;
  nombres.erase(it);
}
void Lista::BorrarElementosListaFinal(){
	nombres.pop_back();
}
void Lista::BorrarElementoListaPrincipio(){
	string primero;
  it = nombres.begin();
  nombres.erase(it);
}
int main(int argc, char** argv){
	Lista lis;
	int opc=1,opc2;
	while(opc !=0){
		cout<<"\n1.- Insertar elemento en la lista ";
		cout<<"\n2.- Listar elementos de la lista";
		cout<<"\n3.- Borrar elemento de la lista";
		cout<<"\n0.- Salir del Programa";
		cout<<"\n=====================================";
   		cout<<"\n Ingresa tu opcion: ";
		cin>>opc;
			switch(opc){
				case 1:
					lis.InsertarElemento();
					break;
				case 2:
					lis.ListarElementos();
          break;
				case 3:
					cout<<"\n 1.- Borrar al final";
					cout<<"\n 2.- Borrar al principio";
					cout<<"\n 3.- Borrar Intermedio";
					cout<<"\n 0.- Volver Menu Anterior";
          cout<<"\n Ingresa tu opcion: ";
					cin>>opc2;
					switch(opc2){
						case 1:
							lis.BorrarElementosListaFinal();
              				cout<<"Se ha borrado el nombre de la lista \n ";
              				lis.ListarElementos();
							break;
						case 2:
							lis.BorrarElementoListaPrincipio();
              				cout<<"Se ha borrado el nombre de la lista \n";
              				lis.ListarElementos();
							break;
						case 3:
							lis.BorrarElementoIntermedio();
              				cout<<"Se ha borrado el noombre de la lista\n";
              				lis.ListarElementos();
							break;
					
			}
          }
			
	}

}

