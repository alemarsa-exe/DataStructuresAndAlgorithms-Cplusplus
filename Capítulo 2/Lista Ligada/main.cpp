#include <iostream>
#include "Nodo.h"
#include "ListaLigada.h"
#include <string>

using namespace std;

int main(){

    cout << "Con enteros" << endl;
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
    l1.borrarTail();
    l1.insertarTail(90);
    l1.borrarPorIndex(2);
    l1.imprimir();
    

    //Ya funcionan los string :D
    
    cout << "\nAhora con strings" << endl;
    ListaLigada<string> l2;
    l2.insertarHead("Hola");
    l2.insertarTail("estás?");
    l2.insertarPorIndex(1, "¿cómo ");
    l2.buscar("hola");
    l2.imprimir();

    return 0;
}