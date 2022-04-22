#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <cstdio>

using namespace std;
fstream f;

class Persona{
    public:
        string nombre[50];
        string rut[50];
        int i=0;
    void registrar(); // registrar nuevo usuario // TRUE
    void mostrar_df(); // TRUE
}; // TRUE

class alumno : public Persona{
    public:
        int seccion; // 1, 2 o 3
    void soli_nota(); // funcion para pedir sus notas // TRUE
}; // TRUE

class Materia{
    public:
        string nrc[3] = {"01.","02.","03."};
        string ID[5] = {"PR001","BD002","AE003","DM004","PP005"};
        string materia_nombres[5] = {"PROGRAMACION","BASE DE DATOS", "ALGORITMO Y ESTRUCTURA DE DATOS", "DESARROLLO WEB Y MOBIL", "PARADIGMA DE PROGRAMACION"};

}; // TRUE

class Profesor : public Persona,public Materia{
    public:
        void crear_file(); // TRUE
        void nota_alumno(string rut2, int materia); // TRUE
        void cargar_file(); // TRUE
    private:
        float ND,nt[4]; // promedio y notas
    void calcular_ND(); // TRUE
}; // TRUE

void Profesor::calcular_ND(){
    ND = nt[0] + nt[1] + nt[2] + nt[3];
    ND = ND / 4;
} // TRUE

void alumno::soli_nota(){
    while(true){
        string name;
        cout<<"Ingrese su rut: ";
        cin>>name;
        name += ".txt";
        cout<<endl;
        ifstream f;
        string line;
        f.open(name,ios::in);
        if(f.fail()){cout<<"El profesor no ha subido sus notas.\n";break;}
        while(!f.eof()){
            getline(f,line);
            cout<<line<<endl;
        }
    cout<<"\nListo :D\n";
    break;
    }
} // TRUE

void Profesor::crear_file(){
    int materia,seccion,aprobado,reprobado;
    string nombre2,ape,rut2;
    int opcion = 1;
    while(true){
        cout<<"\n---Bienvenido al ingreso de notas manualmente.---\n\n";
        cout<<"Seleccione el codigo de materia que imparte:\n"<<ID[0]<<" (0)\n"<<ID[1]<<" (1)\n"<<ID[2]<<" (2)\n"<<ID[3]<<" (3)\n"<<ID[4]<<" (4)\n: ";
        cin>>materia;
        if(materia < 0 || materia > 4){
            cout<<"\nERROR INGRESAR DATOS...\n";
            break;
        }
        cout<<"\nSeleccione la seccion:\n"<<nrc[0]<<" (0)\n"<<nrc[1]<<" (1)\n"<<nrc[2]<<" (2)\n: ";
        cin>>seccion;
        if(seccion < 0 || seccion > 2){
            cout<<"\nERROR INGRESAR DATOS...\n";
            break;
        }
        system("clear");
        string name = nrc[seccion];
        name += ID[materia];
        name += ".txt";
        ofstream f;
        f.open(name, fstream::app);
        while(opcion==1){
            cout<<"Ingrese el nombre, apellido y rut del estudiante: \n"; 
            cin>>nombre2>>ape>>rut2;
            for(int i=0;i<4;i++){
                cout<<"Ingrese la nota numero "<<i+1<<": ";
                cin>>nt[i];
            }
            calcular_ND();
            if(ND>=4){aprobado++;}
            else{reprobado++;}
            nota_alumno(rut2, materia);
            f<<nombre2<<" "<<ape<<" "<<ND<<endl;
            cout<<"\nDesea ingresar mas alumnos? (1 = si)/(0 = no): ";
            system("clear");
            cin>>opcion;
            if(opcion==0){
                break;
            }
        }
        f.close();
        cout<<"\nAprobados: "<<aprobado<<endl;
        cout<<"Reprobados: "<<reprobado<<endl;
        cout<<"\nListo :D\n";
        break;
    }
} // TRUE

void Profesor::nota_alumno(string rut2,int materia){
    string estado = "Reprobado";
    if(ND >= 4){
        estado = "Aprobado";
    }
    rut2 += ".txt";
    ofstream f;
    f.open(rut2, fstream::app);
    f<<materia_nombres[materia]<<" "<<ND<<" "<<estado<<endl;
    f.close();
} // TRUE

int menu(){
    int x;
    cout<<"\n--- Bienvenido al sistema de notas Unab ---\n\n";
    cout<<"Registrar notas manualmente (1)"<<endl;
    cout<<"Cargar archivo (2)"<<endl;
    cout<<"Solicitar nota de alumno (3)"<<endl;
    cout<<"Salir del menu (4)"<<endl;
    cout<<"\nIngrese una opcion: ";
    cin>>x;
    return x;
} // TRUE

void Profesor::cargar_file(){
    int materia,seccion, aprobado, reprobado;
    while(true){
        cout<<"\n---Bienvenido al ingreso de notas mediante archivo.txt.---\n\n";
        cout<<"Seleccione el codigo de materia que imparte:\n"<<ID[0]<<" (0)\n"<<ID[1]<<" (1)\n"<<ID[2]<<" (2)\n"<<ID[3]<<" (3)\n"<<ID[4]<<" (4)\n: ";
        cin>>materia;
        if(materia < 0 || materia > 4){
            cout<<"\nERROR INGRESAR DATOS...\n";
            break;
        }
        cout<<"\nSeleccione la seccion:\n"<<nrc[0]<<" (0)\n"<<nrc[1]<<" (1)\n"<<nrc[2]<<" (2)\n: ";
        cin>>seccion;
        if(seccion < 0 || seccion > 2){
            cout<<"\nERROR INGRESAR DATOS...\n";
            break;
        }
        else{
            string name;
            name += nrc[seccion];
            name += ID[materia];
            name += ".txt";
            ofstream fe;
            ifstream f;
            string filename;
            string nom,ape,rut2;
            cout<<"Ingrese el nombre nombre del archivo (sin .txt): ";
            cin>>filename;
            filename += ".txt";
            f.open(filename, ios::in);
            if(f.fail()){cout<<"\nEl archivo no existe...\n";break;}
            fe.open(name, fstream::app);
            while(!f.eof()){
                f>>nom>>ape>>rut2>>nt[0]>>nt[1]>>nt[2]>>nt[3];
                calcular_ND();
                if(ND >= 4){aprobado++;}
                else{reprobado++;}
                fe<<nom<<" "<<ape<<" "<<ND<<endl;
                nota_alumno(rut2, materia); 
            }
        cout<<"\nAprobados: "<<aprobado<<endl;
        cout<<"Reprobados: "<<reprobado<<endl;
        cout<<"\nRealizado :D\n";
        break;    
        }
    }
    
} // TRUE

int main() {
    int opcion;
    Profesor a;
    alumno b;
    do{
        opcion = menu();
        switch (opcion){
            case 1:
                a.crear_file();
                break;
            case 2:
                a.cargar_file();
                break;
            case 3:
                b.soli_nota();
            break;
        }
    }while (opcion != 4);
    
    return 0;
}