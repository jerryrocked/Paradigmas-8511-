#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <cstdio>

using namespace std;
fstream f;

/*
-	Convertir las notas a un valor del tipo real
-	Los registros de los estudiantes almacenarlos en Arreglos
*/

class alumno{
   public:
        string alumnos[50];
        float NDS[50];
        char nombre[50];
        float ND,n1,n2,n3,n4; // ND y notas alumno
        int cant_alumnos;
    void open_file();
};

void alumno::open_file()
{
    f.open("archivo1.txt", ios::in); // abre archivo
    if(f.fail()){cout<<"file error";system("pause");}// error archivo
    f.is_open();
    int i = 0;
    while(!f.eof()){
        f>>nombre>>n1>>n2>>n3>>n4; // guarda las variables
        ND = n1+n2+n3+n4; // calcula el promedio
        ND = ND / 4;

        alumnos[i] = nombre;
        NDS[i] = ND;
        if(i<cant_alumnos){
            cout<<alumnos[i]<<": "<<NDS[i]<<endl;
            i++;
        }
    }
    f.close(); // cierra archivo
}

int main()
{
    alumno a;
    cout<<"Ingrese cantidad alumnos a procesar: ";
    cin>>a.cant_alumnos;
    cout<<"\nNombre y promedio del alumno: \n";
    a.open_file();
  
    return 0;    
}