#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

//-------------------clase persona---------------------
class Persona {
	public:
	struct {
		string nomb,rut,dir,tel;
		char sex;
		int edad;
	}reg;	
	Persona(){ };
	~Persona(){ };
	void datosper();
	void mostrarper();
};

void Persona::datosper(){
    ofstream documento;

    documento.open("documento.txt",ios::out);

    if(documento.fail()){
      cout<<"no se pudo abrir el documento";
      exit(1);
    }
		cout << "Nombre : "; 
    
    getline(cin, reg.nomb); 
    
		cout << "Rut : "; 
    getline(cin, reg.rut);
    cout << "Edad : "; 
    cin >> reg.edad;
	};

void Persona::mostrarper(){
		cout << "\n Nombre : "<<reg.nomb<<endl;
    cout << "\n Rut : "<<reg.rut<<endl;
    cout << "\n Edad : "; cout<<reg.edad<<endl;
    
	};


//------------------clase profesor-------------------------

class Profesor: public virtual Persona{
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
		cout<<"Escriba la Categoria: "; getline (cin, cat);
        

};

void Profesor::mostrarprof(){
		int i;
		mostrarper();
		cout << "Categoria : "<<cat<<endl;
	};



//---------------------------clase estudiante------------------
class Estudiante: public virtual Persona {
	public:
	string carr;
	int can;
  float nota1, nota2, nota3, nota4, promedio;
	Estudiante(){ };
	~Estudiante(){ };
	void datos_estudiante();
	void mostrar_estudiante();
};

void Estudiante::datos_estudiante() {
    ofstream documento;

    documento.open("documento.txt",ios::out);//abriendo el documento

    if(documento.fail()){
      cout<<"no se pudo abrir el documento";
      exit(1);
    }
		int i;
		datosper();
		cout<<"Ingresar Carrera que Estudia: ";
		cin>>carr;
    documento <<carr;
  
    cout<<"ingrese nota 1: ";
    cin>>nota1;
    documento << " "<<nota1;
  
    cout<<"ingrese nota 2: ";
    cin>>nota2;
    documento <<" "<<nota2;
  
    cout<<"ingrese nota 3: ";
    cin>>nota3;
    documento <<" "<<nota3;
  
    cout<<"ingrese nota 4: ";
    cin>>nota4;
    documento <<" "<< nota4;

    promedio= (nota1+nota2+nota3+nota4)/4;
    documento<<" "<<promedio;
  
	};

void Estudiante::mostrar_estudiante(){
		string arreglo_alumnos;
		mostrarper();
		cout<<"\n Carrera: "<<carr;
    cout<<"\n promedio de notas: "<<promedio;

    char arreglo_alumno;
    cout<<arreglo_alumno<<endl;
	};


//------------------main--------------------

int main(int argc, char** argv) {
  ifstream archivo;
  archivo.open("archivo.txt",ios::in);
	string texto;
  Estudiante as;
  Profesor es;
  while(1==1){
	int opc;
	cout<<"Sistema de Notas \n";
	cout<<"1. Profesor: \n";
	cout<<"2. Estudiante: \n";
	cout<<"3. Mostrar Estudiantes \n";
  cout<<"4. Salir \n";
	cout<<"Seleccionar Opcion: ";
	cin>>opc;
	cin.ignore();
	switch (opc){
		case 1:
			
			break;
		case 2:
      as.datos_estudiante();
			as.mostrar_estudiante();
			break;
    case 3:

      while(!archivo.eof()){
        getline(archivo,texto);
        cout<<texto<<endl;
      }

    break;
		case 4:
      exit(EXIT_SUCCESS);
      break;
	}}
	return 0;
}