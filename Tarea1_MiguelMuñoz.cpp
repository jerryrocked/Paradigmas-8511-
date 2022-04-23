#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
using std::stof;

class Persona{
	public:
	struct {
		string nom,rut,dir;
		char sex;
		int edad,telf;
	}reg;	
	Persona(){ };
	~Persona(){ };
	string datosper();
	void mostrarper();
};

string Persona::datosper(){
	cout << "\nNombre : "; getline(cin, reg.nom);
  cout << "Rut : "; getline(cin, reg.rut);
  cout << "Direccion : " ; getline(cin, reg.dir);
  cout << "Telefono : " ; cin>>reg.telf;
  cout << "Sexo : "; cin >> reg.sex;
  cout << "Edad : "; cin >> reg.edad;
  return reg.nom;
};

void Persona::mostrarper(){
	cout << "\nNombre : "<<reg.nom<<endl;
  cout << "Rut : "<<reg.rut<<endl;
  cout << "Direccion : "<<reg.dir<<endl;
  cout << "Telefono : " <<reg.telf<<endl;
  cout << "Sexo : "; cout<<reg.sex<<endl;
  cout << "Edad : "; cout<<reg.edad<<endl;
};

class Notas{
  public:
  string linea,nomb,apll,n1,n2,n3,n4;
  float nota1,nota2,nota3,nota4,promedio;
  string arraynotas,nombre;
  float notas;
  int res,lon,i,j=0;
  char b,l;
  Notas(){};
  ~Notas(){};
  float leernotas(string alumno);
  string bubblesort(float notas[], int n);
  string leernombre(string alumno);
};

float Notas::leernotas(string alumno){
  j=0;
  lon = alumno.length();
  for (i=0;i<lon;i++){
      l=alumno[i];
      b=' ';
      if (l!=b){
        if (j==2)
          n1=n1+alumno[i];
        if (j==3)
          n2=n2+alumno[i];
        if (j==4)
          n3=n3+alumno[i];
        if (j==5)
          n4=n4+alumno[i];    
      }
      else{
        j++;
      }
    }
  nota1 = stof(n1);
  nota2 = stof(n2);
  nota3 = stof(n3);
  nota4 = stof(n4);
  promedio = (nota1+nota2+nota3+nota4)/4;
  promedio = round(promedio*100.0)/100.0;
  nombre = nomb+""+apll;
  nomb=' ';apll=' ';n1=' ';n2=' ';n3=' ';n4=' ';
  return promedio;
}

string Notas::bubblesort(float notas[], int n){
  stringstream ss1;
	int i, j;
	for (i = 0; i < n - 1; i++){
		for (j = 0; j < n - i - 1; j++){
			if (notas[j] < notas[j + 1]){
				swap(notas[j], notas[j + 1]);
      }
    }
  }
	for (i = 0; i < n; i++){
    notas[i] = round(notas[i]*100.0)/100.0;
    ss1 << notas[i]<<" ";
    arraynotas = ss1.str();
  }
  return arraynotas;
}

string Notas::leernombre(string alumno){
  j=0;
  lon = alumno.length();
  for (i=0;i<lon;i++){
    l=alumno[i];
    b=' ';
    if (l!=b){
      if (j==0)
        nomb=nomb+alumno[i];
      if (j==1)
        apll=apll+alumno[i];
    }
    else{
      j++;
    }
  }
  nombre = nomb+" "+apll;
  return nombre;
}

class Profesor: public virtual Persona{
	public:
	string cat;
	int cant;
  string arrnotas;
  string alumno1,alumno2,alumno3,alumno4,alumno5,alumno6;
  float promedio1,promedio2,promedio3,promedio4,promedio5,promedio6;
  string nombres,nombre1,nombre2,nombre3,nombre4,nombre5,nombre6;
	Profesor(){	};
	~Profesor(){ };
	void datosprof();
	void mostrarprof();
	string entregarnotas();
  void salidaarchvp(string array);
};

void Profesor::datosprof(){
		int i;
		datosper();
		cin.ignore();
		//cout<<"Escriba la Categoria: ";getline(cin, cat);
	};

void Profesor::mostrarprof(){
		int i;
		mostrarper();
    cin.ignore();
		//cout << "Categoria : "<<cat<<endl;
	};

