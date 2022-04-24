#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

/*
Declaracion funcion de indentificacion del sistema
*/
#ifdef _WIN32
  #include<windows.h>
#endif  

/*
Struck ocupado para guardar la nota y el nombre al momento de ser ingresador por el profesor
*/
struct nombre_nota {
    string nombre;
    float nota = 0.000F;
} typedef nombre_nota;

/*
Funcion ocupada para rellener el txt y la pantalla
*/
string espacios(int n){
	string esp(n, ' ');
	return esp;
}

/*
Funcion ocupada para limpiar la pantalla
*/
void limpiar_pantalla(){
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

/*
Clase base de Estudiante y Profesor
*/
class Persona{
	public:
	struct {
		string nom,rut;
	}reg;	
	Persona(){ };
	~Persona(){ };
	void datosper();
	void mostrarper();
};

/*
Funcion para rellenar los datos de persona
*/
void Persona::datosper(){
	string r;
	inicio:
		cout << "Ingrese su nombre y rut por favor.\n";
		cout << "Nombre : "; getline(cin.ignore(), reg.nom);
    	cout << "Rut : "; getline(cin, reg.rut);
    	cout <<"\nEs correcta la informacion? Ingrese (s) o (n) para continuar.\El fallo significara volver a ingresar sus datos.\n"; getline(cin, r);
    	if (r.length() != 1 || r[0] != 's' && r[0] != 'n'){
			cout<<"Ingrese una opcion invalida.\n\nSe Volveran a preguntar los datos.\n";
			system("PAUSE");
			limpiar_pantalla();
			goto inicio;
		}
		if(r[0] == 'n'){
			limpiar_pantalla();
			goto inicio;
		}
		limpiar_pantalla();
	}

/*
Funcion para mostar los datos de persona
*/
void Persona::mostrarper(){
		cout << "Nombre : "<<reg.nom<<endl;
    	cout << "Rut : "<<reg.rut<<endl;
	};


/*
Declaracion clase Profesor
*/
class Profesor: public virtual Persona{
	public:
	Profesor(){};
	~Profesor(){};
	void entregarnotas();
};

/*
Declaracion Clase Estudiante
*/
class Estudiante: public virtual Persona{
	public:
	Estudiante(){};
	~Estudiante(){};
	void notas(string codig, string seccion);
};


/*
Declaracion Clase Asignatura
*/
class Asignatura: public Profesor, public Estudiante{
	public:
	string s[10],a[10],c[10];
	int cant;
	string mat[5]={"PROGRAMACION","BASE DE DATOS","ALGORITMO Y ESTRUCTURA DE DATOS","DESARROLLO WEB Y MOBIL","PARADIGMAS DE PROGRAMACION"};
	string cod[5]={"PR001","BD002","AE003","DM004","PP005"};
	Asignatura(){};
	~Asignatura(){};
	void ingresardatose();
	void OpP();
	void OpE();
	void Ingreso();
};

/*
Declaracion Ingreso de datos del estudiante
*/
void Asignatura::ingresardatose(){
	int opcion,opc;
	datosper();
	cout<<"ATENCION: CUALQUIER ERROR AL INGRESAR DATOS SIGNIFICARA HACER LA CONSULTA AL PROGRAMA NUEVAMENTE.\n\nEscriba la Cantidad de Asignaturas: ";cin>>cant;
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
		cout<<"\n Seleccione la seccion: ";			
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
		limpiar_pantalla();
	}
};


/*
Declaracion Ingreso de datos del profesor
*/
void Asignatura::Ingreso(){
	string a,s;
	cout<<"Ingrese la opcion correcta:\n\n";
	cout<<"1. PROGRAMACION\n";
	cout<<"2. BASE DE DATOS\n";
	cout<<"3. ALGORITMO Y ESTRUCTURA DE DATOS\n";
	cout<<"4. DESARROLLO WEB Y MOBIL\n";
	cout<<"5. PARADIGMA DE PROGRAMACION\n";
	cout<<"ATENCION:  El ingreso erroneo significara volver al menu principal.\n";
	cin>>a;
	if (a.size() != 1 || a[0] != '1' && a[0] != '2' && a[0] != '3' && a[0] != '4' && a[0] != '5'){
		cout<<"Ingrese una opcion invalida.\n\nVolviendo al menu principal."<<endl;
		system("PAUSE");
		limpiar_pantalla();
		return;
	}
	cout<<"Ingrese la opcion correcta:\n\n";
	cout<<"1. Seccion 1\n";
	cout<<"2. Seccion 2\n";
	cout<<"ATENCION:  El ingreso erroneo significara volver al menu principal.\n";
	cin>>s;
	if (s.size() != 1 || s[0] != '1' && s[0] != '2'){
		cout<<"Ingrese una opcion invalida.\n\nVolviendo al menu principal."<<endl;
		system("PAUSE");
		limpiar_pantalla();
		return;
	}
	notas(cod[stoi(a)-1],s);
}

