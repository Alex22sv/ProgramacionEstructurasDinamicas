/* 23/10/2023 */
#include <iostream>
#include <windows.h>

using namespace std;
/*   
    / ; () > [] ? : $ @ & %  # "" = _ !
*/

#define size 7
struct Registro {
    int dato;
};
struct Nodo {
    struct Registro registro;
    struct Nodo *anterior, *siguiente;
};
struct Nodo *tabla[size] = {nullptr};
struct Nodo *lista = nullptr;

// Declaración de funciones
void Agregar(int);
int F_Hash(int);
void Imprimir();
struct Nodo *Buscar(int, int);
void EliminarR(int);

int main(){
    // Función que permite mostrar los caracteres especiales en la terminal
    SetConsoleOutputCP(CP_UTF8);
    /* 
        Son estructuras de datos que utilizan una función hash para registro de datos.
        Son conocidos como mapas hash.
        3 métodos para calcular la función hash:
            - Método de división
            - Método de plegado
            - Método de medio
        Método de división:
            h(ki) = ki % m;
            f(hash) = llave % divisor;
            Donde m es el tamaño de la tabla
        Esto puede causar problemas, que la función de el mismo valor 2 veces
        Los valores de un string se calculan utilizando la suma de las letras en ASCII 
        Colisión:
            - Técnicas de resolución: hash abierto y cerrado
            - El hash abierto se implementa mediante listas enlazadas
            -
    */

    // Mi nombre en ASCII: ALEX
    // 65 + 76 + 69 + 88 = 298
    Agregar(34);
    Agregar(1);
    Agregar(5);
    Agregar(9);
    Agregar(76);
    Imprimir();
    EliminarR(34);
    return 0;
}

void Agregar(int _dato){
    struct Nodo *nuevoNodo = new Nodo();
    struct Registro r;
    r.dato = _dato;
    int clave = F_Hash(_dato);
    nuevoNodo->registro = r;
    nuevoNodo->anterior = nullptr;
    nuevoNodo->siguiente = tabla[clave];
    if(tabla[clave]){
        tabla[clave]->anterior = nuevoNodo;
    }
    tabla[clave] = nuevoNodo;
    cout<<"Dirección: "<<tabla[clave]<<" - Clave (índice): "<<clave<<" - Dato almacenado: "<<tabla[clave]->registro.dato<<"\n";
}
int F_Hash(int _dato){
    return _dato % size;
}
void Imprimir(){
    for(int i = 0; i < size; i++){
        struct Nodo *temporal;
        temporal = tabla[i];
        while(temporal!=nullptr){
            cout<<"Dirección: "<<tabla[i]<<" - Clave (índice): "<<i<<" - Dato almacenado: "<<tabla[i]->registro.dato<<"\n";
            temporal = temporal->siguiente; 
        }
    }
}
void EliminarR(int _dato){
    int clave = F_Hash(_dato);
    struct Nodo *nuevoNodo = Buscar(_dato, clave);
    if(nuevoNodo){
        cout<<"Registro eliminado: "<<nuevoNodo->registro.dato<<"\n";
        if(nuevoNodo->siguiente){
            nuevoNodo->siguiente->anterior = nuevoNodo->anterior;
        }
        if(nuevoNodo->anterior){
            nuevoNodo->anterior->siguiente = nuevoNodo->siguiente;
        } else {
            tabla[clave] = nuevoNodo->siguiente;
        }
        nuevoNodo->anterior->siguiente = nuevoNodo->siguiente;
        delete nuevoNodo;
    } else {
        cout<<"Registro no encontrado.\n";
    }
}
struct Nodo *Buscar(int _dato, int _clave){
    struct Nodo *nuevoNodo = tabla[_clave];
    while(nuevoNodo){
        if(nuevoNodo->registro.dato==_dato){
            return nuevoNodo;
        }
        nuevoNodo = nuevoNodo->siguiente;
    }
    return nullptr;
}