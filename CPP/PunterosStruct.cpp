/* 28/08/2023 */
#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;
/*   
    / ; () > [] ? : $ @ & %  # "" = _ !
*/

struct Producto {
    string nombre;
    float precio;
} producto1, *ptr1; //global

struct Productos {
    string nombre;
    float precio;
    string categoria[2];
} *ptr, producto[3];

struct Temperatura{
    float alta;
    float baja;
} temp;

struct BolsaValores{
    string nombreEmpresa;
    float compra;
    float venta;
}empresa;

void GuardarDatos();
void ImprimirDatos();
void LeerTemperatura(float &actual);
void RegistroActual(Temperatura &t);
void LeerBolsaValores(float &actual);
vois RegistroBolsaValores(struct BolsaValores &s);

int main(){
    // Función que permite mostrar los caracteres especiales en la terminal
    SetConsoleOutputCP(CP_UTF8);

    /*
    struct Producto producto2; //local
    Producto producto3; //local
    Producto *ptr2;
    
    ptr1 = &producto1; // asignar dirección
    ptr1->nombre = "Cuaderno"; // acceder con puntero
    ptr1->precio = 1.25; 
    */
    
    
    // GuardarDatos();
    // ImprimirDatos();


    temp.alta = 0;
    temp.baja = 100;
    while (true){
        RegistroActual(temp);
        cout<<"Temperaturas: "<<temp.baja<<" - "<<temp.alta;
        Sleep(3000);
    }
    
    empresa.venta = 0;
    empresa.compra = 800;
    cout<<"Ingrese el nombre de la empresa: ";
    cin>>empresa.nombreEmpresa;
    cout<<"El valor de la bolsa de: "<<empresa.nombreEmpresa;<<"\n";
    while(true){
        RegistroBolsaValores(empresa);
        cout<<"Valores: "<<empresa.venta<<" -- "<<empresa.float compra;
        Sleep(2000);
    }   
    return 0;
}

void GuardarDatos(){
    string nombreProducto;
    float precioProducto;
    string categorias[2];
    for (int i = 0; i < 3; i++){
        cout<<"Ingrese el nombre del producto #"<<i+1<<": ";
        cin>>nombreProducto;
        cout<<"Ingrese el precio del producto #"<<i+1<<": $";
        cin>>precioProducto;
        ptr = &producto[i];
        ptr->nombre = nombreProducto;
        ptr->precio = precioProducto;
        for (int j = 0; j < 2; j++){
            cout<<"Ingrese la categoría #"<<j+1<<" del producto #"<<i+1<<": ";
            cin>>categorias[j];
            ptr->categoria[j] = categorias[j];
        }
    }    

}
void ImprimirDatos(){
    cout<<"\n\nImprimiendo datos...\n\n";
    for (int i = 0; i < 3; i++){
        cout<<"\n** Producto #"<<i+1<<" **\n";
        ptr = &producto[i];
        for (int j = 0; j < 2; j++)
        {
            cout<<"Nombre: "<<ptr->nombre<<" | Precio: $"<<ptr->precio<<" | Categoría #"<<j+1<<": "<<ptr->categoria[j]<<"\n";
        }
        
    }
    
}

void LeerTemperatura(float &actual){
    // Crear una temperatura aleatoria
    int t = time(NULL);
    srand(t);
    cout<<" - tiempo: "<<t;
    actual = rand() % (48+1);
}
void RegistroActual(Temperatura &t){
    float actual = 0.0;
    LeerTemperatura(actual);
    cout<<" -> Lectura actual: "<<actual<<"\n";
    if(actual>t.alta){
        t.alta = actual;
    }
    if(actual<t.alta){
        t.baja = actual;
    }
}
void LeerBolsaValores(float &actual){
    int t = time(NULL);
    srand(t);
    cout<<" - valor: "<<t;
    actual = rand() % (1000+1);
}
void RegistroBolsaValores(struct BolsaValores &s){
    float actual = 0;
    LeerBolsaValores(actual);
    cout<<" -> Lctura actual: "<<actual<<"\n";
    if(actual>=s.venta){
        s.venta = actual;
    }
    if(actual<s.compra){
        s.compra = actual;
    }
}
/* / ; () > [] ? : $ @ & %  # "" = _ ! */