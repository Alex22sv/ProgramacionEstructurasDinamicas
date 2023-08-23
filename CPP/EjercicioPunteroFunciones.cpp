/* 23/08/2023 */
#include <iostream>
#include <windows.h>

using namespace std;
/*   
    / ; () > [] ? : $ @ & %  # "" = _ !
*/

void alternarValorVariables(int &x, int &y);
// Podemos mezclar valores simples y por referencia
void calculadora(int, int, int &, int &, int &);
void calcularTicket(int cant, float precio, float &descuento, float &totalPagar);

int main(){
    // Función que permite mostrar los caracteres especiales en la terminal
    SetConsoleOutputCP(CP_UTF8);
    // Ejercicio 1 
    int x, y;
    cout<<"Ingrese el primer valor: ";
    cin>>x;
    cout<<"Ingrese el segundo valor: ";
    cin>>y;
    alternarValorVariables(x, y);
    cout<<"El primer valor ingresado ha cambiado a "<<x<<". El segundo valor ingresado a cambiado a "<<y<<". \n";

    cout<<"\n\n";
    // Ejercicio 2
    int suma = 0;
    int resta = 0;
    int mult = 0;
    int n, m;
    cout<<"Ingrese el primer valor: ";
    cin>>n;
    cout<<"Ingrese el segundo valor: ";
    cin>>m;
    calculadora(n, m, suma, resta, mult);
    cout<<"Suma: "<<suma<<"\n";
    cout<<"Resta: "<<resta<<"\n";
    cout<<"Multiplicación: "<<mult<<"\n";

    cout<<"\n\n";
    // Ejercicio 3
    int cant, precio;
    float descuento, totalPagar;
    cout<<"Ingrese la cantidad del producto: ";
    cin>>cant;
    cout<<"Ingrese el precio del producto: $";
    cin>>precio;
    calcularTicket(cant, precio, descuento, totalPagar);
    cout<<"El descuento aplicado es: $"<<descuento<<".\nEl total a pagar es: $"<<totalPagar<<".\n";
    return 0;
}

// Esto nos sirve para devolver varios valores usando referencia
void alternarValorVariables(int &x, int &y){
    // Por referencia
    int x1 = x;
    int y1 = y;
    x = y1;
    y = x1;
    return;

}

// Podemos dejarlo como float y no debería dar error
void calculadora(int n, int m, int &suma, int &resta, int &mult){
    suma = n + m;
    resta = n - m;
    mult = n * m;
}

void calcularTicket(int cant, float precio, float &descuento, float &totalPagar){
    totalPagar = (cant*precio)*0.8;
    descuento = (cant*precio)-totalPagar; 
}