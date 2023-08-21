/* 21/08/2023 */
#include <iostream>
#include <windows.h>

using namespace std;
/*   
    / ; () > [] ? : $ @ & %  # "" = _ !
*/

void EncontrarDireccion(int num);
int arreglo[5] = {2, 5, 72, 65, 0};
int arregloSize = sizeof(arreglo)/sizeof(int);

int main(){
    // Función que permite mostrar los caracteres especiales en la terminal
    SetConsoleOutputCP(CP_UTF8);

    // Escribir una función que utilice punteros para buscar la dirección de un entero dado en un array dado. 
    // Si se encuentra el puntero dado, la función devuelve su dirección, en caso contrario devuelve NULL.
    int num;
    cout<<"Ingrese un número: ";
    cin>>num;
    EncontrarDireccion(num);
    return 0;
}

void EncontrarDireccion(int num){
    int *ptr;
    ptr = nullptr;
    for (int i = 0; i < arregloSize; i++){
        if(num == arreglo[i]){
            ptr = (arreglo+i);
        } 
    }
    cout<<"Su dirección de memoria es "<<ptr;
    
}