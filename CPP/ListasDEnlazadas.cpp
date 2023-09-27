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
    InsertarIntermedio(3, 500);
    Imprimir();
    return 0;
}

void InsertarInicio(int n)
{
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal = lista;

    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;

    // Si la lista esta vacia
    if (lista == nullptr)
    {
        lista = nuevoNodo;
    }
    else
    {
        //conexion del nuevo nodo con la lista
        nuevoNodo->siguiente = lista;
        lista->anterior = nuevoNodo;
        //asignar el nuevonodo a la cabeza de la lista
        lista = nuevoNodo;
    }
}

// Insertar nodos al final de la lista
void InsertarFinal(int n)
{
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal = lista;

    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;

    // Si la lista esta vacia
    if (lista == nullptr)
    {
        lista = nuevoNodo;
    }
    else
    {
        while (temporal->siguiente != nullptr)
        {
            temporal = temporal->siguiente;
        }
        //conexiones de nuevonodo a temporal
        temporal->siguiente = nuevoNodo;
        nuevoNodo->anterior = temporal;
    }
}

// Insertar intermedio
void InsertarIntermedio(int n, int posicion)
{

    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo();
    // Variable auxiliar almacena el nodo actual
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;

    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;

    posicion--;
    while (posicion != 1)
    {
        temporal = temporal->siguiente;
        posicion--;
    }
    //Conexiones del nuevoNodo con la lista 
    temporal2 = temporal->siguiente;
    temporal->siguiente = nuevoNodo;
    temporal2->anterior = nuevoNodo;
    nuevoNodo->siguiente = temporal2;
    nuevoNodo->anterior = temporal;
}




// Borrar el primer nodo de la lista
void EliminarInicio()
{
    struct Nodo *temporal = lista;

    if (lista != nullptr)
    {
        if (temporal->siguiente != nullptr)
        {
            lista = lista->siguiente;
            delete temporal;
            // temporal = nullptr;
            lista->anterior = nullptr;
        }
        else
        {
            delete lista;
            lista = nullptr;
        }
    }
    else
    {
        cout << "Lista vacia";
    }
}
void EliminarIntermedio(int posicion){
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;
    struct Nodo *temporal3;
    while(posicion!=1){
        temporal2 = temporal;
        temporal = temporal->siguiente;
        temporal3 = temporal->siguiente;
        posicion--;
    }
    temporal2->siguiente = temporal3;
    temporal3->anterior = temporal2;
    delete temporal;
    temporal = nullptr;

}
// Borrar el ultimo nodo de la lista
void EliminarFinal()
{
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
    }
    else{
        cout << "Lista vacia";
    }
}
void Imprimir(){
    struct Nodo *temporal = lista;
    if (temporal != nullptr)
    {
        // Imprimir cuando se inserta al final de la lista
        while (temporal != nullptr)
        {
            cout << "Lista " << temporal->elemento << " Direccion " << temporal << " Dir siguiente " << temporal->siguiente << " Dir anterior " << temporal->anterior << endl;
            temporal = temporal->siguiente;
        }
    }
    else
    {
        cout << "Lista vacia";
    }
}