#include <iostream>
#include <string.h>
#include <fstream>  //Primordial para extraer el archivo
#include <vector>
//#include <cstream>  //funciones de caracteres
using namespace std;

void NotasAlArreglo(float nota,vector<float>notas){
  notas.push_back(nota);
  for(int i=notas.size()-1;i>=0;i++){
    cout<<notas[i]<<" ";
    //return notas[i];
  }
} // No me funciono esta funcion :(

int main(){
  string archivo1="archivo1.txt";
  ifstream archivo(archivo1.c_str()); //extraer el archivo txt
  string linea,nomb,n1,n2,n3,n4;  
  int res,lon,i,j=0;  //lon = longitud
  vector<float>notas;
  float notauno,notados,notatres,notacuatro;
  string arreglo[100];
  char b,l;  

  while(getline(archivo,linea)){ // extraer linea por linea
    //cout<<linea<<endl;         //muestra la linea completa
    lon = linea.length();        //longitud de linea
    for(i=0;i<lon;i++){
      l=linea[i]; //extraer el primer caracter
      b=' ';  //colocar un "blanco"
      if(l!=b){      // si la letra, es diferente al caracter blanco...
        if(j==0){    //extraer el nombre
          nomb=nomb+linea[i];
        }
        if(j==1){    //extraer nota 1
          n1=n1+linea[i];
          notauno=stof(n1); //cambio de tipo string a float
          NotasAlArreglo(notauno,notas);
          
        }
        if(j==2){    //extraer nota 2
          n2=n2+linea[i];
          notados=stof(n2);
          NotasAlArreglo(notados,notas);
        }
        if(j==3){    //extraer nota 3
          n3=n3+linea[i];
          notatres=stof(n3);
          NotasAlArreglo(notatres,notas);
        }
        if(j==4){    //extraer nota 4
          n4=n4+linea[i];
          notacuatro=stof(n4);
          NotasAlArreglo(notacuatro,notas);
        }
      }
      else{
        j++; //cuando l==b, j aumenta su valor y vuelve a repetir el ciclo
      }
    }
    /*cout<<nomb<<endl;
    cout<<n1<<endl;
    cout<<n2<<endl;
    cout<<n3<<endl;
    cout<<n4<<endl;*/
    cout<<"--------"<<endl;
    cout<<notauno<<endl;
    cout<<notados<<endl;
    cout<<notatres<<endl;
    cout<<notacuatro<<endl;
    j=0;nomb=' ';n1=' ';n2=' ';n3=' ';n4=' ';
  }
}