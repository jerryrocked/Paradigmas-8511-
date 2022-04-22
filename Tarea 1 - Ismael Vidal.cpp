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
using std::cout; using std::fstream;
using std::endl; using std::string;


class Persona
{
	public:
	struct {
		string nom,rut,dir,telf;
		char Nombres[10];
		char sex;
		int edad;
		int k;
	}reg;	
	Persona(){ };
	~Persona(){ };
	void datosper();
	void mostrarper();
	void registrar();
};
void Persona::datosper(){ //Ingreso de datos

		cout << "Nombre : "; getline(cin,reg.nom);
    	cout << "Rut : "; getline(cin, reg.rut);
    	cout << "Direccion : " ; getline(cin, reg.dir);
    	cout << "Telefono : " ; getline(cin, reg.telf);
    	cout << "Sex : "; cin >> reg.sex;
    	cout << "Edad : "; cin >> reg.edad;

	}
	
	;
void Persona::mostrarper(){
		cout << "Nombre : "<<reg.nom<<endl;
    	cout << "Rut : "<<reg.rut<<endl;
    	cout << "Direccion : "<<reg.dir<<endl;
    	cout << "Telefono : " <<reg.telf<<endl;
    	cout << "Sex : "; cout<<reg.sex<<endl;
    	cout << "Edad : "; cout<<reg.edad<<endl;
	};
void Persona::registrar(){
	
}

class Profesor: public virtual Persona
{
	public:
	int cant;
	Profesor(){	};
	~Profesor(){ };
	void datosprof();
	void mostrarprof();
	void ingresarnotas();
	void entregarnotas();

};

void Profesor::datosprof() {
		int i;
		datosper();
	};
void Profesor::mostrarprof(){
		int i;
		mostrarper();

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
		cout<<"Ingresar Carrera que Estudia: ";
		cin>>carr;
	};
void Estudiante::mostrarest(){
		mostrarper();
		cout<<"\n Carrera: "<<carr;
	};
	
class Asignatura: public Profesor, public Estudiante
{
	public:
	string s[10];
	string a[10],c[10];
	char nom[40]= "Estudiante.txt";
	int cant;
	string mat[5]={"PROGRAMACION","BASE DE DATOS","ALGORITMO Y ESTRUCTURA DE DATOS","DESARROLLO WEB Y MOBIL","PARADIGMAS DE PROGRAMACION"};
	string cod[5]={"PR001","BD002","AE003","DM004","PP005"};
	void ingresardatose();
	void mostrare();
	void ingresardatosp();
	void mostrarp();
	void mostrar_promedios();
  void ingresar_notas();
};
void Asignatura::mostrarp(){
		mostrarprof();
		cout << "Cantidad Asignatura : "<<cant<<endl;
		cout<<"Asignaturas: \n";	
		for(int i=0;i<cant;i++){
			cout<<a[i]<<endl;
		}
};
void Asignatura::ingresardatosp(){ //Ingreso de datos en los respectivos archivos de cada asignatura
	ofstream archivo1;
	int opcion,opc;
	datosprof();
	cout<<"Escriba la Cantidad de Asignaturas: ";
	cin.ignore();
	cin>> cant;
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
			archivo1.open("Profesores PR001.txt",std::ios_base::app);
			archivo1<<reg.nom<<" ";
			archivo1<<reg.rut<<" ";
			archivo1<<reg.dir<<" ";
			archivo1<<reg.telf<<" ";
			archivo1<<reg.sex<<" ";
			archivo1<<reg.edad<<" ";
			// abrir archivo con nombre y codigo
			//guardar los datos del profesor 
			break;
			}
			case 2: {
			a[i]=mat[1];
			c[i]=cod[1];
			archivo1.open("Profesores BD002.txt",std::ios_base::app);
			archivo1<<reg.nom<<" ";
			archivo1<<reg.rut<<" ";
			archivo1<<reg.dir<<" ";
			archivo1<<reg.telf<<" ";
			archivo1<<reg.sex<<" ";
			archivo1<<reg.edad<<" ";
			break;
			}
			case 3: {
			a[i]=mat[2];
			c[i]=cod[2];
			archivo1.open("Profesores AE003.txt",std::ios_base::app);
			archivo1<<reg.nom<<" ";
			archivo1<<reg.rut<<" ";
			archivo1<<reg.dir<<" ";
			archivo1<<reg.telf<<" ";
			archivo1<<reg.sex<<" ";
			archivo1<<reg.edad<<" ";
			break;
			}
			case 4: {
			a[i]=mat[3];
			c[i]=cod[3];
			archivo1.open("Profesores DM004.txt",std::ios_base::app);
			archivo1<<reg.nom<<" ";
			archivo1<<reg.rut<<" ";
			archivo1<<reg.dir<<" ";
			archivo1<<reg.telf<<" ";
			archivo1<<reg.sex<<" ";
			archivo1<<reg.edad<<" ";
			break;
			}
			case 5: {
			a[i]=mat[4];
			c[i]=cod[4];
			archivo1.open("Profesores PP005.txt",std::ios_base::app);
			archivo1<<reg.nom<<" ";
			archivo1<<reg.rut<<" ";
			archivo1<<reg.dir<<" ";
			archivo1<<reg.telf<<" ";
			archivo1<<reg.sex<<" ";
			archivo1<<reg.edad<<" ";
			break;
			}
			}
		
		cout<<"\n 1. Seccion 1";
		cout<<"\n 2. Seccion 2";
		cout<<"\n Seleccione la seccion: ";			
		cin>>opc;
		switch (opc){
			case 1: {
				s[i]="1";
				archivo1<<"Seccion: 1 \n";
				break;
			}
			case 2: {
				s[i]="2";
				archivo1<<"Seccion: 2 \n";
				break;
			}
		}
		      archivo1.close();
 	}
};


