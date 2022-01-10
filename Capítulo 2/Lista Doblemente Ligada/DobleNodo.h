#ifndef DOBLENODO_H
#define DOBLENODO_H

#include<iostream>
using namespace std;
template<typename T>

class DobleNodo{

    public:
        T valor;
        Nodo<t> *previo = NULL;
        Nodo<T> *siguiente = NULL;

        DobleNodo(T valor);
};

//Esto es importante. Mi código no compilaba por no tener esto de abajo
template<typename T>
DobleNodo<T>::DobleNodo(T valor){
    this->valor = valor;
    this->previo = NULL;
    this->siguiente = NULL;
}


#endif