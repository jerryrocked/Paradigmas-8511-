#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

//Clases
class Persona{
    public:
        Persona(){ };
        ~Persona(){ };
        string nombre, rut;
};

class Asignatura{
    public:
        string codigo, nombAsig, seccion;
};

class Estudiante:public Persona, Asignatura{
    public:
        float notaFinal;
        void PedirNotas();
};

class Profesor:public Persona, Asignatura{
    public:

        void EntregarNotas();
};




//CONSTRUCTORES
void Estudiante::PedirNotas(){
    string nombEst,apeEst,rutEst,asigEst,codEst,secEst,estadoAl;
    float notaFinal,n1,n2,n3,n4;
    ofstream alumnos;
    alumnos.open("NotasAl.txt",ios::out);
    do{
        cout<<"PEDIR NOTAS:"<<endl<<endl;
        
        cout<<"Ingresar nombre: ";
        getline(cin.nombEst);
       
        cout<<"Apellido: ";
        getline(cin.apeEst)
        
        cout<<"Ingresa tu rut: ";
        getline(cin.rutEst);
        
        cout<<"Ingresa la asginatura: ";
        getline(cin.asigEst);

        cout<<"Codigo de la Asignatura: ";
        getline(cin.codEst);

        cout<<"Seccion: ";
        getline(cin.secEst);

        alumnos.open("NotasAl.txt",ios::in);
        cout<<"Nombre Alumno: "<<nombEst<<" "<<apeEst<<endl;
        cout<<"Rut: "<<rut<<endl;
        cout<<"Nota 1: "<<n1<<endl;
        cout<<"Nota 2: "<<n2<<endl;
        cout<<"Nota 3: "<<n3<<endl;
        cout<<"Nota 4: "<<n4<<endl;
        notaFinal=(n1+n2+n3+n4)/4;
        if(notaFinal>=4.0){
            estadoAl="Alumno Aprobado";
        }
        else{
            estadoAl="Alumno Reprobado";
        }
    }
}

void Profesor::EntregarNotas(){
    string rutProf,asigProf,codProf,secProf;
    float n1,n2,n3,n4;

    cout<<"MENU PROFESOR"<<endl<<endl;
    
    cout<<"Ingrese su Rut: ";
    getline(cin.rutProf);

    cout<<"Asignatura: ";
    getline(cin.asigProf);

    cout<<"Codigo: ";
    getline(cin.codProf);

    cout<<"Seccion: ",
    getline(cin.secProf);


    float n1,n2,n3,n4;
    string nomAl,apeAl,rutAl;
    ofstream notas;
    notas.open("Notas.txt",ios::out);
    do{
        cout<<"INGRESAR ALUMNO"<<endl<<endl;
        
        cout<<"Ingresar Nombre de Alumno: ";
        getline(cin.nom);
        cout<<"Apellido de alumno: ";
        getline(cin.apeAl);
        cout<<"Ingrese Rut de Alumno: ";
        getline(cin.rutAl);

        cout<<"REGISTRO DE NOTAS"<<endl<<endl;

        cout<<"Nota 1: ";
        cin>>n1;
        while(n1<1.0 || n1>7.0){
            cout<<"Error, Ingrese Nuevamente la nota 1: ";
            cin>>n1;
        }
        cout<<"Nota 2: ";
        cin>>n2;
        while(n2<1.0 || n2>7.0){
            cout<<"Error, Ingrese Nuevamente la nota 2: ";
            cin>>n2;
        }
        cout<<"Nota 3: ";
        cin>>n3;
        while(n3<1.0 || n3>7.0){
            cout<<"Error, Ingrese Nuevamente la nota 3: ";
            cin>>n3;
        }
        cout<<"Nota 4: ";
        cin>>n4;
        while(n4<1.0 || n4>7.0){
            cout<<"Error, Ingrese Nuevamente la nota 4: ";
            cin>>n4;
        }
    }
}
int menuPrin(){
    int OPmenu;
    cout<<"MENU PRINCIPAL"<<endl<<endl;
    
    cout<<"1. Profesor"<<endl;
    cout<<"2. Alumno"<<endl;
    cout<<"3. Salir"<<endl;
    cout<<"Elija una opcion: ";
    cin>>OPmenu;
    return OPmenu;
}

int menuEst(){
    int opEst;
    cout<<"MENU ESTUDIANTE"<<endl<<endl;
    cout<<"1. Pedir Notas"<<endl;
    cout<<"2. Atras"<<endl;
    cout<<"Elija una opcion: ";
    cin>>opEst;
    return opEst;
}

int menuProf(){
    int opProf;
    cout<<"MENU PROFESOR"<<endl<<endl;
    cout<<"1. Ingresar Notas"<<endl;
    cout<<"2. Atras"<<endl;
    cout<<"3. Elija una opcion: ";
    cin>>opProf;
    return opProf;
}

int main(){
    int OP,OP2,OP3;

    do{
        OP=menuPrin();
        switch (OP){
            case 1:
                do{
                    OP3=menuProf();
                    switch(OP3){
                        case 1:
                            Profesor::EntregarNotas(ios::out);
                            break;
                        case 2:
                            menuPrin();
                            break;
                    }
                }
                while(OP3!=3){
                    break;
                }
            case 2:
                do{
                    OP2=menuEst();
                    switch(OP2){
                        case 1:
                            Estudiante::EntregarNotas(ios::in);
                            break;
                        case 2:
                            menuPrin();
                    }
                }
                while(OP2!=3){
                    break;
                }
            
        }
  
    }
    while(OP!=3){
        break;
    }

}
