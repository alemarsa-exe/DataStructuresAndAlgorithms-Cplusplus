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
        int buscar(T valor);

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
    maxCounter = 0;
    head = NULL;
    tail = NULL;
}

//Obtener               // Complejidad O(1)
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

//insertarHead          // Complejidad O(1)
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

//insertarTail          // Complejidad O(1)
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

//insertarPorIndex      // Complejidad O(n)
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
        return;
    }

    //Asignar el nodo anterior
    Nodo<T> *prevNodo = head;

    //Recorrer la lista para llegar al previo
    for(int i=0; i < index-1; i++){
        prevNodo = prevNodo->siguiente;
    }

    //Crear y asignar el nodo siguiente
    Nodo<T> *sigNodo = prevNodo->siguiente;

    //Crear nuevo nodo
    Nodo<T> *nodo = new Nodo<T>(valor);

    //Asignar el nodo a agregar
    nodo->siguiente = sigNodo;
    prevNodo->siguiente = nodo;

    //Actualizar valor máximo
    maxCounter++;

}

//Buscar                // Complejidad O(n)
template<typename T>
int ListaLigada<T>::buscar(T valor){

    //Checar que no esté vacía la lista
    if(maxCounter == 0){
        cout << "La lista está vacía" << endl;
        return -1;
    }

    Nodo<T> *nodo = head;

    int index = 0;
    while(nodo->valor != valor){
        index++;
        nodo = nodo->siguiente;

        if(nodo == NULL){
            cout << "El nodo con el valor " << valor << " no se ha encontrado."<<endl;
            return -1;
        }
    }

    cout << "Se encontró el nodo con el valor " << valor <<  " en la posición " << index << "."<<endl;
    return index;

}

//Borrar Head           // Complejidad O(1)
template<typename T>
void ListaLigada<T>::borrarHead(){

    //No hacer nada si la lista está vacía
    if(maxCounter == 0){
        return;
    }

    //Crear nuevo nodo y asignarle el siguiente de head
    Nodo<T> *sigNodo = head;
    head = head->siguiente;
    

    delete sigNodo;
    maxCounter--;
}

//Borrar Tail
template<typename T>
void ListaLigada<T>::borrarTail(){
    
    //Checar que la lista no esté vacía
    if(maxCounter == 0){
        cout << "La lista está vacía" << endl;
        return;
    }

    //Si solo hay un elemento, borrar Head
    if(maxCounter == 1){
        borrarHead();
    }

    //Crear un nuevo nodo temporal
    Nodo<T> *segundoNodo = head;

    //Llevarlo al nodo que se convertirá en tail
    for(int i=0; i<maxCounter-2;i++){
        segundoNodo = segundoNodo->siguiente;
    }

    //Asignarle null al siguiente
    segundoNodo->siguiente = NULL;

    tail = segundoNodo;
    
    maxCounter--;
}

//Borrar por Index
template<typename T>
void ListaLigada<T>::borrarPorIndex(int index){
    
    //Checar si la lista está vacía
    if(maxCounter == 0){
        cout << "La lista está vacía" << endl;
        return;
    }

    //Si solo hay un elemento, borrar Head
    if(maxCounter == 1){
        borrarHead();
    }

    //Si se quiere eliminar el final, borrar Tail
    if(index == maxCounter){
        borrarTail();
    }

    //Crear nodos auxiliares
    Nodo<T> *nodoABorrar = head;
    Nodo<T> *sigNodo = nodoABorrar->siguiente;
    
    for(int i=0; i<index;i++){
        nodoABorrar = nodoABorrar->siguiente;
        sigNodo = sigNodo->siguiente;
    }

    nodoABorrar->siguiente = sigNodo;

    //delete nodoABorrar;
    maxCounter--;

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
            cout<<"Vacío"<<endl;
}
#endif