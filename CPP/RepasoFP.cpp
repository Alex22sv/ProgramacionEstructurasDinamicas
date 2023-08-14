#include <iostream>
#include <windows.h>

using namespace std;

void NumeroDias(int numMes);

int main(){
    // Función que permite mostrar los caracteres especiales en la terminal
    SetConsoleOutputCP(CP_UTF8);
    // Declaración de variables
    int mesInput;
    cout<<"Ingresa el número del mes: ";
    cin>>mesInput;
    NumeroDias(mesInput);
    return 0;
}

void NumeroDias(int numMes){
    if((numMes>12)||(numMes<1)){
        cout<<"Has ingresado un mes no válido.";
    } else {
        if((numMes==1)||(numMes==3)||(numMes==5)||(numMes==7)||(numMes==8)||(numMes==10)||(numMes==12)){
            cout<<"El mes ingresado tiene 31 días.";
        }
        else if((numMes==4)||(numMes==6)||(numMes==9)||(numMes==11)){
            cout<<"El mes ingresado tiene 30 días.";
        }
        else if(numMes==2){
            cout<<"El mes ingresado tiene 28 días.";
        } else{
            cout<<"Has ingresado un més no válido.";
        }
        
    }
}