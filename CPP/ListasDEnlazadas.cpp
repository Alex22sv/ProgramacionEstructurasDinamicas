/* 27/09/2023 */
#include <iostream>
#include <windows.h>

using namespace std;
/*   
    / ; () > [] ? : $ @ & %  # "" = _ !
*/
struct Nodo {
    int elemento;
    struct Nodo *siguiente;
    struct Nodo *anterior;
};

// Global
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

    InsertarInicio(45);
    InsertarInicio(15);
    InsertarInicio(78);
    InsertarInicio(1);
    InsertarFinal(100);
    Imprimir();
    EliminarFinal();
    EliminarInicio();
    /* Eliminar intermedio no funciona correctamente */
    //EliminarIntermedio(3);
    cout<<"\nValores eliminados.\n";
    Imprimir();
    InsertarIntermedio(500, 2);
    cout<<"\nInsertando intermedio de la lista.\n";
    Imprimir();
    return 0;
}

void InsertarInicio(int n){
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal = lista;
    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;

    // Si la lista esta vacía
    if (lista == nullptr){
        lista = nuevoNodo;
    } else {
        // Conexión del nuevo nodo con la lista
        nuevoNodo->siguiente = lista;
        lista->anterior = nuevoNodo;
        // Asignar el nuevoNodo a la cabeza de la lista
        lista = nuevoNodo;
    }
}
// Insertar nodos al final de la lista
void InsertarFinal(int n){
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal = lista;

    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;
    // Si la lista esta vacia
    if (lista == nullptr){
        lista = nuevoNodo;
    } else {
        while (temporal->siguiente != nullptr){
            temporal = temporal->siguiente;
        }
        // Conexiones de nuevoNodo a temporal
        temporal->siguiente = nuevoNodo;
        nuevoNodo->anterior = temporal;
    }
}
// Insertar intermedio
void InsertarIntermedio(int n, int posicion){
    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo();
    // Variable auxiliar almacena el nodo actual
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;
    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;
    posicion--;
    while(posicion != 1){
        temporal = temporal->siguiente;
        posicion--;
    }
    // Conexiones del nuevoNodo con la lista 
    temporal2 = temporal->siguiente;
    temporal->siguiente = nuevoNodo;
    temporal2->anterior = nuevoNodo;
    nuevoNodo->siguiente = temporal2;
    nuevoNodo->anterior = temporal;
}
// Borrar el primer nodo de la lista
void EliminarInicio(){
    struct Nodo *temporal = lista;
    if (lista != nullptr){
        if (temporal->siguiente != nullptr){
            lista = lista->siguiente;
            delete temporal;
            // temporal = nullptr;
            lista->anterior = nullptr;
        } else {
            delete lista;
            lista = nullptr;
        }
    }
    else {
        cout<<"Lista vacía";
    }
}
void EliminarIntermedio(int posicion){
    struct Nodo *temporal = lista;
    int i = 1;
    while((temporal!=nullptr) && (i < posicion)){
        temporal = temporal->siguiente;
        i++;
    }
    /* while((temporal!=nullptr)&&(temporal->elemento!=valor)){
        temporal = temporal->siguiente;
    } */
    if(temporal!=nullptr){
        temporal->anterior->siguiente = temporal->siguiente;
        temporal->siguiente->anterior = temporal->anterior;
        delete temporal;
    } else {
        cout<<"No se pudo encontrar."; 
    }
}
// Borrar el último nodo de la lista
void EliminarFinal(){
    struct Nodo *temporal = lista;
    struct Nodo *temporal2 = nullptr;
    if (lista != nullptr){
        if (temporal->siguiente != nullptr){
            while (temporal->siguiente != nullptr){
                temporal = temporal->siguiente;
            }
            temporal2 = temporal->anterior;
            temporal2->siguiente = nullptr;
            delete temporal;
        } else {
            delete lista;
            lista = nullptr;
        }
    } else {
        cout<<"Lista vacía";
    }
}
void Imprimir(){
    struct Nodo *temporal = lista;
    if (lista != nullptr){
        // Imprimir cuando se inserta al final de la lista
        while (temporal != nullptr){
            cout<<"Elemento: "<<temporal->elemento<<" - Dirección actual: "<<temporal<<" - Dirección siguiente: "<<temporal->siguiente<<" - Dirección anterior: "<<temporal->anterior<<".\n";
            temporal = temporal->siguiente;
        }
    } else {
        cout<<"Lista vacía";
    }
}