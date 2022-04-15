#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class nodo{		//clase requerida

	
	public:		
	
	typedef struct NodoLista {

	char Nombre[50];

  	struct NodoLista *Siguiente;

}Nodo;
	
	nodo();
	~nodo();
	//metodos
	int InsertarElemento(Nodo **);
	void ListarElementos(Nodo *);
	int BorrarElementoListaFinal(Nodo **);
	int BorrarElementoListaPrincipio(Nodo **);
	int BorrarElementoIntermedio(Nodo **);

    
} Nodo;


//principalmente se cambiaron los printf a cout y los scanf a cin o getline respectivamente


int nodo::InsertarElemento(Nodo **Inicio)
{
     Nodo *Elemento = NULL;
     Nodo *Recorrer = NULL;
     Nodo *Ultimo = NULL;
     
     Recorrer = *Inicio;
     while(Recorrer!=NULL) {
       Ultimo = Recorrer;
       Recorrer=Recorrer->Siguiente;
     }
     
     Elemento = (Nodo *)new(sizeof(Nodo));		//malloc transformado a new
     
     if(Elemento == NULL ) return -1;
     
     cout<<"\nTeclear Nombre : "<<endl;
     getline(cin,Elemento->Nombre);
    
     Elemento->Siguiente = NULL;
    
     if (Ultimo == NULL ) {
        
        *Inicio = Elemento;
     } else {
       
       Ultimo->Siguiente = Elemento;
     }
   
     return 0;
};


void nodo::ListarElementos(Nodo *Inicio)
{
    
     Nodo *Recorrer = Inicio;
     
     cout<<"\nListado de elementos de la lista"<<endl;
     cout<<"\n==================================="<<endl;
     
     while(Recorrer!=NULL)
     {
        
        cout<<"\n%s",Recorrer->Nombre<<endl;
       
        Recorrer=Recorrer->Siguiente;
     }
     cout<<"\n===================================\n"<<endl;
};

int nodo::BorrarElementoListaPrincipio(Nodo **Inicio)
{
    
    Nodo *Borrar=NULL;
    
    if (*Inicio==NULL) {
       cout<<"\nNo hay elementos que borrar\n"<<endl;
       return -1;
    } else {
      Borrar = *Inicio;
      *Inicio = (*Inicio)->Siguiente;
      free (Borrar);
    }
    return 0;
};

int nodo::BorrarElementoListaFinal(Nodo **Inicio)
{
    Nodo *Borrar=NULL;;
    Nodo *Recorrer=NULL;
    Recorrer=*Inicio;
    if(Recorrer==NULL) {
     cout<<"\nNo existen elementos que borrar\n"<<endl;
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
};


int nodo::BorrarElementoIntermedio(Nodo **Inicio)
{
    
    Nodo *Recorrer=NULL;
    Nodo *Borrar=NULL;
    Nodo *Anterior=NULL;
    
    char NombreBuscar[30];
    int encontrado=0;
    
    cout<<"\nNombre a eliminar: "<<endl;
    getline(cin,NombreBuscar);
   
    if (*Inicio==NULL) {
       cout<<"\nNo hay elementos que borrar\n"<<endl;
       return -1;
    } else {
        
        cout<<"\nBuscando: %s ",NombreBuscar<<endl;
        Recorrer = *Inicio;
        Anterior = *Inicio;
        while(Recorrer!=NULL && encontrado==0)
        {
            
            cout<<"."<<endl;
            if(strcmp(Recorrer->Nombre,NombreBuscar)==0) {
                cout<<" Encontrado Ok"<<endl;
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
};




int main(){
    nodo n;		//inicializacion 
    Nodo *Inicio = NULL;
    int opcion=0;
    int opcion2=0;

    do {
        cout<<"\n1.- Insertar elemento en la lista."<<endl;
        cout<<"\n2.- Listar elementos de la lista."<<endl;
        cout<<"\n3.- Borrar elemento de la lista."<<endl;
        cout<<"\n0.- Salir del programa."<<endl;
        cout<<"\n====================================="<<endl;
        cout<<"\nOpcion ...: "<<endl;
        cin>>&opcion;
        switch(opcion) {

          case 1:
            n.InsertarElemento(&Inicio);
               break;

          case 2:
               n.ListarElementos(Inicio);
               break;
          case 3:
               cout<<"\n(0) Volver Menu Anterior."<<endl;
               cout<<"\n(1) Borrar al final."<<endl;
               cout<<"\n(2) Borrar al principio."<<endl;
               cout<<"\n(3) Borrar Intermedio."<<endl;
               cout<<"\n.... "<<endl;
               cin>>&opcion2;

               switch(opcion2) {

                 case 1:
					n.BorrarElementoListaFinal(&Inicio);

                      break;

                 case 2:

                      n.BorrarElementoListaPrincipio(&Inicio);

                      break;
                 case 3:

                      n.BorrarElementoIntermedio(&Inicio);
                      break;
               }
               break;
        }
    } while(opcion!=0);
  system("PAUSE" );
  return 0;

}
