#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string line;
string text;
string subLine;

//Aqui definiremos las clases
class Person{
	public:
		string name, rut;
};
class Professor: public Person{
	public:
		string section;
};

class Student: public Person{
	public:
		string sections[60];
		string averages[60]; 
    vector<string> notas;
    Student(string _name, string _rut, vector<string> _notas); //Contructor
    ~Student(){}; //Destructor
};

Student::Student(string _name, string _rut, vector<string> _notas){
  this->name = _name;
  this->rut = _rut;
  this->notas = _notas;
}

class Subject{
	string name;
	string code;
};

struct Secciones{
  vector<Student> Alumnos_PR001;
  vector<Student> Alumnos_BD002;
  vector<Student> Alumnos_AE003;
  vector<Student> Alumnos_DM004;
  vector<Student> Alumnos_PP005;
};

//Asignaturas
string subj[5]= {"Programacion", "Base de Datos", "Algoritmo y E.", "Desarrollo Web", "Paradigmas de P."};
string cod[5]= {"PR001", "BD002", "AE003", "DM004", "PP005"};

//Funcion para elegir modo en que entra el usuario 

void menuDocente(Secciones Sec);
void menuAlumno(Secciones Sec);
void menu(Secciones Sec);
bool buscarSeccion(string sec);
vector<Student> CrearAlumnos(string name);
bool archivo_existe(string nombre);
float ObtenerPromedio(vector<Student> S, int pos);
void OrdenarNotas(vector<Student> verE);

int main(){
  Secciones Sec;
	menu(Sec);
	return 0;
}

void menu(Secciones Sec){
  string option;
  cout<<"--------------------------------"<<endl;
  cout<<"Seleccione una opcion: "<<endl;
  cout<<"- Alumno(1)"<<endl;
  cout<<"- Docente(2)"<<endl;
  cout<<"--------------------------------"<<endl;
  cin>>option;
  if (option != "1" && option != "2"){
    return menu(Sec);
  }else{
    if(option == "1"){
      menuAlumno(Sec);
    }
    if(option == "2"){
      menuDocente(Sec);
    }
  }
}

void menuDocente(Secciones Sec){
  string rutDocente;
  string sectionDocente;
  string N_Texto;
  cout<<"--------------------------------"<<endl;
  cout<<"Ingrese su rut: "<<endl;
  cout<<"--------------------------------"<<endl;  
  cin>>rutDocente; 
  cout<<"--------------------------------"<<endl; 
  cout<<"Ingrese seccion: "<<endl;
  cout<<"--------------------------------"<<endl; 
  cin>>sectionDocente;
  bool estado = buscarSeccion(sectionDocente);
  if(estado == false){
    return menuDocente(Sec);
  }
  string opcionA;
  cout<<"--------------------------------"<<endl; 
  cout<<"Ingresar archivo de texto sobre notas(1)"<<endl; 
  cout<<"Ver notas ordenadas(2)"<<endl;
  cin>>opcionA;
  if(opcionA == "1"){
    cout<<"--------------------------------"<<endl;
    cout<<"Ingrese el archivo de texto (con .txt): "<<endl;
    cout<<"--------------------------------"<<endl;
    cin>>N_Texto;
  
    bool existe = archivo_existe(N_Texto);
    if(existe == false){
      return menuDocente(Sec);
    }
    vector<Student> alumnos = CrearAlumnos(N_Texto);
    cout<<"Todos los alumnos han sido ingresados de manera correcta"<< endl;
    if(sectionDocente == "PR001"){
      Sec.Alumnos_PR001 = alumnos;
    }
    if(sectionDocente == "BD002"){
      Sec.Alumnos_BD002 = alumnos;
    }
    if(sectionDocente == "AE003"){
      Sec.Alumnos_AE003 = alumnos;
    }
    if(sectionDocente == "DM004"){
      Sec.Alumnos_DM004 = alumnos;
    }
    if(sectionDocente == "PP005"){
      Sec.Alumnos_PP005 = alumnos;
    } 
  }else{
    if(opcionA == "2"){
      if(sectionDocente == "PR001"){
        OrdenarNotas(Sec.Alumnos_PR001);
      }
      if(sectionDocente == "BD002"){
        OrdenarNotas(Sec.Alumnos_BD002);
      }
      if(sectionDocente == "AE003"){
        OrdenarNotas(Sec.Alumnos_AE003);
      }
      if(sectionDocente == "DM004"){
        OrdenarNotas(Sec.Alumnos_DM004);
      }
      if(sectionDocente == "PP005"){
        OrdenarNotas(Sec.Alumnos_PP005);
      } 
    }
  }
  //Con el codigo se asume que existen varios tipos de archivo los cuales estan designados para distintos ramos, cabe decir ( un archivo de texto para PP005 o un archivo para AE003)

  cout<<"Desea volver al inicio (Y/N)"<< endl;
  char res;
  cin>>res;
  if(res == 'Y' || res == 'y'){
    menu(Sec);
  }else{
    menuDocente(Sec);
  }
}

