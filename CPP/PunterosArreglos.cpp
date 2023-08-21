/* 21/08/2023 */
#include <iostream>
#include <windows.h>

using namespace std;
/*   
    / ; () > [] ? : $ @ & %  # "" = _ !
*/

int main(){
    // Función que permite mostrar los caracteres especiales en la terminal
    SetConsoleOutputCP(CP_UTF8);

    // Punteros con arreglos
    // El arreglo ya funciona como un puntero
    cout<<"Punteros con arreglos\n";
    int vector[5]  = {4, 5, 8, 1, 9};
    cout<<vector[2]<<"\n";
    cout<<vector<<"\n";
    cout<<*(vector)<<"\n"; // Sintaxis de puntero, acceder al primer valor del arreglo
    cout<<*(vector+1)<<"\n"; // Acceder al segundo valor
    
    cout<<"\n\n";
    int *ptr = vector;
    for (int i = 0; i < 5; i++){
        cout<<*(vector+i)<<" - "<<ptr++<<"\n";
    }
    
    return 0;

}
