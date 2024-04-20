/* 14/08/2023 */
#include <iostream>
#include <windows.h>

using namespace std;
/*   
/ ; () >> [] ? : $ @ & %  # "" =   
*/

// Declaración de SumarNumeros
int SumarNumeros(int lista[]);

int main(){
    // Función que permite mostrar los caracteres especiales en la terminal
    SetConsoleOutputCP(CP_UTF8);
    // Hacer una función que permita sumar 10 números

    int listaNumeros[10];
    // Pedir valores
    for (int i = 0; i < 10; i++){
        cout<<"Ingrese el valor del número #"<<to_string(i+1)<<": ";
        cin>>listaNumeros[i];
    }
    cout<<"La suma total de los 10 números es: "<<SumarNumeros(listaNumeros);
    return 0;
}

int SumarNumeros(int listaSuma[]){
    int sumaTotal = 0;
    for (int i = 0; i < 10; i++){
        sumaTotal+=listaSuma[i];
    }
    return sumaTotal;
      
}