void menuAlumno(Secciones Sec){
  string rutAlumno;
  cout<<"--------------------------------"<<endl;
  cout<<"Ingrese el rut del alumno"<<endl;
  cin>>rutAlumno;
  cout<<"--------------------------------"<<endl;
  bool estado = false;
  int posAlP;
  int posAlB;
  int posAlA;
  int posAlD;
  int posAlPAR;
  for(int i = 0; i < 5; i++){
    if(Sec.Alumnos_PR001.empty() == false){
      if(Sec.Alumnos_PR001[i].rut == rutAlumno){
        estado = true;
        posAlP = i;
      }
    }
    if(Sec.Alumnos_BD002.empty() == false){
      if(Sec.Alumnos_BD002[i].rut == rutAlumno){
        estado = true;
        posAlB = i;
      }
    }
    if(Sec.Alumnos_AE003.empty() == false){
      if(Sec.Alumnos_AE003[i].rut == rutAlumno){
        estado = true;
        posAlA = i;
      }
    }
    if(Sec.Alumnos_DM004.empty() == false){
      if(Sec.Alumnos_DM004[i].rut == rutAlumno){
        estado = true;
        posAlD = i;
      }
    }
    if(Sec.Alumnos_PP005.empty() == false){
      if(Sec.Alumnos_PP005[i].rut == rutAlumno){
        estado = true;
        posAlPAR = i;
      }
    }
  }
    
  if(estado == false){
    cout<<"El profesor no ha ingresado sus notas."<<endl;
    menuAlumno(Sec);
  }
  cout<<"--------------------------------"<<endl;
  cout<<"- Mostrar Notas(1)"<<endl;
  cout<<"- Volver al menu(2)"<<endl;
  string opcion;
  cin>>opcion;
  cout<<"--------------------------------"<<endl;
  if(opcion == "1"){
    for(int i = 0; i <= 4; i++){
      if(Sec.Alumnos_PR001.empty() == false){
        if(i == 0){
          float Promedio = ObtenerPromedio(Sec.Alumnos_PR001, posAlP) ;
          cout << "Programacion " << Promedio;
          if(Promedio < 4){
            cout << " Reprobado" <<endl;
          }else{
            cout << " Aprobado" <<endl;
          }
        }
      }
      if(Sec.Alumnos_BD002.empty() == false){
        if(i == 1){
          float Promedio = ObtenerPromedio(Sec.Alumnos_BD002, posAlB);
          cout << "Base de datos " << Promedio;
          if(Promedio < 4){
            cout << " Reprobado" <<endl;
          }else{
            cout << " Aprobado" <<endl;
          }
        }
      }
      if(Sec.Alumnos_AE003.empty() == false){
        if(i == 2){
          float Promedio = ObtenerPromedio(Sec.Alumnos_AE003, posAlA);
          cout << "Algoritmo y estructura de datos " << Promedio;
          if(Promedio < 4){
            cout << " Reprobado" <<endl;
          }else{
            cout << " Aprobado" <<endl;
          }
        }
      }
      if(Sec.Alumnos_DM004.empty() == false){
        if(i == 3){
          float Promedio = ObtenerPromedio(Sec.Alumnos_DM004, posAlD);
          cout << "Desarrollo web y movil " << Promedio;
          if(Promedio < 4){
            cout << " Reprobado" <<endl;
          }else{
            cout << " Aprobado" <<endl;
          }
        }
      }
      if(Sec.Alumnos_PP005.empty() == false){
        if(i == 4){
          float Promedio = ObtenerPromedio(Sec.Alumnos_PP005, posAlPAR);
          cout << "Paradigmas de programacion " << Promedio;
          if(Promedio < 4){
            cout << " Reprobado" <<endl;
          }else{
            cout << " Aprobado" <<endl;
          }
        }
      }
    }
  }else{
    menu(Sec);
  }
}

bool buscarSeccion(string sec){
  for(int i=0; i < 5; i++){
    if(sec == cod[i]){
      return true;
    }
  }
  return false;
}

bool archivo_existe(string nombre){
	ifstream archivo(nombre.c_str());
	return archivo.good();
}

vector<Student> CrearAlumnos(string name){
  vector<string> lines;
  string line;
  ifstream myfile (name);
  if (myfile.is_open())
  {
      while ( getline (myfile,line) )
      {
        lines.push_back(line);
      }
        myfile.close();
    }

  vector<Student> Alumnos;
  for(int a = 0; a < lines.size(); a++){
    vector<string> internal;
    stringstream ss(lines[a]);
    string tok;
    while(getline(ss, tok, ' ')) {        
        internal.push_back(tok);
    }
    //Sacar nombre
    string _name = internal[0] + internal[1];
    string _rut = internal[2];
    //Asumiendo que las notas son 4
    vector<string> notasA;
    for(int i = 0; i <= 3; i++){
      notasA.push_back(internal[3+i]);
    }
    Student s(_name, _rut, notasA);
    Alumnos.push_back(s);
  }

  return Alumnos;
}

float ObtenerPromedio(vector<Student> S, int pos){
  float suma;
  for(int i = 0; i < S[pos].notas.size(); i++){
    suma = stoi(S[pos].notas[i]) + suma;
  }
  float promedio = suma/S[pos].notas.size();
  return promedio;
}

void OrdenarNotas(vector<Student> verE){
  for(int i = 0; i < verE.size(); i++){
    float pro = ObtenerPromedio(verE, i);
    cout << verE[i].name << " " << pro << endl;
  }
}