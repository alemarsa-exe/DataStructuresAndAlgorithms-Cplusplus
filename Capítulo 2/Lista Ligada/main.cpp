#include <iostream>
#include "Nodo.h"
#include "ListaLigada.h"


using namespace std;

int main(){

    ListaLigada<int> l1; 
    l1.insertarHead(22);
    l1.insertarHead(76);
    l1.insertarTail(44);
    l1.insertarTail(23);
    //l1.obtener(0);
    l1.imprimir();

    return 0;
}