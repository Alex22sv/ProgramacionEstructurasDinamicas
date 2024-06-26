/* 25/09/2023 */
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

// Global
struct Nodo *lista = nullptr;

void InsertarInicio(int);
void InsertarIntermedio(int, int);
void InsertarFinal(int);
void Imprimir();
void EliminarInicio();
void EliminarIntermedio(int);
void EliminarFinal();
int main(){
    // Función que permite mostrar los caracteres especiales en la terminal
    SetConsoleOutputCP(CP_UTF8);
    int valor = 0, pos = 0;
    for(int i=0; i<5; i++){
        cout<<"Ingrese el valor #"<<i+1<<": ";
        cin>>valor;
        InsertarFinal(valor);
    }
    Imprimir();
    cout<<"Ingrese un valor para insertar en una posición: ";
    cin>>valor;
    cout<<"Ingrese la posición del valor: ";
    cin>>pos;
    InsertarIntermedio(valor, pos);
    cout<<"Eliminando el valor inicial.\n";
    EliminarInicio();
    cout<<"Eliminando el valor final.\n";
    EliminarFinal();
    Imprimir();
    return 0;
}

void InsertarInicio(int n){
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal = lista;
    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = nullptr;
    if(lista==nullptr){
        lista = nuevoNodo;
    } else {
        // Agregar nodo al inicio
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
}
void InsertarIntermedio(int n, int posicion){
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal = lista;
    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = nullptr;
    posicion--;
    while(posicion!=1){
        temporal = temporal->siguiente;
        posicion--;
    }
    // Conectar el nuevoNodo a temporal
    nuevoNodo->siguiente = temporal->siguiente;
    temporal->siguiente = nuevoNodo;
}
void InsertarFinal(int n){
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal = lista;
    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = nullptr;
    if(lista==nullptr){
        lista = nuevoNodo;
    } else {
        while(temporal->siguiente!=nullptr){
            temporal = temporal->siguiente;
        }
        temporal->siguiente = nuevoNodo;
    }
}
void EliminarInicio(){
    struct Nodo *temporal = lista;
    if(lista!=nullptr){
        lista = temporal->siguiente;
        delete temporal;
    } else {
        cout<<"Lista vacía.\n";
    }
}
void EliminarIntermedio(int posicion){
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;
    while(posicion!=1){
        temporal2 = temporal;
        temporal = temporal->siguiente;
        posicion--;
    }
    temporal2 = temporal->siguiente;
    temporal->siguiente = temporal2;
    delete temporal;
    temporal = nullptr;
}
void EliminarFinal(){
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;
    if(lista!=nullptr){
        if(temporal->siguiente!=nullptr){
            while(temporal->siguiente!=nullptr){
                temporal2 = temporal;
                temporal = temporal->siguiente;
            }
            // Almacena el penúltimo nodo será quien apunte 
            temporal2->siguiente = nullptr;
            // Se libera la memoria del último nodo
            delete temporal;
            temporal = nullptr;
        } else { 
            // solo hay un nodo en la lista
            delete lista;
            lista = nullptr;
        }
    }
}
void Imprimir() {
    struct Nodo *temporal = lista;
    if(lista!=nullptr){
        while(temporal!=nullptr){
            cout<<"Elemento de la cola: "<<temporal->elemento<<" - Dirección actual: "<<temporal<<" - Dirección siguiente: "<<temporal->siguiente<<"\n";
            temporal = temporal->siguiente;
        }
    } else {
        cout<<"Lista vacía.\n";
    }
}