/* 14/08/2023 */
#include <iostream>
#include <windows.h>

using namespace std;
/*  
/ ; () > [] ? : $ @ & %  # "" =  _   
*/

// Declaración de funciones
int CalcularFactorial(int num);
int CalcularFactorialRecursividad(int num);


int main(){
    // Función que permite mostrar los caracteres especiales en la terminal
    SetConsoleOutputCP(CP_UTF8);
    int numeroFactorial = 0;
    cout<<"Ingrese el número al que le desea calcular el factorial: ";
    cin>>numeroFactorial;
    cout<<"El resultado es: "<<CalcularFactorialRecursividad(numeroFactorial);
    return 0;
}

int CalcularFactorial(int num){
    int resultado = 1;
    for (int i = num; i>0; i--){
        resultado*= i;
    }
    return resultado;
}
int CalcularFactorialRecursividad(int num){
    if(num==1||num==0){
        return 1;
    }
    return num*CalcularFactorialRecursividad(num-1);
}