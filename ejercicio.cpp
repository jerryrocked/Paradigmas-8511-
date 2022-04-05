#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string archivo1="archivo1.txt";
    ifstream archivo(archivo1.c_str());
    string linea,nomb,n1,n2,n3,n4;
    int nota1,nota2,nota3,nota4;
    int notas_curso [12];
    string nombre_curso[3];
    int res,lon,i,j=0;
    string arreglo[100];
    char b,l;
    int a=0;
    int k=0;
    int z=0;
    int x;
    int y;

    while (getline(archivo,linea)) {
        cout<<linea<<endl;
        lon = linea.length();
        for (i=0;i<lon;i++){
            l=linea[i];
            b=' ';
            if (l!=b){
                if (j==0)
                    nomb=nomb+linea[i];
                    
                if (j==1)
                    n1=n1+linea[i];
                    istringstream(n1)>>nota1; // comvertir sting en int
                    
                if (j==2)
                    n2=n2+linea[i];
                    istringstream(n2)>>nota2;
                    
                if (j==3)
                    n3=n3+linea[i];
                    istringstream(n3)>>nota3;
                    
                if (j==4)
                    n4=n4+linea[i];
                    istringstream(n4)>>nota4;
                    
            }
            else
                j++;
          
        }
      
        
        nombre_curso[k]=nomb;
        k++;
        notas_curso[a]=nota1;
        a++; 
        notas_curso[a]=nota2;
        a++; 
        notas_curso[a]=nota3;
        a++; 
        notas_curso[a]=nota4;
        a++;       

        cout<<nomb<<endl;
        cout<<n1<<endl;
        cout<<n2<<endl;
        cout<<n3<<endl;
        cout<<n4<<endl;
        

        j=0;
        nomb=" ";
        n1=" ";
        n2=" ";
        n3=" ";
        n4=" ";
        }
		double promedio = 0;
    	y = 0 ;
    	double not1,not2,not3,not4;
    	

    	while(y != sizeof(nombre_curso)/sizeof(nombre_curso[0])){
			cout<<nombre_curso[y]<<endl;	
			cout<<notas_curso[z]<<endl;
			not1 = notas_curso[z];
			z++;
			cout<<notas_curso[z]<<endl;
			not2 = notas_curso[z];
			z++;
			cout<<notas_curso[z]<<endl;
			not3 = notas_curso[z];
			z++;
			cout<<notas_curso[z]<<endl;
			not4 = notas_curso[z];
			z++;
			y++;
			promedio = (not1+not2+not3+not4)/4;
			cout << promedio << endl;
			if(promedio<4)
				cout<< " su promedio es deficiente"<< endl;

			if (promedio>=4 and promedio<5.49)
				cout<< "su promedio es regular"<< endl;

			if	(promedio>5.49 and promedio<6.49)
				cout<< "su promedio es bueno"<< endl;

			if (promedio>6.49 and promedio<=7)
				cout<< "su promedio es sobresaliente"<< endl;

		}


  }
