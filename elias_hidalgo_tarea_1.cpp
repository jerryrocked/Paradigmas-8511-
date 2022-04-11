#include <iostream>
#include <string.h>
#include <fstream>
//#include <cstream>
using namespace std;

int main() {
    string archivo1="archivo1.txt";
    ifstream archivo(archivo1.c_str());
    string linea,nomb,n1,n2,n3,n4;
    int res,lon,i,j=0;
    string arreglo[100];
    char b,l;

    while(getline(archivo,linea)){//leer linea por linea
        cout<<linea<<endl;
        lon=linea.length();
        for(i=0;i<lon;i++){
            l=linea[i];
            b=' ';
            if (l!=b){//preguntar si la letra es diferente de blanco
                if(j==0)
                    nomb=nomb+linea[i];
                if(j==1)
                    n1=n1+linea[i];
                if(j==2)
                    n2=n2+linea[i];
                if(j==3)
                    n3=n3+linea[i];
                if(j==4)
                    n4=n4+linea[i];
            }
            else
                j++;
        }
        cout<<nomb<<endl;
        cout<<n1<<endl;
        cout<<n2<<endl;
        cout<<n3<<endl;
        cout<<n4<<endl;
        j=0;
        nomb="";
        n1="";
        n2="";
        n3="";
        n4="";
        }
    }
