#include "Lista.h"
using namespace std;

Lista::Lista(){
    maximo = 0;
}


Lista::~Lista(){
    delete [] maxItems;
    maxItems = NULL;
}


int Lista::obtener(int index){ // Complejidad O(1)

    //Checar que no esté fuera del límite
    if(index < 0 || index > maximo){
        std::cout<<"El índice se sale del límite"<<std::endl;
        return -1;
    }
    //Regresar el valor
    return maxItems[index];
}


void Lista::insertar(int index, int valor){ //Complejidad O(n)

    //Checar que no esté fuera del límite
    if(index<0 || index > maximo){
        std::cout<<"El índice se sale del límite"<<std::endl;
        return;
    }

    //Copiar la lista vieja
    int *listaTemp = maxItems;

    //Incrementar el tamaño de la lista
    maximo++;

    //Inicializar la nueva lista
    maxItems = new int[maximo];

    //Llenar la nueva lista
    for(int i=0, j=0; i<maximo;i++){
        if(i == index)
        {
            maxItems[i] = valor;
        }
        else
        {
            maxItems[i] = listaTemp[j];
            j++;
        }
    }
   
    //Eliminar la lista vieja
    delete [] listaTemp;
}


int Lista::buscar(int index){ // Complejidad O(n)
   for(int i=0; i<maximo; i++){
       if(i == index){
           cout<<"El elemento en la posición " << index << " es " << maxItems[i] << endl;
           return maxItems[i];
       }
   }
   cout<<"No hay elementos en esa posición"<<endl;
   return -1;
}


void Lista::eliminarPorIndex(int index){ //Complejidad O(n)

    //Checar que no esté fuera del límite
    if(index<0 || index>maximo){
        cout << "El indice se sale del límite" << endl;
    }
    //Copiar lista
    int *listaTemp = maxItems;
    
    //Disminuir el tamaño de la lista
    maximo--;

    //Inicializar una nueva lista
    maxItems = new int[maximo];

    //Llenar la lista sin el elemento
    for(int i=0, j=0; i<maximo; i++, j++){
        if(j == index){
            j++;
        }

        maxItems[i] = listaTemp[j];
        
    }

    //Eliminar la lista vieja
    delete [] listaTemp;
}

void Lista::setMaximo(int valor){
    this->maximo = valor;
}

int Lista::getMaximo(){
    return maximo;
}

void Lista::imprimir(){
    for(int i=0; i < maximo; i++){
        cout << maxItems[i] << " ";
    }
    cout << endl;
}
