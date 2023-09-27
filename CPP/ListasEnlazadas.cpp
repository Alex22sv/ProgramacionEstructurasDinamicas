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
    Imprimir();
    return 0;
}

void InsertarInicio(int n){
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal = lista;
    if(nuevoNodo!=nullptr){
        nuevoNodo->siguiente = nullptr;
        if(lista==nullptr){
            lista = nuevoNodo;
        } else {
            // Agregar nodo al inicio
            nuevoNodo->siguiente = lista;
            lista = nuevoNodo;
        }
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
    if(nuevoNodo!=nullptr){
        while(temporal->siguiente!=nullptr){
            temporal = temporal->siguiente;
        }
        temporal->siguiente = nuevoNodo;
    } else {
        cout<<"No se pueden crear más nodos.";
    }
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
void EliminarInicio(){
    struct Nodo *temporal = lista;
    if(lista!=nullptr){
        lista = temporal->siguiente;
        delete temporal;
    }
}
void Imprimir() {
    struct Nodo *temporal = lista;
    while(temporal!=nullptr){
        cout<<"Elemento de la cola: "<<temporal->elemento<<"\n";
        temporal = temporal->siguiente;
    }
}