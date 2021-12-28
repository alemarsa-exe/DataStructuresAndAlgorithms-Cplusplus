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



#endif