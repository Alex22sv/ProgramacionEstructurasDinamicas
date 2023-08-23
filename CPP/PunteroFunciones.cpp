/* 23/08/2023 */
#include <iostream>
#include <windows.h>

using namespace std;
/*   
    / ; () > [] ? : $ @ & %  # "" = _ !
*/

// Declaración de funciones
int incrementoPorValor(int i);
int incrementoPuntero(int *i);
int incrementoReferencia(int &i);

int main(){
    // Función que permite mostrar los caracteres especiales en la terminal
    SetConsoleOutputCP(CP_UTF8);
    int a = 4;
    // Por valor
    cout<<a<<endl;
    cout<<incrementoPorValor(a)<<endl;
    cout<<a<<endl;
    cout<<"\n\n";
    // Por puntero
    int b = 4;
    int *ptr = &b;
    cout<<b<<endl;
    cout<<incrementoPuntero(&b)<<endl;
    cout<<b<<endl;
    cout<<"\n\n";
    // Por referencia
    int c = 4;
    cout<<c<<endl;
    cout<<incrementoReferencia(c)<<endl;
    cout<<c<<endl;
    return 0;
}

// Definición de funciones
int incrementoPorValor(int i){
    return i+=1;
}
int incrementoPuntero(int *i){
    return *i += 1;
}
int incrementoReferencia(int &i){
    return i += 1;
}