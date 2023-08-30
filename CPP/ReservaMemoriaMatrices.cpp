/* 30/08/2023 */
#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    // Función que permite mostrar los caracteres especiales en la terminal
    SetConsoleOutputCP(CP_UTF8);
    string **matriz;
    string nombreLugarT, nombrePais;
    int numRegistros, columnas = 2;
    cout<<"¿Cuántos lugares turísticos desea registrar?";
    cin>>numRegistros;
    matriz = new string *[numRegistros];

    for(int i = 0; i < numRegistros; i++){
        matriz[i] = new string[columnas];
        cout<<"Ingrese el lugar turístico: ";
        cin>>matriz[i][0];
        cout<<"Ingrese el país: ";
        cin>>matriz[i][1];
    }
    for(int i = 0; i < numRegistros; i++){
        cout<<&matriz[i][0]<<" - "<<&matriz[i][1]<<" \n";
    }
    for(int i = 0; i < numRegistros; i++){
        delete[] matriz[i];
    }
    delete[] matriz;
    matriz = nullptr;
    return 0;
}