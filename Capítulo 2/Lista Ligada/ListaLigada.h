#ifndef LISTALIGADA_H
#define LISTALIGADA_H

#include <iostream>
#include "Nodo.h"

using namespace std;
template<typename T>

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

//Constructor
template<typename T>
ListaLigada<T>::ListaLigada(){
    int maxCounter = 0;
    head = NULL;
    tail = NULL;
}

//Obtener          // Complejidad O(1)
template<typename T>
Nodo<T>* ListaLigada<T>::obtener(int index){
    
    //Checar que el index esté dentro de los límites
    if(index <0 || index > maxCounter){
        cout << "Index fuera de límite" << endl;
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

//insertarHead     // Complejidad O(1)
template<typename T>
void ListaLigada<T>::insertarHead(T valor){

    //Crear nuevo nodo
    Nodo<T> *nodo = new Nodo<T>(valor);

    //Como el nodo actual va a sustituir a head,
    //nuestro nodo va a apuntar a head.
    nodo->siguiente = head;

    //El nuevo nodo se convertirá en head
    head = nodo;

    //Si la lista tiene un solo elemento, 
    //tail también es head.
    if(maxCounter == 0){
        tail = head;
    }

    //Actualiza tamaño de lista
    maxCounter++;
}

//insertarTail     // Complejidad O(1)
template<typename T>
void ListaLigada<T>::insertarTail(T valor){

    //Ver si la lista está vacia
    if(maxCounter == 0){
        insertarHead(valor);
        return;
    }

    //Crear nuevo nodo
    Nodo<T> *nodo = new Nodo<T>(valor);

    //Hacer que tail apunte al nuevo nodo
    tail->siguiente = nodo;

    //Ahora actualizo tail
    tail = nodo;

    //Aumento el contador de la lista
    maxCounter++;
}

//insertarPorIndex
template<typename T>
void ListaLigada<T>::insertarPorIndex(int index, T valor){
    
    //Checar que esté dentro de los límites
    if(index < 0 || index > maxCounter){
        cout << "Index fuera de límite" << endl;
        return;
    }
    //Por si tratas de agregar en índice 0
    if(index == 0){
        insertarHead(valor);
        return;
    }
    //Por si tratas de agregar al final
    if(index == maxCounter){
        insertarTail(valor);
    }

    //Crear nuevos nodos
    Nodo<T> *nodo = new Nodo<T>(valor);
    Nodo<T> *prevNodo = new Nodo<T>;
    Nodo<T> *sigNodo = new Nodo<T>;

    //
}

//Contar
template<typename T>
int ListaLigada<T>::contar(){
    return maxCounter;
}

//Imprimir
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