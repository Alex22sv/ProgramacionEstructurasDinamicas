/* 16/08/2023 */
#include <iostream>
#include <windows.h>

using namespace std;
/*   
    / ; () > [] ? : $ @ & %  # "" = _ !
*/

void CuentaRegresiva(int numInicio);

int main(){
    // Función que permite mostrar los caracteres especiales en la terminal
    SetConsoleOutputCP(CP_UTF8);

    int inicio;
    cout<<"Ingrese el número de inicio: ";
    cin>>inicio;

    if (inicio>=1)
    {
        CuentaRegresiva(inicio);
    } else {
        cout<<"No se aceptan números negativos ni cero.";
    }
    
    return 0;
}

void CuentaRegresiva(int numInicio){
    if(numInicio==0){
        return;
    }
    cout<<numInicio<<"\n";
    CuentaRegresiva(--numInicio);
}