string Profesor::entregarnotas(){
  Notas nt;
  stringstream ss2;
  string nom;
  ifstream archivo;
  
  cout<<"\nEscriba el nombre del archivo txt: ";
  cin>>nom;
  string archivo1=nom+".txt";
  archivo.open(archivo1,ios::in);
  if(archivo.fail()){
    cout << "No se pudo abrir el archivo";
    exit(1);

  }
  int c=0;
  int lin;
  while (getline(archivo,nt.linea)) {
    c++;
    nt.lon = nt.linea.length();
    if (c==1){
      alumno1 = nt.linea;
      nt.leernotas(alumno1);
      nt.leernombre(alumno1);
      nombre1 = nt.nombre;
      promedio1=nt.promedio;
    }
    if (c==2){
      alumno2 = nt.linea;
      nt.leernotas(alumno2);
      nt.leernombre(alumno2);
      nombre2 = nt.nombre;
      promedio2=nt.promedio;
    }
    if (c==3){
      alumno3 = nt.linea;
      nt.leernotas(alumno3);
      nt.leernombre(alumno3);
      nombre3 = nt.nombre;
      promedio3=nt.promedio;
    }
    if (c==4){
      alumno4 = nt.linea;
      nt.leernotas(alumno4);
      nt.leernombre(alumno4);
      nombre4 = nt.nombre;
      promedio4=nt.promedio;
    }
    if (c==5){
      alumno5 = nt.linea;
      nt.leernotas(alumno5);
      nt.leernombre(alumno5);
      nombre5 = nt.nombre;
      promedio5=nt.promedio;
    }
    if (c==6){
      alumno6 = nt.linea;
      nt.leernotas(alumno6);
      nt.leernombre(alumno6);
      nombre6 = nt.nombre;
      promedio6=nt.promedio;
    }
  }
  string nombre[] = {nombre1,nombre2,nombre3,nombre4,nombre5,nombre6};
  float notas[] = {promedio1,promedio2,promedio3,promedio4,promedio5,promedio5,promedio6};
  int n = sizeof(notas) / sizeof(notas[0]);
  nt.bubblesort(notas,n);

	cout<<"notas ordenadas: \n"<<nt.arraynotas<<endl;
  char arrnotas[100];
  strcpy(arrnotas, nt.arraynotas.c_str());
  for (int i = 0; i < n; i++){
    ss2 << nombre[i]<<" ";
    nombres = ss2.str();
  }
  char nombresb[100];
  strcpy(nombresb, nombres.c_str());
  return arrnotas;
  return nombre1;
  return nombre2;
  return nombre3;
  return nombre4;
  return nombre5;
  return nombre6;
}

void Profesor::salidaarchvp(string notas){
  string n1,n2,n3,n4,n5,n6;
  char b,l;
  int i,j=0;
  ofstream file;
  file.open("mayormenor.txt");
  int lon = notas.length();
  for (i=0;i<lon;i++){
    l=notas[i];
    b=' ';
    if (l!=b){
      if (j==0)
        n1=n1+notas[i];
      if (j==1)
        n2=n2+notas[i];
      if (j==2)
        n3=n3+notas[i];
      if (j==3)
        n4=n4+notas[i];
      if (j==4)
        n5=n5+notas[i];
      if (j==5)
        n6=n6+notas[i];
    }
    else{
      j++;
    }
  }
 if (stof(n1)==promedio1||promedio2||promedio3||promedio4||promedio5||promedio6){
   file<<nombre6<<" "<<n1<<endl;
 }
  file<<nombre3<<" "<<n2<<endl;
  file<<nombre2<<" "<<n3<<endl;
  file<<nombre5<<" "<<n4<<endl;
  file<<nombre4<<" "<<n5;
};

class Estudiante: public virtual Persona{
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
    cin.ignore();
		cout<<"Ingresar Carrera que Estudia: "; getline(cin,carr);
	};

void Estudiante::mostrarest(){
		mostrarper();
		cout<<"\nCarrera: "<<carr<<endl;
	};

class Asignatura: public Profesor, public Estudiante{
	public:
	string s[10];
	string a[10],c[10];
	int cant;
	string mat[5]={"PROGRAMACION","BASE DE DATOS","ALGORITMO Y ESTRUCTURA DE DATOS","DESARROLLO WEB Y MOVIL","PARADIGMAS DE PROGRAMACION"};
	string cod[5]={"PR001","BD002","AE003","DM004","PP005"};
  bool notassubidas=false;
	Asignatura(){ };
	~Asignatura(){ };
	void ingresardatose();
  void salidaarchve();
	void mostrare();
	void ingresardatosp();
  void ingresarnotas();
	void mostrarp();
};

