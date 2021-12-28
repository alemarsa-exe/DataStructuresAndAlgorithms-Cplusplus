#ifndef NODO_H
#define NODO_H

#include<iostream>
using namespace std;
template<class T>

class Nodo{

    public:
        int valor;
        Nodo<T> *siguiente = NULL;

        void imprimir(Nodo *nodo){
            while(nodo!=NULL){
                cout<<nodo->valor<<" -> ";
                nodo=nodo->siguiente;
            }
            cout<<"NULL"<<endl;
        }

};


#endif