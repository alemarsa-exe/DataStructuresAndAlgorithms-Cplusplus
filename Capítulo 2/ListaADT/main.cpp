#include <iostream>
#include "Lista.cpp"
using namespace std;

int main(){
    
    Lista l1;

    l1.insertar(0, 23);
    l1.insertar(1, 44);
    l1.insertar(2, 90);
    l1.insertar(3, 11);
    l1.insertar(7, 42);

    l1.imprimir();

    l1.buscar(1);
    l1.buscar(4); 

    l1.eliminarPorIndex(0);
    
    l1.imprimir();

    system("pause");
    return 0;
}