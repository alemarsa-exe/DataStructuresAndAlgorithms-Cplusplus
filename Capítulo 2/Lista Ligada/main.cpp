#include <iostream>
#include "Nodo.h"
#include "ListaLigada.h"
#include <string>

using namespace std;

int main(){

    cout << "\nHola, prueba de lista ligada con enteros" << endl;
    
    ListaLigada<int> l1;

    //Imprimir la lista vacía
    l1.imprimir();

    //Probar métodos de inserción
    l1.insertarHead(8);
    l1.insertarTail(900);
    l1.insertarPorIndex(1, 38);
    l1.insertarHead(-12);
    l1.insertarTail(999);
    l1.insertarPorIndex(5, 923764);

    //Reimprimir para corroborar que funciona
    l1.imprimir();

    //Probar métodos de búsqueda y obtención
    l1.obtener(1);
    l1.buscar(8);
    l1.buscar(200);

    //Probar métodos de borrado
    l1.borrarHead();
    l1.borrarTail();
    l1.borrarPorIndex(4);

    //Reimprimir para corroborar que funciona
    l1.imprimir();


    //Probando con strings
    
    cout << "\nAhora con strings" << endl;
    
    ListaLigada<string> l2;

    l2.insertarHead("Hola");
    l2.insertarTail("estás?");
    l2.insertarPorIndex(1, "¿cómo ");
    l2.buscar("hola");
    l2.imprimir();
    
    cout << endl;

    return 0;
}