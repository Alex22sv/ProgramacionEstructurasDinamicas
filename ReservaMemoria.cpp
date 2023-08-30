/* 30/08/2023 */
#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

/*  
/ ; () > [] ? : $ @ & %  # "" =  _   
*/

int main(){
    // Función que permite mostrar los caracteres especiales en la terminal
    SetConsoleOutputCP(CP_UTF8);
    int *ptr;
    /*
    // Hacer reserva de memoria con C (no es C++)
    ptr = (int*)malloc(100*sizeof(int)); // Hacer reserva de memoria con malloc()
    free(ptr); // Hacer una liberación de memoria
    return 0;
    */
    int tamanio = 4;
    ptr = new int[tamanio]; // Hacer reserva de memoria (ebn este caso un arreglo de 4 valores)

    /* Si no está disponible el espacio solicitado, da NULL */
    if(ptr==NULL){
        cout<<"Error en asignación de memoria.";
    } else{
        cout<<"Dirección de memoria: "<<ptr;
    }

    delete ptr; //Hacer liberación de memoria
}