void Asignatura::ingresardatose(){ //ingreso de datos en el respectivo archivo de cada asignatura
	ofstream archivo1;
	int opcion,opc;
	datosest();
	cout<<"Escriba la Cantidad de Asignaturas: ";
	cin.ignore();
	cin>> cant;
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
			archivo1.open("Estudiantes PR001.txt",std::ios_base::app);
			archivo1<<reg.nom<<" ";
			archivo1<<reg.rut<<" ";
      		archivo1<<reg.dir<<" ";
      		archivo1<<reg.telf<<" ";
      		archivo1<<reg.sex<<" ";
      		archivo1<<reg.edad<<" ";
      		
      cin.ignore();


			break;
		}
		case 2: {
			a[i]=mat[1];
			c[i]=cod[1];
			archivo1.open("Estudiantes BD002.txt",std::ios_base::app);
			archivo1<<reg.nom<<" ";
			archivo1<<reg.rut<<" ";
      archivo1<<reg.dir<<" ";
      archivo1<<reg.telf<<" ";
      archivo1<<reg.sex<<" ";
      archivo1<<reg.edad<<" ";
      cin.ignore();	
			break;
		} 
		case 3: {
			a[i]=mat[2];
			c[i]=cod[2];
			archivo1.open("Estudiantes AE003.txt",std::ios_base::app);
			archivo1<<reg.nom<<" ";
			archivo1<<reg.rut<<" ";
      archivo1<<reg.dir<<" ";
      archivo1<<reg.telf<<" ";
      archivo1<<reg.sex<<" ";
      archivo1<<reg.edad<<" ";
      cin.ignore();
			break;
		} 
		case 4: {
			a[i]=mat[3];
			c[i]=cod[3];
			archivo1.open("Estudiantes DM004.txt",std::ios_base::app);
			archivo1<<reg.nom<<" ";
			archivo1<<reg.rut<<" ";
      archivo1<<reg.dir<<" ";
      archivo1<<reg.telf<<" ";
      archivo1<<reg.sex<<" ";
      archivo1<<reg.edad<<" ";
      cin.ignore();
			break;
		} 
		case 5: {
			a[i]=mat[4];
			c[i]=cod[4];
			archivo1.open("Estudiantes PP005.txt",std::ios_base::app);
			archivo1<<reg.nom<<" ";
			archivo1<<reg.rut<<" ";
      archivo1<<reg.dir<<" ";
      archivo1<<reg.telf<<" ";
      archivo1<<reg.sex<<" ";
      archivo1<<reg.edad<<" ";
      cin.ignore();
			break;
		} 
		}
		cout<<"\n 1. Seccion 1";
		cout<<"\n 2. Seccion 2";
		cout<<"\n Seleccione la seccion: ";			
		cin>>opc;
		switch (opc){
			case 1: {
				s[i]="1";
				archivo1<<"Seccion: 1 \n";
				break;
			}
			case 2: {
				s[i]="2";
				archivo1<<"Seccion: 2 \n";
				break;
			}
		}
		archivo1.close();
	}
}; 


	
void Asignatura::mostrare(){
	FILE *archivo; // FILE se escribe en mayuscula
	mostrarest();
	
	cout<<"Asignaturas: \n";	
	for(int i=0;i<cant;i++){
		cout<<a[i]<<endl;
		cout<<c[i]<<endl;
		cout<<s[i]<<endl;
	}
	// En el segundo parametro se escribe la forma en que sera abierto "w"

	
	
	for(int i=0;i<cant;i++){
		cout<<(archivo,a[i]);
		cout<<(archivo,c[i]);
		cout<<(archivo,s[i]);
	}
	fclose(archivo);
};
void Asignatura::mostrar_promedios(){//abre el archivo segun el codigo que se ingrese y se muestra los promedios por pantalla
	int opcion,i,lon;
	string codigo;
	string linea;
		cout<<"Seleccione las Asignaturas: ";
		cout<<"\n 1. "<<mat[0];
		cout<<"\n 2. "<<mat[1];
		cout<<"\n 3. "<<mat[2];
		cout<<"\n 4. "<<mat[3];
		cout<<"\n 5. "<<mat[4];
		cout<<"\n Seleccione una Opcion: ";
		cin>>opcion;
		switch (opcion){
			case 1:{
				string archivo1="PR001 Promedios.txt";
				ifstream archivo(archivo1.c_str());
				if(archivo.good()){
				
				while (getline(archivo,linea)) {
        			cout<<linea<<endl;
        			lon = linea.length();
        		}}
				else{//en el caso de que no exista el archivo de promedios se mostrara por pantalla 
					cout<<"El profesor aun no entrega los promedios \n";
				}
        		break;
    }
			case 2:
				{
				
				string archivo1="BD002 Promedios.txt";
				ifstream archivo(archivo1.c_str());
				if(archivo.good()){
				while (getline(archivo,linea)) {
        			cout<<linea<<endl;
        			lon = linea.length();
				}}
				else {
					cout<<"El profesor aun no entrega los promedios \n";
				}
				break;
		}
			case 3:{
				
				string archivo1="AE003 Promedios.txt";
				ifstream archivo(archivo1.c_str());
				if(archivo.good()){
				while (getline(archivo,linea)) {
        			cout<<linea<<endl;
        			lon = linea.length();
        		}
        	}
        		else {
        			cout<<"El profesor aun no entrega los promedios \n";	
				}
        		break;
        	}
        	case 4:{
				
        		string archivo1="DM004 Promedios.txt";
				ifstream archivo(archivo1.c_str());
				if(archivo.good()){
				if(archivo.good()){
				while (getline(archivo,linea)) {
        			cout<<linea<<endl;
        			lon = linea.length();
        		}
        	}	
        		else { 
        			cout<<"El profesor aun no entrega los promedios \n";	
				}
				break;
		}}
        	case 5:{
        		
        		string archivo1="PP005 Promedios.txt";
				ifstream archivo(archivo1.c_str());
				if(archivo.good()){
				while (getline(archivo,linea)) {
        			cout<<linea<<endl;
        			lon = linea.length();
        	}}
        		else{
        			cout<<"El profesor aun no entrega los promedios \n";	
				}
				break;			
			}}
				
}
void Asignatura::ingresar_notas(){//ingreso de datos dependiendo de la asigantura
  
	string nom,rut,direcc;
	string nomb;
	ofstream archivo1;
	ofstream archivo2;
	string codigo,linea;
	int z,i,lon,j=0;
	int cantidad;
  char b,l;

  
	double nota1,nota2,nota3,promedio;
	
	cout<<"Ingresar codigo del ramo: \n";
	getline(cin,codigo);
	while(codigo!= "PR001" && codigo!="BD002" && codigo!= "AE003" && codigo!= "DM004" && codigo != "PP005"){ // en el caso de que se equivoque en el ingreso del codigo se solitara nuevamente
	cout<<"Este codigo no existe, ingrese nuevamente:  ";
	getline(cin,codigo);
	}
		
	if(codigo == "PR001"){
	
		archivo1.open("PR001 Notas.txt",std::ios_base::app); // se abren todos los archivos necesarios para tener los nombres de los alumnos de cada asigantura e ingresar sus notas
		archivo2.open("PR001 Promedios.txt",std::ios_base::app);
	    string archivo3="Estudiantes PR001.txt";
    	ifstream archivo4(archivo3.c_str());	
        while (getline(archivo4,linea)) {  
        lon = linea.length();
        for (i=0;i<lon;i++){
            l=linea[i];
            b=' ';
            if (l!=b){
                if (j==0)
                    nomb=nomb+linea[i];
                  

    }
          else
              j++;
	}
         
    cout<<"Ingrese la primera nota de "<<nomb<<" :";
		cin>>nota1;
		while(nota1<1.0 || nota1>7.0){
			cout<<"Ingrese una nota valida, Ingrese nuevamente:  ";
			cin>>nota1;
		}
		cout<<"Ingrese la segunda nota de "<<nomb<<" :";
		cin>>nota2;
		while(nota2<1.0 || nota2>7.0){
			cout<<"Ingrese una nota valida, Ingrese nuevamente:  ";
			cin>>nota2;
		}
		cout<<"Ingrese la tercera nota de "<<nomb<<" :";
		cin>>nota3;
		while(nota3<1.0 || nota3>7.0){
			cout<<"Ingrese una nota valida, Ingrese nuevamente:  ";
			cin>>nota3;
		}

		archivo1<<nomb;
		archivo1<<" "<<"Notas: "<<nota1<<",";
		archivo1<<nota2<<",";
		archivo1<<nota3<<"\n";
		promedio = (nota1+nota2+nota3)/3;
		archivo2<<nomb<<"  ";
		archivo2<<"Su Promedio es: "<<promedio<<"  ";// una vez ingresadas las notas se calcula su promedio y se ingresa junto a su nombre en un archivo
		if(promedio>= 4.0) {
			archivo2<<"Aprobado \n";
			
		}   
		else
		{
			archivo2<<"Reprobado \n";
		}
	  nomb = " ";
    j=0;
  }
    
  }
	if(codigo == "BD002"){
	
		archivo1.open("BD002 Notas.txt",std::ios_base::app);
		archivo2.open("BD002 Promedios.txt",std::ios_base::app);
	    string archivo3="Estudiantes BD002.txt";
    	ifstream archivo4(archivo3.c_str());	
        while (getline(archivo4,linea)) {  
        lon = linea.length();
        for (i=0;i<lon;i++){
            l=linea[i];
            b=' ';
            if (l!=b){
                if (j==0)
                    nomb=nomb+linea[i];
                  

    }
          else
              j++;
	}
         
    cout<<"Ingrese la primera nota de "<<nomb<<" :";
		cin>>nota1;
		while(nota1<1.0 || nota1>7.0){
			cout<<"Ingrese una nota valida, Ingrese nuevamente:  ";
			cin>>nota1;
		}
		cout<<"Ingrese la segunda nota de "<<nomb<<" :";
		cin>>nota2;
		while(nota2<1.0 || nota2>7.0){
			cout<<"Ingrese una nota valida, Ingrese nuevamente:  ";
			cin>>nota2;
		}
		cout<<"Ingrese la tercera nota de "<<nomb<<" :";
		cin>>nota3;
		while(nota3<1.0 || nota3>7.0){
			cout<<"Ingrese una nota valida, Ingrese nuevamente:  ";
			cin>>nota3;
		}

		archivo1<<nomb;
		archivo1<<" "<<"Notas: "<<nota1<<",";
		archivo1<<nota2<<",";
		archivo1<<nota3<<"\n";
		promedio = (nota1+nota2+nota3)/3;
		archivo2<<nomb<<"  ";
		archivo2<<"Su Promedio es: "<<promedio<<"  ";
		if(promedio>= 4.0) {
			archivo2<<"Aprobado \n";
			
		}   
		else
		{
			archivo2<<"Reprobado \n";
		}
	  nomb = " ";
    j=0;
  }
    
  }
	if(codigo == "AE003"){
	
		archivo1.open("AE003 Notas.txt",std::ios_base::app);
		archivo2.open("AE003 Promedios.txt",std::ios_base::app);
	    string archivo3="Estudiantes AE003.txt";
    	ifstream archivo4(archivo3.c_str());	
        while (getline(archivo4,linea)) {  
        lon = linea.length();
        for (i=0;i<lon;i++){
            l=linea[i];
            b=' ';
            if (l!=b){
                if (j==0)
                    nomb=nomb+linea[i];
                  

    }
          else
              j++;
	}
         
    cout<<"Ingrese la primera nota de "<<nomb<<" :";
		cin>>nota1;
		while(nota1<1.0 || nota1>7.0){
			cout<<"Ingrese una nota valida, Ingrese nuevamente:  ";
			cin>>nota1;
		}
		cout<<"Ingrese la segunda nota de "<<nomb<<" :";
		cin>>nota2;
		while(nota2<1.0 || nota2>7.0){
			cout<<"Ingrese una nota valida, Ingrese nuevamente:  ";
			cin>>nota2;
		}
		cout<<"Ingrese la tercera nota de "<<nomb<<" :";
		cin>>nota3;
		while(nota3<1.0 || nota3>7.0){
			cout<<"Ingrese una nota valida, Ingrese nuevamente:  ";
			cin>>nota3;
		}

		archivo1<<nomb;
		archivo1<<" "<<"Notas: "<<nota1<<",";
		archivo1<<nota2<<",";
		archivo1<<nota3<<"\n";
		promedio = (nota1+nota2+nota3)/3;
		archivo2<<nomb<<"  ";
		archivo2<<"Su Promedio es: "<<promedio<<"  ";
		if(promedio>= 4.0) {
			archivo2<<"Aprobado \n";
			
		}   
		else
		{
			archivo2<<"Reprobado \n";
		}
	  nomb = " ";
    j=0;
  }
    
  }
	
	if(codigo == "DM004"){
	
		archivo1.open("DM004 Notas.txt",std::ios_base::app);
		archivo2.open("DM004 Promedios.txt",std::ios_base::app);
	    string archivo3="Estudiantes DM004.txt";
    	ifstream archivo4(archivo3.c_str());	
        while (getline(archivo4,linea)) {  
        lon = linea.length();
        for (i=0;i<lon;i++){
            l=linea[i];
            b=' ';
            if (l!=b){
                if (j==0)
                    nomb=nomb+linea[i];
                  

    }
          else
              j++;
	}
         
    cout<<"Ingrese la primera nota de "<<nomb<<" :";
		cin>>nota1;
		while(nota1<1.0 || nota1>7.0){
			cout<<"Ingrese una nota valida, Ingrese nuevamente:  ";
			cin>>nota1;
		}
		cout<<"Ingrese la segunda nota de "<<nomb<<" :";
		cin>>nota2;
		while(nota2<1.0 || nota2>7.0){
			cout<<"Ingrese una nota valida, Ingrese nuevamente:  ";
			cin>>nota2;
		}
		cout<<"Ingrese la tercera nota de "<<nomb<<" :";
		cin>>nota3;
		while(nota3<1.0 || nota3>7.0){
			cout<<"Ingrese una nota valida, Ingrese nuevamente:  ";
			cin>>nota3;
		}

		archivo1<<nomb;
		archivo1<<" "<<"Notas: "<<nota1<<",";
		archivo1<<nota2<<",";
		archivo1<<nota3<<"\n";
		promedio = (nota1+nota2+nota3)/3;
		archivo2<<nomb<<"  ";
		archivo2<<"Su Promedio es: "<<promedio<<"  ";
		if(promedio>= 4.0) {
			archivo2<<"Aprobado \n";
			
		}   
		else
		{
			archivo2<<"Reprobado \n";
		}
	  nomb = " ";
    j=0;
  }
    
  }
	if(codigo == "PP005"){
	
		archivo1.open("PP005 Notas.txt",std::ios_base::app);
		archivo2.open("PP005 Promedios.txt",std::ios_base::app);
	    string archivo3="Estudiantes PP005.txt";
    	ifstream archivo4(archivo3.c_str());	
        while (getline(archivo4,linea)) {  
        lon = linea.length();
        for (i=0;i<lon;i++){
            l=linea[i];
            b=' ';
            if (l!=b){
                if (j==0)
                    nomb=nomb+linea[i];
                  

    }
          else
              j++;
	}
         
    cout<<"Ingrese la primera nota de "<<nomb<<" :";
		cin>>nota1;
		while(nota1<1.0 || nota1>7.0){
			cout<<"Ingrese una nota valida, Ingrese nuevamente:  ";
			cin>>nota1;
		}
		cout<<"Ingrese la segunda nota de "<<nomb<<" :";
		cin>>nota2;
		while(nota2<1.0 || nota2>7.0){
			cout<<"Ingrese una nota valida, Ingrese nuevamente:  ";
			cin>>nota2;
		}
		cout<<"Ingrese la tercera nota de "<<nomb<<" :";
		cin>>nota3;
		while(nota3<1.0 || nota3>7.0){
			cout<<"Ingrese una nota valida, Ingrese nuevamente:  ";
			cin>>nota3;
		}

		archivo1<<nomb;
		archivo1<<" "<<"Notas: "<<nota1<<",";
		archivo1<<nota2<<",";
		archivo1<<nota3<<"\n";
		promedio = (nota1+nota2+nota3)/3;
		archivo2<<nomb<<"  ";
		archivo2<<"Su Promedio es: "<<promedio<<"  ";
		if(promedio>= 4.0) {
			archivo2<<"Aprobado \n";// en el caso de que su promedio se igual o mayor a 4 el estudiante abra aprobado
			
		}   
		else
		{
			archivo2<<"Reprobado \n"; // en el caso de que su promedio sea menor a 4 el estudiante abra reprobado
		}
	  nomb = " ";
    j=0;
  }
    
  }
		if(archivo1.fail()){
			cout<<"No se pudo abrir el archivo";
			exit(1);
		}		
		archivo1.close();
		archivo2.close();
	//cin>>u;	
	
	//"PR001","BD002","AE003","DM004","PP005"
	
	
}


int main(int argc, char** argv) {
	Asignatura as;
	int opc;
	while (opc !=5){
		cout<<"Sistema de Notas \n";
		cout<<"1. Ingresar Profesor: \n";
		cout<<"2. Ingresar Estudiante: \n";
		cout<<"3. Ingresar Notas\n";
		cout<<"4. Mostrar Promedios \n";
		cout<<"5. Salir \n";
		cout<<"Seleccionar Opcion: ";
		cin>>opc;
		cin.ignore();
		switch (opc){
			case 1:
				as.ingresardatosp();	// ingreso y registro de datos del profesor por cada asignatura
				break;
			case 2:
				as.ingresardatose();	// ingreso y registro de datos del estudiante por cada asignatura			
				break;
			case 3:
				as.ingresar_notas();	//ingreso de notas de todos los alumno de cada asignatura
				break;
			case 4:
				as.mostrar_promedios(); //visualizacion por pantalla de los promedios de los alunnos y el estado de aprobacion o reprobacion
				break;
			case 5:
				cout<<"Cerrado con Exito";
				break;
	}
}
	return 0;
}