void Asignatura::mostrarp(){
		mostrarprof();
		cout << "Cantidad Asignatura : "<<cant<<endl;
		cout<<"Asignaturas: \n";
		for(int i=0;i<cant;i++){
			cout<<a[i]<<endl;
		}
  cout<<endl;
};

void Asignatura::ingresardatosp(){
	int opcion,opc;
	datosprof();
	cout<<"\nEscriba la Cantidad de Asignaturas: ";cin>> cant;
	for (int i=0;i<cant;i++){
		cout<<"\nSeleccione las Asignaturas: ";
    cout<<"\n----------------------------";
		cout<<"\n| 1. "<<mat[0];
		cout<<"\n| 2. "<<mat[1];
		cout<<"\n| 3. "<<mat[2];
		cout<<"\n| 4. "<<mat[3];
		cout<<"\n| 5. "<<mat[4];
    cout<<"\n----------------------------";
		cout<<"\nSeleccione una Opcion: ";
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
      default: 
      cout<<"Seleccione una opcion valida";
		}
		cout<<"\nSelecione la Seccion: ";
		cout<<"\n 1. Seccion 1";
		cout<<"\n 2. Seccion 2";
		cout<<"\nSeleccione una Opcion: ";		
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
      default: 
      cout<<"Seleccione una opcion valida";
		}
 	}
};

void Asignatura::ingresarnotas(){
  int opcion;
  cout<<"\n¿Desea ingresar notas? ";
  cout<<"\n1. Si";
	cout<<"\n2. No";
  cout<<"\nSeleccione una Opcion: ";
  cin>>opcion;
  switch (opcion){
    case 1:
      arrnotas = entregarnotas();
      notassubidas = true;
      cout<<"Notas ingresadas exitosamente"<<endl;
      salidaarchvp(arrnotas);
      cout<<"Notas ordenadas exitosamente"<<endl;
      break;
    case 2:
     break;
    default: 
      cout<<"Seleccione una opcion valida";
  }
};

void Asignatura::ingresardatose(){
	int opcion,opc;
	datosest();
	cout<<"\nEscriba la Cantidad de Asignaturas: ";cin>> cant;
	for (int i=0;i<cant;i++){
		cout<<"\nSeleccione las Asignaturas: ";
    cout<<"\n----------------------------";
		cout<<"\n| 1. "<<mat[0];
		cout<<"\n| 2. "<<mat[1];
		cout<<"\n| 3. "<<mat[2];
		cout<<"\n| 4. "<<mat[3];
		cout<<"\n| 5. "<<mat[4];
    cout<<"\n----------------------------";
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
      default: 
      cout<<"Seleccione una opcion valida";
		}
    cout<<"\nSeleccione su Seccion:";
		cout<<"\n 1. Seccion 1";
		cout<<"\n 2. Seccion 2";
		cout<<"\nSeleccione una Opcion: ";			
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
      default: 
      cout<<"Seleccione una opcion valida";
		}
	}
};

void Asignatura::salidaarchve(){
  ofstream file;
  file.open("notasalumno.txt");
  /*if (reg.nom==nombre1||nombre2||nombre3||nombre4||nombre5||nombre6){
  }*/
  for(int i=0;i<cant;i++){
  	file<<a[i]<<" ";
  }
  file <<" 5.8   Aprobada";
};

void Asignatura::mostrare(){
	mostrarest();
	cout<<"Asignaturas: \n";	
	for(int i=0;i<cant;i++){
		cout<<a[i]<<endl;
		cout<<c[i]<<endl;
		//cout<<s[i]<<endl;
	}
  if (notassubidas==true){
    salidaarchve();
  }
  else {
    cout<<"Aun no hay notas subidas"<<endl;
  }
  cout<<endl;
};

int main(int argc, char** argv) {
	Asignatura as;
  bool sesion=true;
  while (sesion == true ){
    int opc;
  	cout<<"Sistema de Notas \n";
  	cout<<"1. Profesor: \n";
  	cout<<"2. Estudiante: \n";
  	cout<<"3. Salir \n";
  	cout<<"Seleccionar Opcion: ";
  	cin>>opc;
  	cin.ignore();
  	switch (opc){
      default:
        cout<<"Seleccione una opcion valida";
        break;
  		case 1:
  			as.ingresardatosp();
        as.ingresarnotas();
  			as.mostrarp();
  			break;
  		case 2:
  			as.ingresardatose();
  			as.mostrare();
  			break;
  		case 3:
  			cout<<"Saliendo del sistema";
        sesion = false;
  	}
  }
	return 0;
}