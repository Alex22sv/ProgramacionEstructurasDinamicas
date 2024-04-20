/* 15/08/2023 */
#include <iostream>
#include <windows.h>

using namespace std;
/*   
    / ; () > [] ? : $ @ & %   "" = _ ! 
*/

int CalcularMCD(int num1, int num2);
int CalcularMCM(int num1, int num2);

int main(){
    // Función que permite mostrar los caracteres especiales en la terminal
    SetConsoleOutputCP(CP_UTF8);

    int opcion, num1, num2;
    cout<<"--- Bienvenido al sistema de M.C.D. y M.C.M. ---\n"<<"¿Qué desea calcular?\n1. Mínimo Común Múltiplo (M.C.M.)\n2. Mínimo Común Divisor (M.C.D.)\n...";
    cin>>opcion;
    cout<<"Ingrese el primer número: ";
    cin>>num1;
    cout<<"Ingrese el segundo número: ";
    cin>>num2;
    if(opcion==1){
        cout<<"El M.C.M. de "<<num1<<" y "<<num2<<" es: "<<CalcularMCM(num1, num2); 
    } else if(opcion==2){
        cout<<"El M.C.D. de "<<num1<<" y "<<num2<<" es: "<<CalcularMCD(num1, num2);    
    } else {
        cout<<"Has ingresado una opción no válida.";
    }

    return 0;
}

// Definición de funciones
int CalcularMCD(int num1, int num2){
    if (num2==0){
        return num1;
    }
    // Llamado directo, llamamos a la misma función
    return CalcularMCD(num2, num1 % num2);
    
}

int CalcularMCM(int num1, int num2){
    if (num1==0||num2==0){
        return 0;
    }
    // Llamado indirecto, ya que usamos una función externa
    int mcm = (num1*num2)/CalcularMCD(num1, num2);
    return mcm;
}

