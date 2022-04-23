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
///codigo:Elías Hidalgo
///parte 1: crear todas las clases necesarias
class persona{
    public:
    int p;
    char nombre[40];
    char rut[12];
    char sex;
	persona(){ };
	~persona(){ };
	void datos_per();
	void mostrar_per();
};
///datos
  void persona::datos_per() {
    cout<<"Escriba su Nombre ";
    cin>>nombre;
    cout<<"Escriba su RUT ";
    cin>>rut; 
    cout<<"sexo:"; cin>>sex;
    };
///mostrarlos
void persona::mostrar_per(){
    cout<<"nombre:"<<nombre<<endl;
    cout<<"rut:"<<rut<<endl;
    cout<<"sexo:"<<sex<<endl;
}


class estudiante:public persona{
    public:
    int e;
    string est;
    estudiante(){};
    ~estudiante(){};
    void datos_est();
    void mostrar_est();
};
void estudiante::datos_est(){
    int e;
    datos_per();
    cout<<"carrera que estudia:";
    cin>>est;  
};
void estudiante::mostrar_est(){
    mostrar_per();
    cout<<"carrera:"<<est;
}
      
class profesor : public persona{
    public:
    profesor(){};
    ~profesor(){};
    void datos_prof();
    void mostrar_prof(){};
    void subir_notas(){};
};
void profesor::datos_prof(){
    int i;
    datos_per();
};
void profesor::mostrar_prof(){
    int i;
    mostrar_per();
};

class asignatura:public profesor , public estudiante{
    public:
    string codigo[5]={"PR001","BD002","AE003","DM004","PP005"};
    string asignatura[100]={"PROGRAMACION","BASE_DE_DATOS","ALGORITMO_Y_ESTRUCTURA_DE_DATOS","DESARROLLO WEB Y MOBIL","PARADIGMA DE PROGRAMACION"};
    int cantidad;
    char nom[100]="estudiante.txt";
    string a[30];
    string b[30], c[30];
    void ingresar_dato_est1();
    void mostrar_est();
    void ingresar_dato_prof();
    void mostrar_prof();
    void promedios();

void ingresar_notas(); asignatura::ingresar_dato_est();{
    
};

void asignatura::mostrar_est1(){
};

void asignatura::ingresar_dato_prof(){
    
}
void asignatura::mostrar_prof(){
    
}
void asignatura::promedio(){
    
}
};
int main(int argc, char** argv) {
    ///imprimir lo procesado
    asignatura as;
    int eleccion;
    while (eleccion !=5){
        cout<<"sistema de notas";
        cout<<"1.ingresar estudiante";
        cout<<"2.ingresar profesor";
        cout<<"3.ingresar notas";
        cout<<"4.ingresar promedio";
        cout<<"salir";
    }
    switch(eleccion){
        case 1:as.ingresar_dato_est1();
        case 2:as.ingresar_datos_prof();
        case 3:as.ingresar_notas();
        case 4:as.promedios();
        case 5:
            cout<<"gracias por usar la aplicacion";
        break;
    }
}