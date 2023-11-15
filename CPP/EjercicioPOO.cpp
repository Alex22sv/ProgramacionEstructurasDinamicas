/* 15/11/2023 */
#include <iostream>
#include <windows.h>
using namespace std;

class Car{
    // Establecer los atributos como privados y métodos como públicos
    private:
        string marca;
        string modelo;
        string color;
        bool estado;
        int anio;
        int kilometraje;
        float capacidadTanque; // capacidad máxima 10 galones 
    public:
        string Estado();
        // Definir un constructor para la inicialización del objeto con los parámetros que se consideren necesarios
        Car(string _marca, string _modelo, string _color, bool _estado, int _anio, int _kilometraje, float _capacidadTanque);
        // Definir los métodos get y set para los atributos de la clase
        void setMarca(string _marca);
        string getMarca();
        void setModelo(string _modelo);
        string getModelo();
        void setColor(string _color);
        string getColor();
        void setEstado(bool _estado);
        bool getEstado();
        void setAnio(int _anio);
        int getAnio();
        void setKilometraje(int _kilometraje);
        int getKilometraje();
        void setCapacidadTanque(float _capacidadTanque);
        float getCapacidadTanque(); 
        // Declarar el método para calcular los kilometros recorridos
        int CalcularKilometrosRecorridos(int kmActual);
        // Declarar el método para calcular el kilometraje
        int CalcularKilometraje(int kmRecorridos);
        // Declarar el método para calcular el consumo de gasolina por kilómetro
        float CalcularConsumoGasolina(int kmRecorridos);
        // Convertir galones a litros
        float ConvertirGalonesLitros(float galones);
};

// Declarar el constructor parametrizado para inicializar el objeto
Car::Car(string _marca, string _modelo, string _color, bool _estado, int _anio, int _kilometraje, float _capacidadTanque){
    marca = _marca;
    modelo = _modelo;
    color = _color;
    estado = _estado;
    anio = _anio;
    kilometraje = _kilometraje;
    capacidadTanque = _capacidadTanque;
}
// Declarar los métodos get y set para los atributos de la clase
void Car::setMarca(string _marca){
    marca = _marca;
}
string Car::getMarca(){
    return marca;
}
void Car::setModelo(string _modelo){
    modelo = _modelo;
}
string Car::getModelo(){
    return modelo;
}
void Car::setColor(string _color){
    color = _color;
}
string Car::getColor(){
    return color;
}
void Car::setEstado(bool _estado){
    estado = _estado;
}
bool Car::getEstado(){
    return estado;
}
void Car::setAnio(int _anio){
    anio = _anio;
}
int Car::getAnio(){
    return anio;
}
void Car::setKilometraje(int _kilometraje){
    kilometraje = _kilometraje;
}
int Car::getKilometraje(){
    return kilometraje;
}
void Car::setCapacidadTanque(float _capacidadTanque){
    capacidadTanque = _capacidadTanque;
}
float Car::getCapacidadTanque(){
    return capacidadTanque;
}
// Definir un método para calcular los kilometros recorridos (kmRecorridos = kmActual - Kilometraje)
int Car::CalcularKilometrosRecorridos(int kmActual){
    return kmActual-kilometraje;
}
// Definir un método para determinar el kilometraje del carro  (kilometraje suma con kmRecorridos)
int Car::CalcularKilometraje(int kmRecorridos){
    kilometraje += kmRecorridos;
    return kilometraje;
}
// Definir un método para determinar el consumo de gasolina cada 100km  (kmRecorridos / litrosConsumidos)
float Car::CalcularConsumoGasolina(int kmRecorridos){
    float tanqueActual = 10-capacidadTanque;
    float LitrosConsumidos = ConvertirGalonesLitros(tanqueActual);
    //cout<<tanqueActual<<" - "<<LitrosConsumidos<<"\n";
    return kmRecorridos/tanqueActual;
}
float Car::ConvertirGalonesLitros(float galones){
    return (galones*3.78);
}

// Métodos adicionales necesarios
//  Conversión de galones a litros ( 1 galon = 3.78 lts)
//  Calcular los litrosConsumidos = capacidadTanqueActual - capacidadTanque

string Car::Estado(){
    if (estado == true){
        return "encendido";
    } else {
        return "apagado";
    }
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    int kilometroActual;
    Car carro = Car("Toyota", "Corolla", "Gris", true, 2015, 1000, 7.5);
    cout<<"Ingrese el kilómetro actual: ";
    cin>>kilometroActual;
    int kilometrosRecorridos = carro.CalcularKilometrosRecorridos(kilometroActual);
    int nuevoKilometraje = carro.CalcularKilometraje(kilometrosRecorridos);
    float consumoGasolina = carro.CalcularConsumoGasolina(kilometrosRecorridos);
    cout<<"\n";
    cout<<carro.getMarca()<<" "<<carro.getModelo()<<" - año "<<carro.getAnio()<<"\n";
    cout<<"Color "<<carro.getColor()<<" | Estado: "<<carro.Estado()<<"\n";
    cout<<"Kilometraje: "<<carro.getKilometraje()<<" km | Capacidad del tanque: "<<carro.getCapacidadTanque()<<" gal\n";
    cout<<"Kilometros recorridos: "<<kilometrosRecorridos<<" km | Consumo de gasolina: "<<consumoGasolina<<" km/gal\n";
    return 0;
}