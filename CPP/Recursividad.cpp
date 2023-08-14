/* 14/08/2023 */
#include <iostream>
#include <windows.h>

using namespace std;
/*   
/ ; () > [] ? : $ @ & %  # "" =  _   
*/

// Declaración de funciones
int Suma(int n);

int main(){
    // Función que permite mostrar los caracteres especiales en la terminal
    SetConsoleOutputCP(CP_UTF8);

    // Uso de la recursividad
    cout<<"Suma total: "<<Suma(5)<<"\n";

    return 0;
}

int Suma(int n){
    if(n==0){
        return 0;
    }
    //cout<<n<<"\n";
    return n+Suma(n-1);
    // Es una función directa porque estamos llamando dentro de la función a la misma función.
}

/*
    Si no se declara el caso base, será una recursividad infinita
    El proceso de la recursividad es llamar a la función la n cantidad de veces que esté declarada, requiere más recursos.


*/
