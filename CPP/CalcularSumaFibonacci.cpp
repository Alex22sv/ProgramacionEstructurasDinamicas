/* 14/08/2023 */
#include <iostream>
#include <windows.h>

using namespace std;
/*   
/ ; () > [] ? : $ @ & %  # "" = _   
*/

// Declaración de funciones
int CalcularSumaFibonacciRecursividad(int num);

int main(){
    // Función que permite mostrar los caracteres especiales en la terminal
    SetConsoleOutputCP(CP_UTF8);

    int numeroSucesion = 0;
    cout<<"Ingrese el número al que le desea calcular la sucesión de Fibonacci: ";
    cin>>numeroSucesion;
    cout<<"El resultado es: "<<CalcularSumaFibonacciRecursividad(numeroSucesion);
    return 0;
}

int CalcularSumaFibonacciRecursividad(int num){
    if(num>1){
        return CalcularSumaFibonacciRecursividad(num-1)+CalcularSumaFibonacciRecursividad(num-2);
    } 
    return num;
}