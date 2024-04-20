/* 4/09/2023 */
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <ctime>

using namespace std;

/*  
/ ; () > [] ? : $ @ & %  # "" =  _   
*/

struct BombaGasolinera {
    int cantGasolina;
    int cantDiesel;
} bombaGasolinera;

void LeerCambioBombaGasolinera(float &actual);
void ActualizarBombaGasolinera(struct BombaGasolinera &bm, int opcion);

void ResultadosArea(float b, float h, float &areaT, float &areaR);

int main(){
    // Función que permite mostrar los caracteres especiales en la terminal
    SetConsoleOutputCP(CP_UTF8);
    int opcion;
    cout<<"Bienvenido! \n¿Deseas llenar gasolina o diesel?\n1. Gasolina\n2. Diésel\n...";
    cin>>opcion;
    while(true){
        ActualizarBombaGasolinera(bombaGasolinera, opcion);
        if(opcion==1){
            cout<<"Valor de gasolina: "<<bombaGasolinera.cantGasolina<<"\n";
        } else if(opcion==2){
            cout<<"Valor de diésel: "<<bombaGasolinera.cantDiesel<<"\n";
        }
        if(bombaGasolinera.cantGasolina>=100||bombaGasolinera.cantDiesel>=100){
            cout<<"\nBomba de gasolinera llena.\n";
            return 0;
        }
        Sleep(2000);
    }
    int option;
    float valorBase, valorAltura, areaTriangulo, areaRectangulo;
    cout<<"¿Deseas calcular el área del triángulo o del rectángulo?\n1. Triángulo\n2. Rectángulo\n...";
    cin>>option;
    cout<<"Ingrese el valor de la base: ";
    cin>>valorBase;
    cout<<"Ingrese el valor de la altura: ";
    cin>>valorAltura;
    ResultadosArea(valorBase, valorAltura, areaTriangulo, areaRectangulo);
    if(option==1){
        cout<<"El área es: "<<areaTriangulo;
    } else if(option==2){
        cout<<"El área es: "<<areaRectangulo;
    } else {
        cout<<"Opción no válida";
    }
}

void LeerCambioBombaGasolinera(float &actual){
    int t = time(NULL);
    srand(t);
    //cout<<" - valor: "<<t;
    actual = rand() % (10+1);
}
void ActualizarBombaGasolinera(struct BombaGasolinera &bm, int opcion){
    float actual = 0.00;
    LeerCambioBombaGasolinera(actual);
    //cout<<"Lectura actual: "<<actual<<"\n";
    if(opcion==1){
        bm.cantGasolina += actual;
    } else if(opcion==2){
        bm.cantDiesel += actual; 
    } else {
        cout<<"Opción no definida.";
    }
}

void ResultadosArea(float b, float h, float &areaT, float &areaR){
    areaT = (b*h)/2;
    areaR = b*h;
}