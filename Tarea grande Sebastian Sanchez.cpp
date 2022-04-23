#include <iostream>
#include <string>
using namespace std;

class asignatura{
  public:
  string asig[5]={"Progra","B_datos","E_datos","Desarrollo web y movil","paradigmas de programacion"};
  string code[5] = {"PR001","PD002","AE003","DM004","PP005"};
  asignatura();
  ~asignatura();
  void mostrar_asig();

};

void asignatura::mostrar_asig(){
  int i;
  for (i=0;i<asig.length();i++){
    cout<<asig[i]<<endl;
    cout<<" "<<code[i]<<endl;
    
  }
  
};

class persona{
  public:
  string nombre,rut,dire,telf;
  int edad;
  persona();
  ~persona();
  void ingresar_datos();
  void mostrar_datos();

};

void persona::ingresar_datos(){
	cout<<"ingrese su nombre"<<endl;
	getline(cin,nombre);
	cout<<"ingrese su rut"<<endl;
	getline(cin,rut);
	cout<<"ingrese su direccion"<<endl;
	getline(cin,dire);
	cout<<"ingrese su rut"<<endl;
	getline(cin,telf);
	cout<<"ingrese su rut"<<endl;
	cin>>edad;
}:

void persona::mostrar_datos(){
	cout<<"nombre:"<<nombre<<endl;
	cout<<"rut:"<<rut<<endl;
	cout<<"edad:"<<edad<<endl;
	cout<<"direccion:"<<dire<<endl;	
	cout<<"telefono:"<<telf<<endl;
	
};

class estudiante:public persona,public asignatura{   //aqui se hace la herencia
  public:
  string mat[5], carrera;
  int cant_mat;
  estudiante();
  ~estudiante();
  void ingresar_est();
  void mostrar_est();

};

void estudiante::ingresar_est(){
  int i;
  ingresar_datos();
  cout<<"carrera que estudia:"<<endl;
  getline(cin,carrera);
  cout<<"cantidad de asignaturas"<<endl;
  cin>>cant_mat;
  for (i=0; i<cant_mat;i++){
    cout<<"escriba la materia"<<i<<": ";
    getline(cin,mat[i]);
    
  }
};
void estudiante::mostrar_est(){
	
	cout<<"carrera:"<<carrera<<endl;
	cout<<"sus materias son"<<mat<<endl;	
	
};

class profesor:public persona,public asignatura{
	public:
	string nombre_alum[];
	int rut_alum,n1,n2,n3,prom;
	
	
	estudiante();
	~estudiante();
	void recibir_notas();
	void ingresar_notas();
	void mostrar_alumno();
	
};

void profesor::ingresar_notas(){
	cout<<"nombre del alumno"<<endl;
	getline(cin,nombre_alum);
	cout<<"ingrese el rut"<<endl;
	getline(cin,rut_alum);
	cout<<"ingrese la primera nota"<<endl;
	cin>>n1;
	cout<<"ingrese la segunda nota"<<endl;
	cin>>n2;
	cout<<"ingrese la tercera nota"<<endl;
	cin>>n3;
	prom= (n1+n2+n3)/3;
};

void profesor::mostrar_alumno(){
	cout<<"alumno:"<<nombre_alum<<endl;
	cout<<"rut:"<<rut<<endl;
	cout<<"promedio de notas:"<<prom<<endl;
	
};

int main(){
  asignatura as;
  as.mostrar_asig();
  
}

//profe la verdad no pude terminar la tarea porque desde el inicio me salieron errores, no supe resolverla.
