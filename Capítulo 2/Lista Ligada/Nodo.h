#ifndef NODO_H
#define NODO_H

#include<iostream>
using namespace std;
template<typename T>

class Nodo{

    public:
        int valor;
        Nodo<T> *siguiente = NULL;

        Nodo(T valor);
};

//Esto es importante. Mi código no compilaba por no tener esto de abajo
template<typename T>
Nodo<T>::Nodo(T valor){
    this->valor = valor;
    this->siguiente = NULL;
}


#endif