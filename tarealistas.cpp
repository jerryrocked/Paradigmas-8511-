#include <stdio.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
/*hector pacheco 
20401541-4
*/
class lista{
    public:
    typedef struct NodoLista{
    char nombre [50];
    struct NodoLista *Siguiente;


} Nodo;


  int InsertarElemento(Nodo **);

  void ListarElementos(Nodo *);

  int BorrarElementoListaFinal(Nodo **);

  int BorrarElementoListaPrincipio(Nodo **);

  int BorrarElementoIntermedio(Nodo **);

};
int main(int argc, char *argv[]){
  lista per;
    lista::Nodo *Inicio = NULL;
    int opcion=0;
    int opcion2=0;

    do {
        cout<<"\nBIENVENIDOS A CREAR LISTAS :)";
        cout<<"\n1.- Insertar elemento en la lista.";
        cout<<"\n2.- Listar elementos de la lista.";
        cout<<"\n3.- Borrar elemento de la lista.";
        cout<<"\n0.- Salir del programa.";
        cout<<"\n =====================================";
        cout<<"\n Opcion : ";
        cin>>opcion;
        switch(opcion) {

          case 1:            
            per.InsertarElemento(&Inicio);
            break;

          case 2:
            per.ListarElementos(Inicio);
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
                  per.BorrarElementoListaFinal(&Inicio); 
                  break;

                 case 2:
                   
                    per.BorrarElementoListaPrincipio(&Inicio);
                    break;
                 case 3:
                    per.BorrarElementoIntermedio(&Inicio);
                    break;
               }
               break;
        }
    } while(opcion!=0);
  system("PAUSE" );
  return 0;

}

int lista::InsertarElemento(Nodo **Inicio)
{
     Nodo *Elemento = NULL;
     Nodo *Recorrer = NULL;
     Nodo *Ultimo = NULL;
     
     Recorrer = *Inicio;
     while(Recorrer!=NULL) {
       Ultimo = Recorrer;
       Recorrer=Recorrer->Siguiente;
     }
     
     Elemento = (Nodo *)malloc(sizeof(Nodo));
     
     if(Elemento == NULL ) return -1;
     
     cout<<"\nTeclear Nombre : ";
     cin>>Elemento->nombre;
    
     Elemento->Siguiente = NULL;
    
     if (Ultimo == NULL ) {
        
        *Inicio = Elemento;
     } else {
       
       Ultimo->Siguiente = Elemento;
     }
   
     return 0;
}


void lista::ListarElementos(Nodo *Inicio)
{
    
     Nodo *Recorrer = Inicio;
     
     cout<<"\nListado de elementos de la lista:";
     cout<<"\n";
    
     while(Recorrer!=NULL)
     {
        cout<<endl;
        cout<<Recorrer->nombre<<endl;
       
        Recorrer=Recorrer->Siguiente;
     }
     cout<<"\n===================================\n";
}

int lista::BorrarElementoListaPrincipio(Nodo **Inicio)
{
    
    Nodo *Borrar=NULL;
    
    if (*Inicio==NULL) {
       cout<<"\nNo hay elementos que borrar\n";
       return -1;
    } else {
      Borrar = *Inicio;
      *Inicio =(*Inicio)->Siguiente;
      free (Borrar);
    }
    return 0;
}

int lista::BorrarElementoListaFinal(Nodo **Inicio)
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
      free (Borrar);
   } else {
     free(Borrar->Siguiente);
     Borrar->Siguiente=NULL;
   }
    return 0;
}


int lista::BorrarElementoIntermedio(Nodo **Inicio)
{
    
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
        
        cout<<"\n Buscando: "<<NombreBuscar;
        Recorrer = *Inicio;
        Anterior = *Inicio;
        while(Recorrer!=NULL && encontrado==0)
        {
            
            cout<<".";
            if(strcmp(Recorrer->nombre,NombreBuscar)==0) {
                cout<<" (Encontrado Ok)\n";
                encontrado=1;
                Borrar = Recorrer;
                if(Recorrer==*Inicio) {
                    *Inicio = Recorrer->Siguiente;
                } else {
                    Anterior->Siguiente = Borrar->Siguiente;
                }
                free(Borrar);
            } else {
                
                Anterior = Recorrer;
                Recorrer=Recorrer->Siguiente;
            }
        }
    }
    return 0;
}


