#include <iostream>
#include "Nodo.h"
#include "ListaLigada.h"


using namespace std;

int main(){

    ListaLigada<int> l1; 
    l1.insertarHead(22);
    l1.insertarTail(44);
    l1.insertarPorIndex(0, 1);
    l1.insertarPorIndex(3, 4);
    l1.insertarPorIndex(1, 69);
    //l1.obtener(0);
    l1.imprimir();

    return 0;
}