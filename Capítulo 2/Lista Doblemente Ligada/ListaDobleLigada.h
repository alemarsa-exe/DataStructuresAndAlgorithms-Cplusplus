#ifndef LISTADOBLELIGADA_H
#define LISTADOBLELIGADA_H

#include <iostream>
#include "DobleNodo.h"

using namespace std;
template<typename T>

class ListaDobleLigada{

    private:
        int maxCounter;

    public:
        //Primer nodo de la lista
        DobleNodo<T> *head = NULL;

        //Último nodo de la lista
        DobleNodo<T> *tail = NULL;

        ListaDobleLigada();
        DobleNodo<T> *obtener(int index);
        
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
        void imprimirReversa();
        int contar();
};

//Implementaciones aquí porque en un cpp daría error

//Constructor
template<typename T>
ListaDobleLigada<T>::ListaDobleLigada(){
    maxCounter = 0;
    head = NULL;
    tail = NULL;
}

//Obtener               // Complejidad O(1)
template<typename T>
DobleNodo<T>* ListaDobleLigada<T>::obtener(int index){
    
    //Checar que el index esté dentro de los límites
    if(index <0 || index > maxCounter){
        cout << "Index fuera de límite" << endl;
        return NULL;
    }

    //Empezar desde la cabeza
    DobleNodo<T> *nodo = head;

    //Iterar hasta encontrarlo
    for(int i=0; i<index; i++){
        nodo = nodo->siguiente;
    }

    return nodo;
}

//Buscar                // Complejidad O(n)
template<typename T>
int ListaDobleLigada<T>::buscar(T valor){

    //Checar que no esté vacía la lista
    if(maxCounter == 0){
        cout << "La lista está vacía" << endl;
        return -1;
    }

    DobleNodo<T> *nodo = head;

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

//insertarHead          // Complejidad O(1)
template<typename T>
void ListaDobleLigada<T>::insertarHead(T valor){

    //Crear nuevo nodo
    DobleNodo<T> *nodo = new DobleNodo<T>(valor);

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
void ListaDobleLigada<T>::insertarTail(T valor){

    //Ver si la lista está vacia
    if(maxCounter == 0){
        insertarHead(valor);
        return;
    }

    //Crear nuevo nodo
    DobleNodo<T> *nodo = new DobleNodo<T>(valor);

    //Hacer que tail apunte al nuevo nodo
    tail->siguiente = nodo;

    //Ahora actualizo tail
    tail = nodo;

    //Aumento el contador de la lista
    maxCounter++;
}

//insertarPorIndex      // Complejidad O(n)
template<typename T>
void ListaDobleLigada<T>::insertarPorIndex(int index, T valor){
    
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
    DobleNodo<T> *prevNodo = head;

    //Recorrer la lista para llegar al previo
    for(int i=0; i < index-1; i++){
        prevNodo = prevNodo->siguiente;
    }

    //Crear y asignar el nodo siguiente
    DobleNodo<T> *sigNodo = prevNodo->siguiente;

    //Crear nuevo nodo
    DobleNodo<T> *nodo = new DobleNodo<T>(valor);

    //Asignar el nodo a agregar
    nodo->siguiente = sigNodo;
    prevNodo->siguiente = nodo;

    //Actualizar valor máximo
    maxCounter++;

}

//Borrar Head           // Complejidad O(1)
template<typename T>
void ListaDobleLigada<T>::borrarHead(){

    //No hacer nada si la lista está vacía
    if(maxCounter == 0){
        return;
    }

    //Guardar el actual head y asignarle el siguiente nodo
    DobleNodo<T> *nodo = head;
    head = head->siguiente;
    
    //Borrar el nodo temporal
    delete nodo;

    //Asegurarse que el nodo previo de head sea NULL
    if(head != NULL){
        head->previo = NULL;
    }

    //Limpieza
    maxCounter--;
}

//Borrar Tail           // Complejidad O(1)
template<typename T>
void ListaDobleLigada<T>::borrarTail(){
    
    //Checar que la lista no esté vacía
    if(maxCounter == 0){
        cout << "La lista está vacía" << endl;
        return;
    }

    //Si solo hay un elemento, borrar Head
    if(maxCounter == 1){
        borrarHead();
        return;
    }

    //Crear un nuevo nodo temporal
    DobleNodo<T> *nodo = tail;

    //Apuntar tail al nodo previo
    tail = tail->previo;

    //Asignarle null al siguiente de tail
    tail->siguiente = NULL;

    //Limpieza
    delete nodo;
    maxCounter--;
}

//Borrar por Index      // Complejidad O(n)
template<typename T>
void ListaDobleLigada<T>::borrarPorIndex(int index){
    
    //Checar que index esté dentro del rango
    if(index < 0 || index >= maxCounter){
        cout << "Index fuera de límite" << endl;
        return;
    }

    //Checar si la lista está vacía
    if(maxCounter == 0){
        cout << "La lista está vacía" << endl;
        return;
    }

    //Si solo hay un elemento, borrar Head
    if(index == 0){
        borrarHead();
        return;
    }

    //Si se quiere eliminar el final, borrar Tail
    if(index == maxCounter-1){
        borrarTail();
        return;
    }
    
    //Crear nodos auxiliares y recorrerlos
    DobleNodo<T> *nodoABorrar = head;
    for(int i=0; i<index-1;i++){
        nodoABorrar = nodoABorrar->siguiente;
    }

    DobleNodo<T> *nodo = nodoABorrar->siguiente;
    DobleNodo<T> *sigNodo = nodo->siguiente;

    nodoABorrar->siguiente = sigNodo;

    //Borrar y disminuir counter
    delete nodo;
    maxCounter--;

}

//Contar
template<typename T>
int ListaDobleLigada<T>::contar(){
    return maxCounter;
}

//Imprimir
template<typename T>
void ListaDobleLigada<T>::imprimir(){
    DobleNodo<T> *nodo = head;
    while(nodo!=NULL){
                cout<<nodo->valor<<" -> ";
                nodo=nodo->siguiente;
            }
            cout<<"Vacío"<<endl;
}

//Imprimir reversa
template<typename T>
void ListaDobleLigada<T>::imprimirReversa(){

}
#endif