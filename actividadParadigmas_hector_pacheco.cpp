#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <stdio.h>
using namespace std;
/*
NOMBRE:HECTOR PACHECO
RUT:20401541-4
*/

class Persona
{
	public:
	struct {
		string nom,rut;
		int edad;
	}reg;	
	Persona(){ };
	~Persona(){ };
	void datosper();
	void mostrarper();
};
void Persona::datosper(){
	cout << "Nombre : "; cin >> reg.nom;
  cout << "Rut : "; cin >>  reg.rut;
	cout << "Edad : "; cin>> reg.edad;
	};
void Persona::mostrarper(){
	cout << "Nombre : "<<reg.nom<<endl;
    cout << "Rut : "<<reg.rut<<endl;
    cout << "Edad : "<<reg.edad<<endl;
	};

class Profesor: public virtual Persona
{
	public:
	string cat;
	int cant;
	Profesor(){	};
	~Profesor(){ };
	void datosprof();
	void mostrarprof();
	void entregarnotas();
};

void Profesor::datosprof() {
		int i;
		datosper();
		cin.ignore();
		cout<<"Escriba la Categoria: ";getline(cin, cat);	
	};
void Profesor::mostrarprof(){
		int i;
		mostrarper();
		cout << "Categoria : "<<cat<<endl;
	};

class Estudiante: public virtual Persona
{
	public:
	string carr;
	int can;
	Estudiante(){ };
	~Estudiante(){ };
	void datosest();
	void mostrarest();
};
void Estudiante::datosest() {
		int i;
		datosper();
		cout<<"Ingresar Carrera que Estudia:";
		cin>>carr;
	};
void Estudiante::mostrarest(){
		mostrarper();
		cout<<" Carrera: \n"<<carr;
	};
	
class Asignatura: public Profesor, public Estudiante
{
	public:
	int n;
	float notas[10],promedio;
	string s[10];
	string a[10],c[10];
	string mat[5]={"PROGRAMACION","BASE DE DATOS","ALGORITMO Y ESTRUCTURA DE DATOS","DESARROLLO WEB Y MOBIL","PARADIGMAS DE PROGRAMACION"};
	string cod[5]={"PR001","BD002","AE003","DM004","PP005"};
	Asignatura(){ };
	~Asignatura(){ };
	void ingresardatose();
	void crearArchivoE();
	void ingresardatosp();
	void mostrarp();
  void ingresar_notasE();
  void mostrar_notasE();
  void crearArchivoP();

};

void Asignatura::ingresar_notasE(){
	for(int i=0;i<5;i++){        
    	cout<<"Ingrese nota:";
    	cin>>notas[i];
    }
 
};
  /*Guarda la cantidad y el nombre de asignaturas(archivos)
    para darselas a la variable de alumnos.*/

void Asignatura::mostrar_notasE(){
	cout<<"\n";
  	cout<<"nota1:"<<notas[0]<<endl;
  	cout<<"nota2:"<<notas[1]<<endl;
  	cout<<"nota3:"<<notas[2]<<endl;
  	cout<<"nota4:"<<notas[3]<<endl;
  	cout<<"nota5:"<<notas[4]<<endl;

};
	

void Asignatura::mostrarp(){
		mostrarprof();
		cout << "Cantidad Asignatura : "<<cant<<endl;
		cout<<"Asignaturas: \n";	
		for(int i=0;i<cant;i++){
			cout<<a[i]<<endl;
		}
};
void Asignatura::ingresardatosp(){
	int opcion,opc;
	datosprof();
	cout<<"Escriba la Cantidad de Asignaturas: ";cin>> cant;
	for (int i=0;i<cant;i++){
		cout<<"Seleccione las Asignaturas: ";
		cout<<"\n 1. "<<mat[0];
		cout<<"\n 2. "<<mat[1];
		cout<<"\n 3. "<<mat[2];
		cout<<"\n 4. "<<mat[3];
		cout<<"\n 5. "<<mat[4];
		cout<<"\n Seleccione una Opcion: ";
		cin>>opcion;
		switch (opcion){
			case 1: {
			a[i]=mat[0];
			c[i]=cod[0];
			break;
			}
			case 2: {
			a[i]=mat[1];
			c[i]=cod[1];
			break;
			}
			case 3: {
			a[i]=mat[2];
			c[i]=cod[2];
			break;
			}
			case 4: {
			a[i]=mat[3];
			c[i]=cod[3];
			break;
			}
			case 5: {
			a[i]=mat[4];
			c[i]=cod[4];
			break;
			}
			}
		
		cout<<"\n 1. Seccion 1";
		cout<<"\n 2. Seccion 2";
		cout<<"\n Seleccione la Seccion: ";			
		cin>>opc;
		switch (opc){
			case 1: {
				s[i]="1";
				break;
			}
			case 2: {
				s[i]="2";
				break;
			}
		}
 	}
};


