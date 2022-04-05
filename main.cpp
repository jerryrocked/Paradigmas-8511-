#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <charconv>
#include <string>

using namespace std;
//Guillermo Diaz Adasme 
//20.918.032-4


int main() {
  string archivo1="archivo1.txt";
  ifstream archivo(archivo1.c_str());
  string  linea,nomb,n1,n2,n3,n4;
  int posicion,res,lon,i,j= 0,a=0;
  string arreglo[7];
  char b,l;
  string a1,a2,a3,a4;
  float arreglo2[7],promedio;
  nomb=" ";
  n1=" ";
  n2=" ";
  n3=" ";
  n4=" ";
  while (getline(archivo,linea)){
    lon=linea.length();
    for(i=0;i<lon;i++){
      l=linea[i];
      b=' ';
      if(l!=b){
        if(j==0)
          nomb=nomb+linea[i];
           
        if(j==1)
           n1=n1+linea[i];
           a1=n1;
           

          
           
        if(j==2)
           n2=n2+linea[i];
           a2=n2;
           
        if(j==3)
           n3=n3+linea[i];
           a3=n3;
           
        if(j==4)
           n4=n4+linea[i];
           a4=n4;
           arreglo[a]=nomb+n1+n2+n3+n4;
           
           
          
      }
      else
        j++;
    }
    cout<<nomb<<n1<< n2<<n3<<n4<<endl;
    //Transforma numero reales
    float b1 = stold(a1);
    float b2 = stold(a2);
    float b3 = stold(a3);
    float b4 = stold(a4);
    promedio=(b1+b2+b3+b4)/4;
    arreglo2[a]=promedio;
    //cout<<"El promedio es: "<<promedio<<endl;
    a++;
    j=0;
    nomb=" ";
    n1=" ";
    n2=" ";
    n3=" ";
    n4=" "; 
  }
 
cout<<"Que posicion del arreglo desea mostrar de 0 a 6: ";cin>>posicion; 
if(posicion==0){
  cout<<arreglo[0]<<endl;
  cout<<"El promedio es: "<<arreglo2[0]<<endl;

}
if(posicion==1){
  cout<<arreglo[1]<<endl;
  cout<<"El promedio es: "<<arreglo2[1]<<endl;

}
if(posicion==2){
  cout<<arreglo[2]<<endl;
  cout<<"El promedio es: "<<arreglo2[2]<<endl;

}
if(posicion==3){
  cout<<arreglo[3]<<endl;
  cout<<"El promedio es: "<<arreglo2[3]<<endl;

}
if(posicion==4){
  cout<<arreglo[4]<<endl;
  cout<<"El promedio es: "<<arreglo2[4]<<endl;

}
if(posicion==5){
  cout<<arreglo[5]<<endl;
  cout<<"El promedio es: "<<arreglo2[5]<<endl;

}
if(posicion==6){
  cout<<arreglo[6]<<endl;
  cout<<"El promedio es: "<<arreglo2[6]<<endl;

}

}
