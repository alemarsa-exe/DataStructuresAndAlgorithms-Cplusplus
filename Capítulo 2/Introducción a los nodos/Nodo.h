#ifndef NODO_H
#define NODO_H

#include <iostream>
//using namespace std;

class Nodo{

    public:
        int valor;
        Nodo *siguiente = NULL;
        
        void imprimir(Nodo *nodo){
            while(nodo != NULL){
                std::cout << nodo->valor << " -> ";
                nodo = nodo->siguiente;
            }
            std::cout << "NULL" << std::endl;
        }
};

#endif