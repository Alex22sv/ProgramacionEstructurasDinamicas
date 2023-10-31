/* 02/10/2023 */
#include <iostream>
#include <windows.h>

using namespace std;
/*   
    / ; () > [] ? : $ @ & %  # "" = _ !
*/
struct Nodo {
    int elemento;
    struct Nodo *siguiente;
};

struct Nodo *lista = nullptr;

void InsertarInicio(int);
void InsertarFinal(int);
void InsertarIntermedio(int, int);
void Imprimir();
void EliminarInicio();
void EliminarFinal();
void EliminarIntermedio(int);

int main(){
    // Función que permite mostrar los caracteres especiales en la terminal
    SetConsoleOutputCP(CP_UTF8);

    InsertarInicio(4);
    InsertarInicio(200);
    InsertarInicio(67);
    Imprimir();
    InsertarFinal(5);
    InsertarFinal(9);
    InsertarFinal(12);
    Imprimir();
    EliminarInicio();
    EliminarFinal();
    EliminarIntermedio(3);
    Imprimir();
    return 0;
}

void InsertarInicio(int n){
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal;
    nuevoNodo->elemento = n;
    if(lista == nullptr){
        lista = nuevoNodo;
        lista->siguiente = lista;
        temporal = lista;
    } else {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
        temporal->siguiente = lista;
    }
}
void InsertarFinal(int n){
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal;
    nuevoNodo->elemento = n;
    if(lista == nullptr){
        lista = nuevoNodo;
        lista->siguiente = lista;
        temporal = lista;
    } else {
        temporal->siguiente = nuevoNodo;
        nuevoNodo->siguiente = lista;
        temporal = nuevoNodo;
    }
}
void InsertarIntermedio(int n, int posicion){
    struct Nodo *nuevoNodo = new Nodo();
    // Variable auxiliar almacena el nodo actual
    struct Nodo *temporal = lista;
    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = nullptr;
    posicion--;
    while (posicion != 1){
        temporal = temporal->siguiente;
        posicion--;
    }
    // conexión del nuevoNodo con el resto de nodos de la lista
    nuevoNodo->siguiente = temporal->siguiente;
    // Asignar el nuevoNodo a la lista
    temporal->siguiente = nuevoNodo;
}
void EliminarInicio(){
    struct Nodo *temporal = lista;
    if(lista != nullptr){
        while(temporal->siguiente!=lista){
            temporal = temporal->siguiente;
        }
        temporal->siguiente = lista->siguiente;
        delete lista;
        lista = temporal->siguiente;
    } else if (lista->siguiente == lista){
        delete lista;
        lista = nullptr;
    } else {
        cout<<"La lista está vacía\n";
    }
}
void EliminarFinal()
{
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;
    if (lista != nullptr){
        // Si hay mas de un elemento en la lista
        while (temporal->siguiente != lista){
            temporal2 = temporal;
            temporal = temporal->siguiente;
        }
        temporal2->siguiente = temporal->siguiente;
        delete temporal;
    } else if (lista->siguiente == lista) {
        // SI SOLO HAY UN ELEMENTO
        delete lista;
        lista = nullptr;
    } else {
        cout<<"La lista está vacía.\n";
    }
}
void EliminarIntermedio(int posicion){
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;
    while (posicion != 1){
        temporal2 = temporal;
        temporal = temporal->siguiente;
        posicion--;
    }
    // conexión del nuevoNodo con el resto de nodos de la lista
    temporal2->siguiente = temporal->siguiente;
    delete temporal;
    temporal = nullptr;
}
void Imprimir(){
    struct Nodo *temporal = lista;
    if (lista != nullptr){
        do {
            cout<<"Elemento: "<<temporal->elemento<<" - Dirección: "<<temporal<<" - Siguiente: "<<temporal->siguiente<<"\n";
            temporal = temporal->siguiente;
        } while (temporal != lista);
    } else {
        cout<<"La lista está vacía.\n";
    }
    cout<<"\n---------------------\n";
}