void Asignatura::ingresardatose(){
	int opcion,opc;
	datosest();
	cout<<"Escriba la Cantidad de Asignaturas: ";cin>> cant;
	for (int i=0;i<cant;i++){
		cout<<"Seleccione las Asignaturas: ";
		cout<<"\n 1. "<<mat[0];
		cout<<"\n 2. "<<mat[1];
		cout<<"\n 3. "<<mat[2];
		cout<<"\n 4. "<<mat[3];
		cout<<"\n 5. "<<mat[4];
		cout<<"\n Seleccione una Opcion: ";
		cin>>opcion;
		switch (opcion){
		case 1: {
			a[i]=mat[0];
			c[i]=cod[0];
			break;
		}
		case 2: {
			a[i]=mat[1];
			c[i]=cod[1];
			break;
		} 
		case 3: {
			a[i]=mat[2];
			c[i]=cod[2];
			break;
		} 
		case 4: {
			a[i]=mat[3];
			c[i]=cod[3];
			break;
		} 
		case 5: {
			a[i]=mat[4];
			c[i]=cod[4];
			break;
		} 
		}
		cout<<"\n 1. Seccion 1";
		cout<<"\n 2. Seccion 2";
		cout<<"\n Seleccione la Seccion: ";			
		cin>>opc;
		switch (opc){
			case 1: {
				s[i]="1";
				break;
			}
			case 2: {
				s[i]="2";
				break;
			}
		}
	}
}; 

void Asignatura::crearArchivoE(){
	mostrarest();
  datosper();
  int i;
  ofstream archivo;
  promedio = notas[0]+notas[1]+notas[2]+notas[3]+notas[4] ;
	promedio = promedio/5;
  archivo.open("DatosAlumno.txt",ios::out);
  archivo<<"NOMBRE ESTUDIANTE:"<<reg.nom<<endl;
  archivo<<"RUT ESTUDIANTE:"<<reg.rut<<endl;
  archivo<<"EDAD ESTUDIANTE:"<<reg.edad<<endl;
	archivo<<"Asignatura1:"<<a[0]<<" "<<"CODIGO1:"<<c[0]<<endl;
  archivo<<"Asignatura2:"<<a[1]<<" "<<"CODIGO2:"<<c[1]<<endl;
  archivo<<"Asignatura3:"<<a[2]<<" "<<"CODIGO3:"<<c[2]<<endl;
  archivo<<"Asignatura4:"<<a[3]<<" "<<"CODIGO4:"<<c[3]<<endl;
  archivo<<"Asignatura5:"<<a[4]<<" "<<"CODIGO5:"<<c[4]<<endl;
	archivo<<"SECCION:"<<s[0]<<" "<<s[1]<<endl;
  archivo<<"NOTA1:"<<notas[0]<<" "<<"NOTA2:"<<notas[1]<<" "<<"NOTA3:"<<notas[2]<<" "<<"NOTA4:"<<notas[3]<<" "<<"NOTA5:"<<notas[4]<<endl;
  archivo<<"EL PROMEDIO ES DE:"<<promedio<<endl;
  

};

void Asignatura::crearArchivoP(){
	mostrarest();
  ofstream archivo;
  
  archivo.open("DatosProfe.txt",ios::out);
  archivo<<"NOMBRE profe:"<<reg.nom<<endl;
  archivo<<"RUT profe:"<<reg.rut<<endl;
  archivo<<"EDAD profe:"<<reg.edad<<endl;
	archivo<<"Asignatura1:"<<a[0]<<" "<<"CODIGO1:"<<c[0]<<endl;
  archivo<<"Asignatura2:"<<a[1]<<" "<<"CODIGO2:"<<c[1]<<endl;
  archivo<<"Asignatura3:"<<a[2]<<" "<<"CODIGO3:"<<c[2]<<endl;
  archivo<<"Asignatura4:"<<a[3]<<" "<<"CODIGO4:"<<c[3]<<endl;
  archivo<<"Asignatura5:"<<a[4]<<" "<<"CODIGO5:"<<c[4]<<endl;
	archivo<<"SECCION:"<<s[0]<<" "<<s[1]<<endl;
};

int main() {
	Asignatura asig;
	int opc;
  int opc2;
  int opc3;
    do {
        cout<<"MENU:";
        cout<<"\n1- PROFESOR.";
        cout<<"\n2- ESTUDIANTE.";
        cout<<"\n3- SALIR";
        cout<<"\n Opcion : ";
        cin>>opc;
        switch(opc) {

          case 1:            
            cout<<"\n1- Ingresar datos profesor.";
            cout<<"\n2- Crear archivo con datos de profesor.";
            cout<<"\n3- Crear archivo con datos de alumno.";
            cout<<"\n Opcion : ";
            cin>>opc2;
            switch(opc2) { 
                 case 1:
                  asig.ingresardatosp();
                  break;

                 case 2:
                  asig.crearArchivoP();
                  break;

                 case 3:
                  asig.crearArchivoE();
                  asig.ingresar_notasE();
                  
                  break;
               }
               break;

          

          case 2:
            cout<<"\n1- Ingresar datos Alumno.";
			      cout<<"\n2- crear archivo alumno.";
            cout<<"\n Opcion : ";
            cin>>opc3;
            switch(opc3) { 
                 case 1:
                  asig.ingresardatose();	
                  asig.ingresar_notasE();
                  break;

                 case 2:
                  asig.crearArchivoE();
                  break; 
               }
               break;
        }
    } while(opc!=0);
  system("PAUSE" );
  return 0;

}