#ifndef LISTALIGADA_H
#define LISTALIGADA_H

#include <iostream>
#include "Nodo.h"

using namespace std;
template<class T>

class ListaLigada{

    private:
        int maxCounter;

    public:
        //Primer nodo de la lista
        Nodo<T> *head = NULL;

        //Último nodo de la lista
        Nodo<T> *tail = NULL;

        ListaLigada();
        Nodo<T> *obtener(int index);
        
        //Funciones de insertar
        void insertarHead(T valor);
        void insertarTail(T valor);
        void insertarPorIndex(int index, T valor);

        //Buscar
        T buscar(T valor);

        //Borrar
        void borrarHead();
        void borrarTail();
        void borrarPorIndex(int index);

        //Funciones adicionales
        void imprimir();
        int contar();

};

//Implementaciones aquí porque en un cp daría error

template<typename T>
ListaLigada<T>::ListaLigada(){
    int maxCounter = 0;
    head = NULL;
    tail = NULL;
}

template<typename T>
Nodo<T>* ListaLigada<T>::obtener(int index){
    
    //Checar que el index esté dentro de los límites
    if(index <0 || index > maxCounter){
        return NULL;
    }

    //Empezar desde la cabeza
    Nodo<T> *nodo = head;

    //Iterar hasta encontrarlo
    for(int i=0; i<index; i++){
        nodo = nodo->siguiente;
    }

    return nodo;
}

template<typename T>
int ListaLigada<T>::contar(){
    return maxCounter;
}

template<typename T>
void ListaLigada<T>::imprimir(){
    Nodo<T> *nodo = head;
    while(nodo!=NULL){
                cout<<nodo->valor<<" -> ";
                nodo=nodo->siguiente;
            }
            cout<<"NULL"<<endl;
}
#endif