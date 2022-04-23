#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Lista{
    public:
        struct NodoLista{
            char Nombre[50];
            struct NodoLista *Siguiente;
        }Nodo;

        int InsertarElemento(Nodo **);
        void ListarElementos(Nodo *);
        int BorrarElementoListaFinal(Nodo **);
        int BorrarElementoListaPrincipio(Nodo **);
        int BorrarElementoIntermedio(Nodo **);
};

int Lista::InsertarElemento(Nodo**Inicio){
    Nodo *Elemento=NULL;
    Nodo *Recorrer=NULL;
    Nodo *Ultimo=NULL;

    Recorrer=*Inicio;
    while(Recorrer!=NULL){
        Ultimo=Recorrer;
        Recorrer=Recorrer->Siguiente;
    }

    Elemento=(Nodo *)malloc(sizeof(Nodo));

    if(Elemento==NULL){
        return -1
    }
    cout<<"Teclear Nombre: "<<endl;
    cin>>Elemento->Nombre;

    Elemento->Siguiente=NULL;

    if(Ultimo==NULL){
        *Inicio=Elemento;
    }
    else{
        Ultimo->Siguiente=Elemento;
    }
    
    return 0;
}

void Lista::ListarElementos(Nodo *Inicio){
    Nodo *Recorrer =Inicio;
    cout<<"LISTADO DE ELEMENTOS DE LA LISTA"<<endl;
    cout<<"================================="<<endl;

    while(Recorrer!=NULL){
        cout<<Recorrer->Nombre;

        Recorrer=Recorrer->Siguiente;
    }
    cout<<"============================================"<<endl;
}

int Lista::BorrarElementoListaPrincipio(Nodo **Inicio){
    Nodo *Borrar=NULL;
    if(*Inicio==NULL){
        cout<<"NO HAY ELEMENTOS QUE BORRAR"<<endl;
        return -1;
    }
    else{
        Borrar=*Inicio;
        *Inicio=(*Inicio)->Siguiente;
        free(Borrar);
    }
    return 0;
}

int Lista::BorrarElementoListaFinal(Nodo **Inicio){
    Nodo *Borrar=NULL;
    Nodo *Recorrer=NULL;
    Recorrer=*Inicio;
    if(Recorrer==NULL){
        cout<<"NO EXISTEN ELEMENTOS QUE BORRAR"<<endl;
        return -1;
    }
    while(Recorrer->Siguiente!=NULL){
        Borrar = Recorrer;
        Recorrer= Recorrer->Siguiente;
    }
    if(Borrar==NULL) {
        Borrar = *Inicio;
        *Inicio = NULL;
        free (Borrar);
    }
    else{
        free(Borrar->Siguiente);
        Borrar->Siguiente=NULL;
   }
    return 0;
}

int Lista::BorrarElementoIntermedio(Nodo **Inicio){
    Nodo *Recorrer=NULL;
    Nodo *Borrar=NULL;
    Nodo *Anterior=NULL;

    char NombreBuscar[30];
    int encontrado=0;
    cout<<"Nombre a Eliminar: "<<endl;
    cin>>NombreBuscar;

    if(*Inicio==NULL){
        cout<<"NO HAY ELEMENTOS QUE BORRAR"<<endl;
        return -1;
    }
    else{
        cout<<"Buscando: ..."<<NombreBuscar<<endl;
        Recorrer = *Inicio;
        Anterior = *Inicio;
        while(Recorrer!=NULL && encontrado==0){
            cout<<".";
            if(strcmp(Recorrer->Nombre,NombreBuscar)==0){
                cout<<"(ENCONTRADO OK)"<<endl;
                encontrado=1;
                Borrar=Recorrer;
                if(Recorrer==*Inicio){
                    *Inicio = Recorrer->Siguiente;
                }
                else{
                    Anterior->Siguiente = Borrar->Siguiente;
                }
                free(Borrar);
            }
            else{
                Anterior = Recorrer;
                Recorrer=Recorrer->Siguiente;
            }
        }
    }
    return 0;
}

//PROGRAMA PRINCIPAL

int main(){
    Lista list;
    Lista::Nodo *Inicio = NULL;
    int opcion=0;
    int opcion2=0;
    
    do{
        cout<<"1.- Insertar elemento en la lista."<<endl;
        cout<<"1.- Listar elementos de la lista."<<endl;
        cout<<"1.- Borrar elemento de la lista."<<endl;
        cout<<"1.- Salir del programa."<<endl;
        cout<<"1.- Insertar elemento en la lista."<<endl;
        cout<<"====================================="<<endl;
        cout<<"Opcion ...: "<<endl;
        cin>>opcion;

        switch(opcion){
            case 1:
                list.InsertarElemento(&Inicio);
                break;
            case 2:
                list.ListarElementos(Inicio);
                break;
            case 3:
                cout<<"(0) Volver Menu Anterior."<<endl;
                cout<<"(1) Borrar al final."<<endl;
                cout<<"(2) Borrar al principio."<<endl;
                cout<<"(3) Borrar Intermedio."<<endl;
                cout<<"Opcion ...: "<<endl;
                cin>>opcion2;

                switch(opcion2){
                    case 1:
                        list.BorrarElementoListaFinal(&Inicio);
                        break;
                    case 2:
                        list.BorrarElementoListaPrincipio(&Inicio);
                        break;
                    case 3:
                        list.BorrarElementoIntermedio(&Inicio);
                        break;
                }
                break;
        }
    }
    while(opcion!=0){
        system("PAUSE");

    }
    return 0;
}