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

    int vector[2] = {1, 3};
    int *ptr1 = vector; // ASIGNACIÓN

    int a = 35;
    int *ptr, *ptr2; 
    ptr = &a;
    ptr2 = ptr; 
    if(&ptr==&ptr2){
        // COMPARACIÓN        
        cout<<"Son iguales.\n";
    } 

    for (int i = 0; i < 5; i++){
        cout<<*(vector+i)<<" - "<<ptr++<<"\n"; // SUMA
    }

    for (int i = 0; i < 5; i++){
        cout<<*(vector+i)<<" - "<<ptr--<<"\n"; // RESTA
    }
    return 0;
}
