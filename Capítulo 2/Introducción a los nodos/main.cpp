#include <iostream>
#include "Nodo.h"

using namespace std;



int main(){
    
    Nodo *nodo1 = new Nodo;
    nodo1->valor = 7;

    Nodo *nodo2 = new Nodo;
    nodo2->valor = 14;

    Nodo *nodo3 = new Nodo;
    nodo3->valor = 21;

    nodo1->siguiente = nodo2;
    nodo2->siguiente = nodo3;

    nodo1->imprimir(nodo1);

    return 0;
}