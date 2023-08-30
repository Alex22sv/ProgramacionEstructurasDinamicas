/* 30/08/2023 */
#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    // Función que permite mostrar los caracteres especiales en la terminal
    SetConsoleOutputCP(CP_UTF8);
    string *nombreLugarT = nullptr,*nombrePais = nullptr;
    int numRegistros;
    cout<<"¿Cuántos lugares turísticos desea registrar?";
    cin>>numRegistros;
    nombreLugarT = new string[numRegistros];
    nombrePais = new string[numRegistros];

    for(int i = 0; i < numRegistros; i++){
        cout<<"Ingrese el lugar turístico: ";
        cin>>nombreLugarT[i];
        cout<<"Ingrese el país: ";
        cin<<nombreLugarT[i];
    }
    for(int i = 0; i < numRegistros; i++){
        cout<<&nombreLugarT[i]<<" - "<<&nombrePais[i]<<" \n";
    }
    delete [] nombreLugarT;
    delete [] nombrePais;
    nombreLugarT = nullptr;
    nombrePais = nullptr;

    return 0;
}