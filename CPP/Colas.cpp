/* 18/09/2023 */
#include <iostream>
#include <windows.h>

using namespace std;
/*   
    / ; () > [] ? : $ @ & %  # "" = _ !
*/

/* 
    Una cola es una estructura de datos lineal 
    Almacena los datos en una lista 
    Los datos se pueden acceder por uno de los dos extremos
    Los elementos se eliminan en el mismo orden que entraron
    Una cola es una estructura FIFO (first-in, first-out)
    Operaciones con cola: 
        - vacía (comprueba si la cola está vacía)
        - frente (devuelve el valor del elemento en el frente de la cola)
        - final (devuelve el valor del elemento en el final de la cola)
        - desencolar (elimina y devuelve el elemento de la cabeza o frente de la cola)
        - encolar (inserta un elemento al final de la cola)
    Tipos d cola:
        - cola simple: los elementos se eliminan en el mismo orden que de almacenan
        - cola circular/anillo: los elementos pueden manipularse desde el frente y la última posición conecta con la primera
        - cola de prioridad: los elememtos se insertan en cualquier posición y se remueven solo por el frente

*/
struct Nodo {
    int elemento;
    struct Nodo *siguiente;
};
// Variables global
struct Nodo *frenteCola = nullptr;
struct Nodo *finalCola = nullptr;
bool Vacia();
void Insertar(int);
void Eliminar();
void Imprimir();
void ImprimirFrente();
void ImprimirFinal();


int main(){
    // Función que permite mostrar los caracteres especiales en la terminal
    SetConsoleOutputCP(CP_UTF8);

    int valor;
    for(int i=0;i<5;i++){
        cout<<"Ingrese un valor: ";
        cin>>valor;
        Insertar(valor);
    }
    cout<<"\n----------------\n";
    Imprimir();
    cout<<"\n----------------\n";
    // Imprimir();
    Eliminar();
    Imprimir();
    return 0;
}

// Operación vacía
bool Vacia(){
    return frenteCola == nullptr;
}
void Insertar(int n) {
    struct Nodo *nuevoNodo = new Nodo();

    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = nullptr;
    if(Vacia()){
        frenteCola = nuevoNodo;
    } else {
        finalCola->siguiente = nuevoNodo;
    }
    // Se establece el final de la cola 
    finalCola = nuevoNodo;
}
void Imprimir() {
    struct Nodo *temporal = frenteCola;
    while(temporal!=nullptr){
        cout<<"Elemento de la cola: "<<temporal->elemento<<"\n";
        temporal = temporal->siguiente;
    }
}
void Eliminar(){
    struct Nodo *temporal = frenteCola;
    //Solo hay un elemento en la cola
    if(frenteCola==finalCola){
        frenteCola=nullptr;
        finalCola=nullptr;
    } else {
        // Eliminar el primer valor agregado
        frenteCola = temporal->siguiente;
    }
    delete temporal;
}
void ImprimirFrente() {
    if(frenteCola==nullptr){
        cout<<"La cola está vacía.";
    }
    cout<<"Frente de la cola: "<<frenteCola->elemento<<"\n";
}
void ImprimirFinal() {
    if(finalCola==nullptr){
        cout<<"La cola está vacía.";
    }
    cout<<"Final de la cola: "<<finalCola->elemento<<"\n";
}