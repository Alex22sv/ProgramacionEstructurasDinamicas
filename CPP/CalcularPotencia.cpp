/* 16/08/2023 */
#include <iostream>
#include <windows.h>

using namespace std;
/*   
    / ; () > [] ? : $ @ & %  # "" = _ !
*/

int CalcularPotencia(int base, int exponente);

int main(){
    // Función que permite mostrar los caracteres especiales en la terminal
    SetConsoleOutputCP(CP_UTF8);

    int base, exponente;
    cout<<"Ingrese el número de la base: ";
    cin>>base;
    cout<<"Ingrese el número del exponente: ";
    cin>>exponente;
    cout<<"El número base "<<base<<" elevado al exponente "<<exponente<<" es: "<<CalcularPotencia(base, exponente);
    return 0;
}

int CalcularPotencia(int base, int exponente){
    if(exponente==0){
        return 1;
    } else {
        return base*CalcularPotencia(base,--exponente);
    }
}