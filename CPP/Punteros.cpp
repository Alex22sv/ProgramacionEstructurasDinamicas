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

    int a = 15;
    int *ptr, *ptr2, *ptr3, *ptr4;
    ptr = &a;
    *ptr2 = 20;
    ptr3 = ptr2;
    ptr4 = nullptr;
    cout<<ptr<<"\n"; // Imprimir la dirección de memoria 
    cout<<*ptr<<"\n"; // Imprimir el valor de la variable (15)
    cout<<*ptr2<<"\n"; // Imprime el 20
    cout<<*ptr3<<"\n"; // Da 20, ya que en la línea 17 modificamos el valor desde el origen.
    cout<<*ptr4<<"\n"; // Da cero porque no apunta a nada
    return 0;
}
