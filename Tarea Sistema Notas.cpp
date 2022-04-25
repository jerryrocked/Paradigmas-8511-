#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct nombre_nota {
    string nombre;
    float nota = 0.000F;
} typedef nombre_nota;

string espacios(int n){
	string esp(n, ' ');
	return esp;
}

class Persona{
	public:
	struct {
		string nom,rut,dir,telf,sex,edad;
	}reg;
	Persona(){};
	~Persona(){};
	void datosper();
	void mostrarper();
};

void Persona::datosper(){
	cout << "Ingrese su nombre: "; getline(cin.ignore(), reg.nom);
    cout << "Ingrese su rut: "; getline(cin, reg.rut);
    cout << "Ingrese su direccion: " ; getline(cin, reg.dir);
    cout << "Ingrese su telefono: " ; getline(cin, reg.telf);
    cout << "Ingrese su sexo: "; cin >> reg.sex;
    cout << "Ingrese su edad: "; cin >> reg.edad;
};

void Persona::mostrarper(){
	cout << "Nombre: "<<reg.nom<<endl;
    cout << "Rut: "<<reg.rut<<endl;
    cout << "Direccion: "<<reg.dir<<endl;
    cout << "Telefono: " <<reg.telf<<endl;
    cout << "Sexo: "; cout<<reg.sex<<endl;
    cout << "Edad: "; cout<<reg.edad<<endl;
};

class Profesor: public virtual Persona{
	public:
		Profesor(){};
		~Profesor(){};
	void entregarnotas();
};
class Estudiante: public virtual Persona{
	public:
	Estudiante(){};
	~Estudiante(){};
	void Promedios(string curso, string secc, vector<nombre_nota> &n_n);
};

class Asignatura: public Profesor, public Estudiante{
	public:
	string s[10],a[10],c[10], cant;
	string mat[5]={"PROGRAMACION","BASE DE DATOS","ALGORITMO Y ESTRUCTURA DE DATOS","DESARROLLO WEB Y MOBIL","PARADIGMAS DE PROGRAMACION"};
	string cod[5]={"PR001","BD002","AE003","DM004","PP005"};
	Asignatura(){};
	~Asignatura(){};
	void Ingresar_Datos_Curso_Seccion();
	void Opcion_Profesor();
	void Opcion_Estudiante();
	void Aprovados_Reprobados(string curso, string secc, string nombre, string notas, string rut, float promedio, int opcion, vector<nombre_nota> &n_n, ofstream &archivo);
	void Ingreso_de_Notas();
};

void Asignatura::Ingresar_Datos_Curso_Seccion(){
	string opcion,sec;
	datosper();
	mostrarper();
	int cursos[5] = {1,2,3,4,5};
	cout<<"ATENCION: El mal ingreso de datos hara que tengan que ser ingresados nuevamente.\n";
	while(1){
		cout<<"\nEscriba la Cantidad de Asignaturas: ";
		cin>>cant;
		if (cant.length() > 1 || stoi(cant) > 5 || stoi(cant) < 1){
			cout<<"Cantidad invalida, reintente."<<endl;
			continue;
		}
		break;
	}
	for (int i=0;i<stoi(cant);i++){
		while(1){
			cout<<"Seleccione la Asignatura: ";
			cout<<"\n 1. "<<mat[0];
			cout<<"\n 2. "<<mat[1];
			cout<<"\n 3. "<<mat[2];
			cout<<"\n 4. "<<mat[3];
			cout<<"\n 5. "<<mat[4]<<endl;
			cin.ignore()>>opcion;
			if (opcion.length() > 1 || stoi(opcion) > 5 || stoi(opcion) < 1){
				cout<<"Opcion no disponible, reintente."<<endl;
				continue;
			}
			if(cursos[stoi(opcion)-1] == stoi(opcion)){
				cursos[stoi(opcion)-1] = 0;
			}
			else{
				cout<<"Asignatura ya ingresada, reintente."<<endl;
				continue;
			}
			break;
		}
		a[i]=mat[stoi(opcion) - 1];
		c[i]=cod[stoi(opcion) - 1];
		while(1){
			cout<<"\n Ingrese su seccion: ";
			cout<<"\n 1. Seccion 1";
			cout<<"\n 2. Seccion 2";			
			cin>>sec;
			if (sec.length() > 1 || stoi(sec) > 2 || stoi(sec) < 1){
				cout<<"Opcion no disponible, reintente."<<endl;
				continue;
			}
			s[i] = sec;
			break;	
		}
	}
};

void Estudiante::Promedios(string curso, string secc, vector<nombre_nota> &n_n){
	string nombre_archivo = curso + "_" + secc + "_" + "p.txt";
	ofstream archivo(nombre_archivo);
	sort(n_n.begin(), n_n.end(), [] (nombre_nota &x, nombre_nota &y) { return x.nota > y.nota; });
	for(int i=0;i<n_n.size() ;i++){
		archivo<<fixed <<setprecision(3)<<n_n[i].nombre<<espacios(40-n_n[i].nombre.length())<<n_n[i].nota<<"\n";
	}
	archivo.close();
}

void Asignatura::Aprovados_Reprobados(string curso, string secc, string nombre, string notas, string rut, float promedio, int opcion, vector<nombre_nota> &n_n, ofstream &archivo){
	if (opcion == 1){ 
		archivo<<nombre + espacios(40-nombre.length()) + rut + espacios(15-rut.length()) + notas + "\n";
		n_n.push_back({nombre, promedio});
	}
	else if (opcion == 2){
		archivo<<nombre+espacios(40-nombre.length())+rut+espacios(15-rut.length())+notas + "\n";
		archivo.close();
		n_n.push_back({nombre, promedio});
		Promedios(curso, secc, n_n);
		for(int i=0;i<n_n.size() ;i++){
			if(n_n[i].nota>=4.0){
				cout<<fixed <<setprecision(3)<<n_n[i].nombre<<espacios(40-n_n[i].nombre.length())<<n_n[i].nota<<" APROBADO\n";
			}
			else{
				cout<<fixed <<setprecision(3)<<n_n[i].nombre<<espacios(40-n_n[i].nombre.length())<<n_n[i].nota<<" REPROBADO\n";
			}
		}
		archivo<<reg.rut;
		archivo.close();
	}
}

