/* 25/10/2023 */
#include <iostream>
#include <windows.h>

using namespace std;
/*   
    / ; () > [] ? : $ @ & %  # "" = _ !
*/

#define dimension 7

struct Registro{
    string dato;
};

struct Nodo
{
    struct Registro registro;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

struct Nodo *lista = nullptr;
struct Nodo *tabla[dimension] = {nullptr};

void Agregar(string);
int F_Hash(int);
struct Nodo *Buscar(string, int);
void BuscarR(string);
void EliminarR(string);
void Imprimir();
int ConvertirCaracterAscii(char caracter);  
int ConvertirArregloAscii(string arreglo);
char ConvertirAsciiCaracter(int ascii);

int main(void){
    // Función que permite mostrar los caracteres especiales en la terminal
    SetConsoleOutputCP(CP_UTF8);
    string valorAPedir;
    /* Agregar(12);
    Agregar(40);
    Agregar(33);
    Agregar(50);
    Agregar(75);
    EliminarR(33);
    Imprimir(); */
    for (int i = 0; i < dimension; i++){
        cout<<"Ingrese la palabra que desea agregar: ";
        cin>>valorAPedir;
        Agregar(valorAPedir);
    }
    Imprimir();
    EliminarR("alex");
    Imprimir();
    
}

void Agregar(string arreglo)
{
    struct Nodo *nuevoNodo = new Nodo();
    struct Registro r;
    r.dato = arreglo;
    int indice = ConvertirArregloAscii(arreglo);
    int clave = F_Hash(indice);
    
    nuevoNodo->registro = r;
    nuevoNodo->anterior = nullptr;
    nuevoNodo->siguiente = tabla[clave];
    if (tabla[clave])
        tabla[clave]->anterior = nuevoNodo;
    tabla[clave] = nuevoNodo;

    cout << " Dirección: " << tabla[clave] << " - Índice donde se almacena: " << clave << " - Dato almacenado: " << r.dato << endl;
}

int F_Hash(int _dato)
{
    return _dato % dimension;
}

struct Nodo *Buscar(string _dato, int _clave)
{
    struct Nodo *nuevoNodo = tabla[_clave];
    while (nuevoNodo)
    {
        if (nuevoNodo->registro.dato == _dato)
        {
            return nuevoNodo;
        }
        nuevoNodo = nuevoNodo->siguiente;
    }
    return nullptr;
}

void BuscarR(string arreglo)
{
    int clave = F_Hash(ConvertirArregloAscii(arreglo));
    struct Nodo *nuevoNodo = Buscar(arreglo, clave);
    if (nuevoNodo)
    {
        cout << "Registro encontrado ... Posicion: " << clave << " Valor: " << nuevoNodo->registro.dato << endl;
    }
    else
    {
        cout << "Registro no encontrado" << endl;
    }
}

void EliminarR(string _dato)
{
    int clave = F_Hash(ConvertirArregloAscii(_dato));
    struct Nodo *nuevoNodo = Buscar(_dato, clave);
    if (nuevoNodo){
        cout << "Registro eliminado " << nuevoNodo->registro.dato << endl;
        if (nuevoNodo->siguiente)
        {
            nuevoNodo->siguiente->anterior = nuevoNodo->anterior;
        }
        if (nuevoNodo->anterior)
        {
            nuevoNodo->anterior->siguiente = nuevoNodo->siguiente;
        }
        else
        {
            tabla[clave] = nuevoNodo->siguiente;
        }

        if (nuevoNodo->anterior)
        {
            nuevoNodo->anterior->siguiente = nuevoNodo->siguiente;
        }

        delete nuevoNodo;
    }
    else
    {
        cout << "Registro no encontrado" << endl;
    }
}

void Imprimir()
{
    struct Nodo *temporal;
    for (int i = 0; i < dimension; i++)
    {
        temporal = tabla[i];

        while (temporal != nullptr)
        {
            cout << "Índice de almacenamiento: " << i << " - Índice del arreglo: " << tabla[i] << " - Nodo: " << temporal << " - Anterior: " << temporal->anterior << " - Valor: " << temporal->registro.dato << endl;
            temporal = temporal->siguiente;
        }
    }
}

int ConvertirCaracterAscii(char caracter){
    return (int)caracter;
}
char ConvertirAsciiCaracter(int ascii){
    return (char)ascii;
}
int ConvertirArregloAscii(string arreglo){
    int indice = 0;
    for (int i = 0; i < arreglo.length(); i++){
        indice += ConvertirCaracterAscii(arreglo[i]);
    }
    return indice;
}