/*
Declaracion entrega de notas para el estudiante
*/
void Estudiante::notas(string c, string s){
	vector<nombre_nota> nom_nota;
	limpiar_pantalla();
	int i;
	float prom,nota;
	string na,r,no,o;
	string a, narch1 =c+"_"+s+"_"+"notas.txt" , narch2 =c+"_"+s+"_"+"promedios.txt";
    ofstream arch1(narch1);
    ofstream arch2(narch2);
	inicio:
		prom = 0;
		i=0;
		cout<<"Ingrese el nombre de alumno:\n";
		getline(cin.ignore(),na);
		limpiar_pantalla();
		cout<<"Ingrese el rut de alumno:\n";
		cin>>r;
		limpiar_pantalla();
		cout<<"Ingrese las notas del alumno separadas por un espacio:\n";
		getline(cin.ignore(),no);
		istringstream separador(no);
		while(separador >> nota){
			prom = prom + nota;
			i++;
		}
		prom=prom/i;
		limpiar_pantalla();
		cout<<"Datos entregados:\n\n"<<na<<endl<<r<<endl<<no;
		cout<<"\n\nIngrese la opcion correcta:\n\n";
		cout<<"1. Guardar datos en el archivo y continuar.\n";
		cout<<"2. Guardar datos en el archivo y salir.\n";
		cout<<"3. Volver a ingresar los datos.\n";
		cout<<"4. Volver al menu principal sin guardar.\n";
		cout<<"ATENCION:  El ingreso erroneo significara volver al menu principal.\n";
		cin>>o;
		if (o.size() != 1 || o[0] != '1' && o[0] != '2' && o[0] != '3' && o[0] != '4'){
			cout<<"Ingrese una opcion invalida.\n\nVolviendo al menu principal."<<endl;
			system("PAUSE");
			limpiar_pantalla();
			arch1<<reg.rut;
			arch1.close();
			return;
		}
		int n = stoi(o);
		switch (n){
			case 1:
				arch1<<na+espacios(40-na.size())+r+espacios(15-r.size())+no+"\n";
				nom_nota.push_back({na,prom});
				limpiar_pantalla();
				break;
			case 2:
				arch1<<na+espacios(40-na.size())+r+espacios(15-r.size())+no+"\n";
				arch1.close();
				nom_nota.push_back({na,prom});
				sort(nom_nota.begin(), nom_nota.end(), [] (nombre_nota &x, nombre_nota &y) { return x.nota > y.nota; });
				for(int i=0;i<nom_nota.size() ;i++){
					arch2<<fixed <<setprecision(3)<<nom_nota[i].nombre<<espacios(40-nom_nota[i].nombre.size())<<nom_nota[i].nota<<"\n";
				}
				arch2.close();
				limpiar_pantalla();
				for(int i=0;i<nom_nota.size() ;i++){
					if(nom_nota[i].nota>=4.0){
						cout<<fixed <<setprecision(3)<<nom_nota[i].nombre<<espacios(40-nom_nota[i].nombre.size())<<nom_nota[i].nota<<" APROBADO\n";
					}
					else{
						cout<<fixed <<setprecision(3)<<nom_nota[i].nombre<<espacios(40-nom_nota[i].nombre.size())<<nom_nota[i].nota<<" REPROBADO\n";
					}
				}
				system("PAUSE");
				limpiar_pantalla();
				return;
			case 3:
				limpiar_pantalla();
				break;
			case 4:
				limpiar_pantalla();
				arch1<<reg.rut;
				arch1.close();
				return;
		}
		goto inicio;
}

/*
Declaracion opcion profesor
*/
void Asignatura::OpP(){
	datosper();
	Ingreso();
	}


/*
Declaracion opcion estudiante
*/
void Asignatura::OpE(){
	ingresardatose();
	int tam;
	ifstream arch1;
    ofstream arch2("notas.txt");
	string nombre, nota ,linea, narch;
	for(int i = 0;i<cant; i++){
		arch1.open(c[i] + "_" + s[i] + "_promedios.txt");
		cout<<arch1.is_open()<<endl;
		if(!arch1.is_open()){
			arch2 << a[i] + espacios(40-a[i].length())+"-----     El Profesor aun no sube el archivo de notas del curso.\n";
			arch1.close();
			continue;
		}
		else{
			while(getline(arch1, linea)){
				nombre = linea.substr(0,reg.nom.length());
				if(nombre.compare(reg.nom) == 0){
					nota = linea.substr(40);
					if(stof(nota) >= 4.0){
						arch2 << a[i] + espacios(40-a[i].length())+nota+"     APROBADA\n";
						break;
					}
					else{
						arch2 << a[i] + espacios(40-a[i].length())+nota+"     REPROBADA\n";
						break;
					}
				}
			}
			if(nombre.compare(reg.nom) == 1){
				arch2 << a[i] + espacios(40-a[i].length())+"-----     El Profesor aun no sube su nota final.\n";
			}
		}
		arch1.close();
	}
	arch2.close();
}

/*
Declaracion main
*/
int main(int argc, char** argv) {
	string opcion;
	Asignatura as;
	inicio:
		cout<<"Seleccione una opcion: \n";
		cout<<"1. Profesor: \n";
		cout<<"2. Estudiante: \n";
		cout<<"3. Salir \n";
		cin>>opcion;
		if (opcion.size() != 1 || opcion[0] != '1' && opcion[0] != '2' && opcion[0] != '3'){
			cout<<"Ingrese una opcion valida."<<endl;
			system("PAUSE");
			limpiar_pantalla();
			goto inicio;
		}
		int n = stoi(opcion);
		switch (n){
			case 1:
				limpiar_pantalla();
				as.OpP();
				return 0;
			case 2:
				limpiar_pantalla();
				as.OpE();
				return 0;
			case 3:
				limpiar_pantalla();
				cout<<"Saliendo del sistema";
				return 0;
		}
}