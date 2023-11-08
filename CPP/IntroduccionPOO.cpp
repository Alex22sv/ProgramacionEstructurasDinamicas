/* 08/11/2023 */
#include <iostream>
#include <windows.h>

using namespace std;

/*
    Es uno de los actuales paradigmas predominantes en el desarrollo de software, habiendo reemplazado al paradigma estructurado.
    la idea/*  */ fundamental de POO es combinar (encapsular) en una única unidad tanto los datos como las funciones que operan sobre los datos.
    La abstracción permite seleccionar las característica srelevantes dentro de un conjunto e identificar comportamientos comunes.
    El encapsulamiento es la ocultación de la información, público, protegido y privado.
    Las etapas necesarias para modelar un sistema empleando POO son:
        1. Identificación de los objetos del problema.
        2. Agrupamiento en clases (tipo de objetos) de los objetos con características y comportamiento comunes.
        3. Identificación de los datos y operaciones de cada una de las clases.
        4. Identificación de las relaciones existentes entre las diferentes clases de modelo.
    Los atributos o características son las propiedades de los objetos.
    El comportamiento (método) es la acción que realizan los objetos del mundo real en respuesta a un determinado estímulo, en otras palabras las operaciones definidas para los objetos.
    Las funciones miembro también se conocen como métodos dependiendo de los lenguajes de programación
*/
/*
    Atributos de un atleta: Estatura, peso, posición en el deporte, salud
    Métodos de un atleta: Ganar carrera, entrenar, mantenerse en forma
    Una clase está compuesta por atributos y métodos. Es un molde genérico.
    Booch dice que es "un conjunto de objetos que comparten una estructura y comportamiento comunes.";
    Los atributos (datos) son variables simples
    Los métodos (funciones) son funciones simples que actúan sobre los atributos (datos).
    Recomendado: las funciones son públicas y los datos son privados.
    Recomendado 2: Agregar un archivo extra para la clase, usar snippers.
*/
// Sintaxis
/* class Prueba {
    // Por defecto todos los datos son públicos
    private:
        int datos;
    public: 
        void funcdemo(int d){
            datos = d;
        }
}; */
class Atleta{
    public:
        string nombre;
        int year;
        float altura;
        float peso;
        float IMC; // Almacenar el valor que retorna la función
    public:
        int CalcularEdad(int);
        float CalcularIMC(float, float);
        /* // Sobrecarga de funciones
        ~CalcularEdad(); */
};
// Constructores:
// La función CalcularEdad está dentro de la clase Atleta, eso es lo que indica el ::
int Atleta::CalcularEdad(int year){
    return 2023 - year;
}
float Atleta::CalcularIMC(float peso, float altura){
    return (peso)/((altura)*(altura));
}

/*
// sOBRECARGA DE FUNCIONES
Atleta::~CalcularEdad(){

} */

int main(){
    // Función que permite mostrar los caracteres especiales en la terminal
    SetConsoleOutputCP(CP_UTF8);
    Atleta atleta1;
    atleta1.nombre = "Alex";
    atleta1.altura = 1.80;
    atleta1.peso = 62;
    atleta1.year = 2005;
    atleta1.IMC = atleta1.CalcularIMC(atleta1.peso, atleta1.altura);
    cout<<"Nombre del atleta: "<<atleta1.nombre<<"\nAltura: "<<atleta1.altura<<" metros\nPeso: "<<atleta1.peso<<" kilogramos\nEdad: "<<atleta1.CalcularEdad(atleta1.year)<<" años\nIMC: "<<atleta1.IMC<<"\n";
    return 0;
}
