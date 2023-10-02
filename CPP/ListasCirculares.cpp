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
void Imprimir();
void EliminarInicio();
void EliminarFinal();

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
    return 0;
}

void InsertarInicio(int n){
    struct Nodo *nuevoNodo;
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
    struct Nodo *nuevoNodo;
    struct Nodo *temporal;
    nuevoNodo->elemento = n;
    if(lista == nullptr){
        lista = nuevoNodo;
        lista->siguiente = lista;
        temporal = lista;
    } else {
        temporal->siguiente = nuevoNodo;
        nuevoNodo->siguiente = lista;
        //temporal = nuevoNodo;
    }
}
void EliminarInicio(){
    if(){

    } else {
        while(temporal->siguiente!=lista){
            temporal = temporal->siguiente;
        }
        temporal->siguiente = lista->siguiente;
        delete lista;
        lista = temporal->siguiente;
    }
}