void Asignatura::Ingreso_de_Notas(){
	vector<nombre_nota> n_n;
	int i;
	float promedio,nota;
	string opcion ,secc ,opmat, curso, nombre_alumno, rut, notas, nombre_archivo;
	while(1){
		cout<<"Ingrese la asignatura que imparte:\n";
		cout<<"1. PROGRAMACION\n";
		cout<<"2. BASE DE DATOS\n";
		cout<<"3. ALGORITMO Y ESTRUCTURA DE DATOS\n";
		cout<<"4. DESARROLLO WEB Y MOBIL\n";
		cout<<"5. PARADIGMA DE PROGRAMACION\n";
		cin>>opmat;
		if (opmat.length() > 1 || stoi(opmat) > 5 || stoi(opmat) < 1){
			cout<<"Opcion no disponible, reintente."<<endl;
			continue;
		}
		break;
	}
	while(1){
			cout<<"Ingrese su seccion:\n";
			cout<<"1. Seccion 1\n";
			cout<<"2. Seccion 2\n";
			cin>>secc;
			if (secc.length() > 1 || stoi(secc) > 2 || stoi(secc) < 1){
				cout<<"Opcion no disponible, reintente."<<endl;
				continue;
			}
			break;
	}
	curso = cod[stoi(opmat) - 1];
	nombre_archivo = curso + "_" + secc + "_" + "n.txt";
    ofstream archivo(nombre_archivo);
	while(1){
		promedio = 0;
		i=0;
		cout<<"Ingrese el nombre del alumno:\n";
		getline(cin.ignore(),nombre_alumno);
		cout<<"Ingrese el rut del alumno:\n";
		cin>>rut;
		cout<<"Ingrese las notas del alumno separadas por un espacio:\n";
		getline(cin.ignore(),notas);
		istringstream separador(notas);
		while(separador >> nota){
			 promedio =  promedio + nota;
			i++;
		}
		promedio= promedio/i;
		cout<<nombre_alumno<<endl<<rut<<endl<<notas;
		cout<<"\n\nIngrese una opcion:\n";
		cout<<"1. Guardar y continuar.\n";
		cout<<"2. Guardar y salir.\n";
		cout<<"3. Volver a ingresar los datos.\n";
		cout<<"4. Volver al menu principal sin guardar.\n";
		cout<<"ATENCION: El mal ingreso de datos hara que tengan que ser ingresados nuevamente.\n";
		cin>>opcion;
		if (opcion.length() > 1 || stoi(opcion) > 4 || stoi(opcion) < 1){
			cout<<"Ingrese una opcion valida.\nVolviendo al menu principal."<<endl;
			archivo<<reg.rut;
			archivo.close();
			continue;
		}
		Aprovados_Reprobados(curso, secc, nombre_alumno, notas, rut, promedio, stoi(opcion), n_n, archivo);
		if (stoi(opcion) == 2)
				return;
		else if (stoi(opcion) == 3)
				continue;
		else if (stoi(opcion) == 4){
				archivo<<reg.rut;
				archivo.close();
				return;
				}
		continue;
	}
}

void Asignatura::Opcion_Profesor(){
	datosper();
	mostrarper();
	Ingreso_de_Notas();
	}

void Asignatura::Opcion_Estudiante(){
	int tam;
	ifstream archivo_1;
    ofstream archivo_2("notas.txt");
    Ingresar_Datos_Curso_Seccion();
	string nombre, nota ,linea, narch;
	for(int i = 0;i<stoi(cant); i++){
		archivo_1.open(c[i] + "_" + s[i] + "_p.txt");
		if(!archivo_1.is_open()){
			archivo_2 << a[i] + espacios(40-a[i].length())+"-----     Aun no se suben las notas.\n";
			archivo_1.close();
			continue;
		}
		else{
			while(getline(archivo_1, linea)){
				nombre = linea.substr(0,reg.nom.length());
				if(nombre.compare(reg.nom) == 0){
					nota = linea.substr(40);
					if(stof(nota) >= 4.0){
						archivo_2 << a[i] + espacios(40-a[i].length())+nota+"     APROBADA\n";
						break;
					}
					else{
						archivo_2 << a[i] + espacios(40-a[i].length())+nota+"     REPROBADA\n";
						break;
					}
				}
			}
			if(nombre.compare(reg.nom) == 1){
				archivo_2 << a[i] + espacios(40-a[i].length())+"-----     Aun no se suben sus notas.\n";
			}
		}
		archivo_1.close();
	}
	archivo_2.close();
}

int main(int argc, char** argv) {
	string opcion;
	Asignatura as;
	while(1){
		cout<<"Seleccione una opcion: \n";
		cout<<"1. Profesor: \n";
		cout<<"2. Estudiante: \n";
		cout<<"3. Salir \n";
		cin>>opcion;
		if (opcion.length() > 1 || stoi(opcion) > 3 || stoi(opcion) < 1){
			cout<<"Ingrese una opcion valida."<<endl;
			continue;
		}
	break;
	}
		if (stoi(opcion) == 1){
			as.Opcion_Profesor();
			}
		else if (stoi(opcion) == 2){
			as.Opcion_Estudiante();
			}
		else {
			cout<<"Saliendo del sistema";
			return 0;
		}
}