#include <iostream>
#include "Nodo.h"
#include "ListaLigada.h"
#include <string>

using namespace std;

int main(){

    ListaLigada<int> l1; 
    l1.imprimir();
    l1.buscar(0);
    l1.insertarHead(22);
    l1.insertarTail(44);
    l1.insertarPorIndex(0, 1);
    l1.insertarPorIndex(3, 4);
    l1.insertarPorIndex(1, 69);
    l1.buscar(22);
    l1.buscar(0);
    l1.imprimir();
    l1.borrarHead();
    l1.imprimir();

    //No funcionan los string
    
    return 0;
}