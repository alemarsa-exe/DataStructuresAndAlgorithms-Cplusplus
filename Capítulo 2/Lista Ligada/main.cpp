#include <iostream>
#include "Nodo.h"

using namespace std;

int main(){

    Nodo<int> *nodo1 = new Nodo<int>;
    Nodo<int> *nodo2 = new Nodo<int>;
    
    nodo1->valor = 3;
    nodo2->valor = 4;

    nodo1->siguiente = nodo2;

    nodo1->imprimir(nodo1);


    return 0;
}