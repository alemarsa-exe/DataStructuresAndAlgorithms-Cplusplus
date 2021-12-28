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
        Nodo<T> *getHead(int index);
        
        //Funciones de insertar
        void insertHead(T valor);
        void insertTail(T valor);
        void insertar(int index, T valor);



};



#endif