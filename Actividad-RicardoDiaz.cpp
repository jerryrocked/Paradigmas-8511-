//#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

typedef struct NodoLista {
  char Nombre[50];
  struct NodoLista *Siguiente;
} Nodo;

int InsertarElemento(Nodo **);
void ListarElementos(Nodo *);
int BorrarElementoListaFinal(Nodo **);
int BorrarElementoListaPrincipio(Nodo **);
int BorrarElementoIntermedio(Nodo **);

int main(int argc, char *argv[]){
    Nodo *Inicio = NULL;
    int opcion=0;
    int opcion2=0;
    do {
        cout<<"\n1.- Insertar elemento en la lista.";
        cout<<"\n2.- Listar elementos de la lista.";
        cout<<"\n3.- Borrar elemento de la lista.";
        cout<<"\n0.- Salir del programa.";
        cout<<"\n=====================================";
        cout<<"\nOpcion ...: ";
        cin>>opcion;
        switch(opcion) {
          case 1:
               InsertarElemento(&Inicio);
               break;
          case 2:
               ListarElementos(Inicio);
               break;
          case 3: 
               cout<<"\n(0) Volver Menu Anterior.";
               cout<<"\n(1) Borrar al final.";
               cout<<"\n(2) Borrar al principio.";
               cout<<"\n(3) Borrar Intermedio.";
               cout<<"\n.... ";
               cin>>opcion2;
               switch(opcion2) {
                 case 1:
                      BorrarElementoListaFinal(&Inicio);
                      break;
                 case 2:
                      BorrarElementoListaPrincipio(&Inicio);
                      break;
                 case 3:
                      BorrarElementoIntermedio(&Inicio);
                      break;
               }
               break;
        }
    } while(opcion!=0);
  system("PAUSE" );
  return 0;
}

int InsertarElemento(Nodo **Inicio){
     Nodo *Elemento = NULL;
     Nodo *Recorrer = NULL;
     Nodo *Ultimo = NULL;
     Recorrer = *Inicio;
     while(Recorrer!=NULL) {
       Ultimo = Recorrer;
       Recorrer=Recorrer->Siguiente;
     }
     Elemento = new Nodo;
     if(Elemento == NULL ) return -1;
     //cin.ignore();
     cout<<"\nTeclear Nombre : ";
     cin>>Elemento->Nombre;
     Elemento->Siguiente = NULL;
     if (Ultimo == NULL ) {
        *Inicio = Elemento;
     } else {
       Ultimo->Siguiente = Elemento;
     }
     return 0;
}


void ListarElementos(Nodo *Inicio){ 
     Nodo *Recorrer = Inicio;
     cout<<"\nListado de elementos de la lista";
     cout<<"\n===================================";
     while(Recorrer!=NULL){
        cout<<"\n "<<Recorrer->Nombre;
        Recorrer=Recorrer->Siguiente;
     }
     cout<<"\n===================================\n";
}

int BorrarElementoListaPrincipio(Nodo **Inicio){ 
    Nodo *Borrar=NULL;
    if (*Inicio==NULL) {
       cout<<"\nNo hay elementos que borrar\n";
       return -1;
    } else {
      Borrar = *Inicio;
      *Inicio = (*Inicio)->Siguiente;
      delete(Borrar);
    }
    return 0;
}

int BorrarElementoListaFinal(Nodo **Inicio)
{
    Nodo *Borrar=NULL;;
    Nodo *Recorrer=NULL;
    Recorrer=*Inicio;
    if(Recorrer==NULL) {
     cout<<"\nNo existen elementos que borrar\n";
     return -1;
    }
    while(Recorrer->Siguiente!=NULL) {
      Borrar = Recorrer;
      Recorrer= Recorrer->Siguiente;
    }
   if(Borrar==NULL) {
       Borrar = *Inicio;
      *Inicio = NULL;
      delete(Borrar);
   } else {
     delete(Borrar->Siguiente);
     Borrar->Siguiente=NULL;
   }
    return 0;
}



int BorrarElementoIntermedio(Nodo **Inicio){
    Nodo *Recorrer=NULL;
    Nodo *Borrar=NULL;
    Nodo *Anterior=NULL;
    char NombreBuscar[30];
    int encontrado=0;
    cout<<"\nNombre a eliminar: ";
    cin>>NombreBuscar;
    if (*Inicio==NULL) {
       cout<<"\nNo hay elementos que borrar\n";
       return -1;
    } else {
        cout<<"\nBuscando: "<<NombreBuscar;
        Recorrer = *Inicio;
        Anterior = *Inicio;
        while(Recorrer!=NULL && encontrado==0)
        {
            cout<<".";
            if(strcmp(Recorrer->Nombre,NombreBuscar)==0) {
                cout<<" (Encontrado Ok)\n";
                encontrado=1;
                Borrar = Recorrer;
                if(Recorrer==*Inicio) {
                    *Inicio = Recorrer->Siguiente;
                } else {
                    Anterior->Siguiente = Borrar->Siguiente;
                }
                delete(Borrar);
            } else {
                Anterior = Recorrer;
                Recorrer=Recorrer->Siguiente;
            }
        }
    }
    return 0;
}


