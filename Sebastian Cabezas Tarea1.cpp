#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
#include <map>
//#include <cstream>
using namespace std;

float p1,p2,p3,p4,P;


int main() {
  float Promedio[7];
  string archivo1 = "archivo1.txt";
  ifstream archivo(archivo1.c_str());
  string line,name,N1,N2,N3,N4;
  int res, lon, i, j=0,contador=0;
  string arreglo[100];
  char b, l;
  string s1,s2,s3,s4;
  name=' ';
  N1=' ';
  N2=' ';
  N3=' ';
  N4=' ';

  while (getline(archivo, line)) {
    //cout << linea << endl;
    lon=line.length();
    for (i=0; i < lon; i++) {
      l = line[i];
      b = ' ';
      if(l!=b){
      if(j==0)
        name=name+line[i];
        //string y=nombre;   
      if(j==1)
        N1=N1+line[i];
        s1=N1;
        //float a1;
        //p1 = stold(a1);
        
      if(j==2)
        N2=N2+line[i];
        s2=N2;
        //float a2;
        //p2 = stold(a2);
        //P=(p1+p2);
        
      if(j==3)
        N3=N3+line[i];
        //arreglo[x]=N3;
        //x++;
        s3=N3;
      if(j==4)
        N4=N4+line[i];
        //arreglo[x]=N4;
        s4=N4;
        arreglo[contador]=name+N1+N2+N3+N4;
      }
      else
        j++;
    }
    
  /*
  cout<<nombre<<endl;
  cout<<N1<<endl;
  cout<<N2<<endl;
  cout<<N3<<endl;
  cout<<N4<<endl;
  */
  //cout<<a2;
  float p1 = stold(s1);
  float p2 = stold(s2);
  float p3 = stold(s3);
  float p4 = stold(s4);
  //cout<<p1<<p2<<endl;
  P=(p1+p2+p3+p4)/4;
  Promedio[contador]=P;
  //cout<<"El promedio "<<P<<endl;
  contador++;
  j=0;
  name=' ';
  N1=' ';
  N2=' ';
  N3=' ';
  N4=' ';
    
  }
  //cout<<Promedio[0];

  
  int key;
  cout<<"Elije el alumno de 0 a 6: ";
  cin>>key;
  switch(key){
  case 0:
    cout<<arreglo[0]<<endl;
    cout<<Promedio[0]<<endl;
    break;
  case 1:
    cout<<arreglo[1]<<endl;
    cout<<"El promedio "<<Promedio[1]<<endl;
    break;
  case 2:
    cout<<arreglo[2]<<endl;
    cout<<"El promedio "<<Promedio[2]<<endl;
    break;
  case 3:
    cout<<arreglo[3]<<endl;
    cout<<"El promedio "<<Promedio[3]<<endl;
    break;
  case 4:
    cout<<arreglo[4]<<endl;
    cout<<"El promedio "<<Promedio[4]<<endl;
    break;
  case 5:
    cout<<arreglo[5]<<endl;
    cout<<"El promedio "<<Promedio[5]<<endl;
    break;
  case 6:
    cout<<arreglo[6]<<endl;
    cout<<"El promedio "<<Promedio[6]<<endl;
    break;
  }
  

}