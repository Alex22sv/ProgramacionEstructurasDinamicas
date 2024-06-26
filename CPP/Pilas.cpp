/* 11/09/2023 */
#include <iostream>
#include <windows.h>

using namespace std;
/*  
/ ; () > [] ? : $ @ & %  # "" =  _   
*/

/* Pilas (stack)
    Hoy entramos a estructuras de datos dinámicas
    Las pilas se conocen como LIFO (last-in, first-out)
    El primero que entra es el último que sale
    Si un programa intenta sacar un elemento de una pila vacía, se produce desbordamiento negativo (underflow)
    Si se intenta agregar un elemento a una pila llena, se produce desbordamiento (overflow)
    Las pilas nos pueden ser útiles para una eficiente repredentación de los datos donde es necesario mantener un orden
    Operaciones con pila: crear, vacía, llena, contar, insertar (push), eliminar (pop), tope
    Requiere la librería "stack"
    La raíz es el puntero que almacena la dirección del primer nodo
    El último nodo apunta a nada, a 0
    El primer nodo apunta al segundo, y así sucesivamente
    Para imprimir la dirección de memoria del último elemento, llamamos a pila

 */
struct Nodo {
    int elemento;
    struct Nodo *siguiente;
};
// Variable global
struct Nodo *pila = nullptr;
// Declarando funciones
void Insertar(int);
//void EliminarUltimo(int &);
void EliminarUltimo();
void Imprimir();
bool Vacia();
void UltimoElemento();

int main(){
    // Función que permite mostrar los caracteres especiales en la terminal
    SetConsoleOutputCP(CP_UTF8);
    int valor;
    for(int i = 0;i<5;i++){
        cout<<"Ingrese un valor: ";
        cin>>valor;
        Insertar(valor);
    }
    Imprimir();
    // EliminarUltimo(valor);
    EliminarUltimo();
    cout<<"El último elemento de la fila es: ";
    UltimoElemento();
    // Imprimir el tercer valor manualmente
    // cout<<pila->siguiente->siguiente->elemento<<<<" - "<<pila->siguiente->siguiente<<"\n";
}

// Definición de variables
void Insertar(int n){
    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo();
    //Asignar valor
    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = pila;
    pila = nuevoNodo;
}
void Imprimir(){
    struct Nodo *temporal = pila;
    while(temporal!=NULL){
        cout<<"Elemento de la pila: "<<temporal->elemento<<" - "<<temporal->siguiente<<" \n";
        temporal = temporal->siguiente;
    }
}
// void EliminarUltimo(int &n){
void EliminarUltimo(){   
    if(pila!=NULL){
        struct Nodo *temporal = pila;
        //n = temporal->elemento;
        // cout<<"El valor a eliminar es: "<<n<<"\n";
        pila = temporal->siguiente;
        delete temporal;
    }
}
bool Vacia(){
    if(pila==NULL){
        return true;
    }
}
void UltimoElemento(){
    cout<<pila->elemento<<" - "<<pila<<"\n";   
}