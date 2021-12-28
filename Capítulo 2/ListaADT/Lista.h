#ifndef LISTA_H
#define LISTA_H

#include <iostream>

class Lista{

    private:
        int maximo;
        int *maxItems;

    public:
        Lista();
        ~Lista();
        
        void setMaximo(int valor);
        int getMaximo();

        int obtener(int index);
        void insertar(int index, int valor);
        int buscar(int valor);
        void eliminarPorIndex(int index);

        void imprimir();


};

#endif