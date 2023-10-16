/* 16/10/2023 */
#include <iostream>
#include <windows.h>

using namespace std;

// Estructuras
struct Comida {
    string nombre;
    float precio;
};
struct Orden {
    int ordenId;
    string nombre;
    struct Comida comidas[3];
    struct Comida bebidas[2];
    struct Comida entradas[2];
    string metodoPago;
    string tipoPedido;
    string direccionDomicilio;
};
struct Nodo {
    struct Orden orden;
    struct Nodo *siguiente;
};
struct Comida menuComidas[] = {
    {"Pizza personal de pepperoni - $5.99", 5.99},
    {"Pizza personal de jamón - $5.99", 5.99},
    {"Pizza personal de carne - $5.99", 5.99},
    {"Pizza familiar de pepperoni - $8.99", 8.99},
    {"Pizza familiar de jamón - $8.99", 8.99},
    {"Pizza familiar  de carne - $8.99", 8.99}
};
struct Comida menuBebidas[] = {
    {"Botella de agua - $1.00", 1.00},
    {"Soda en lata - $0.80", 0.80},
    {"Jugo natural - $1.25", 1.25}
};
struct Comida menuEntradas[] = {
    {"Orden de 5 palitroques - $3.99", 3.99},
    {"Orden de 4 panes con ajo - $3.99", 3.99},
    {"Orden de 6 nudillos con ajo - $3.99", 3.99}
};

// Variables globales
struct Nodo *lista = nullptr;
int contadorPedidos = 0;
// Declaración de funciones
void IniciarSesion();
void Menu();
void AgregarOrden(struct Orden);
void DespacharOrden(string);
void CancelarOrden();
float TotalVentas();
void MostrarOrdenes();
void MostrarIdOrdenes(string);

int main(){
    //SetConsoleOutputCP(CP_UTF8);
    IniciarSesion();
    return 0;
};

void IniciarSesion(){
    string usuario, contrasena;
    cout<<"Sistema de inicio de sesión de la Pizzería.\n";
    cout<<"Ingrese su usuario: ";
    cin>>usuario;
    cout<<"Ingrese su contraseña: ";
    cin>>contrasena;
    if((usuario=="admin")&&(contrasena=="1234")){
        Menu();
    } else {
        cout<<"Usuario o contraseña incorrectos.";
    }
}
void Menu(){
    int opcion = 0, opcionPlato, opcionBebida, opcionEntrada, opcionTipoPedido, opcionMetodoPago;
    bool mantenerEnSistema = true;
    string nombre, metodoPago, tipoPedido, direccionDomicilio;
    struct Comida comidasElegidas[3], bebidasElegidas[3], entradasElegidas[3];
    struct Orden nuevaOrden;
    while (mantenerEnSistema){
        cout<<"\n----- Menú del sistema -----\n";
        cout<<" 1. Agregar orden a domicilio \n";
        cout<<" 2. Agregar orden en restaurante \n";
        cout<<" 3. Despachar pedido a domicilio \n";
        cout<<" 4. Despachar pedido en restaurante \n";
        cout<<" 5. Cancelar pedido \n";
        cout<<" 6. Calcular total de ventas \n";
        cout<<" 7. Mostrar órdenes activas \n";
        cout<<" 8. Cerrar sesión \n";
        cout<<"...... ";
        cout<<"Ingrese la opción: ";
        
        cin>>opcion;
        switch (opcion){
            case 1:
                // Agregar orden a domicilio
                nuevaOrden.ordenId = ++contadorPedidos;
                cout<<"Ingrese su nombre: ";
                cin>>nuevaOrden.nombre;
                cout<<"A continuación se le presentará el menú de platos principales (puedes escoger máximo 3): \n";
                for (int i = 0; i < 3; i++){
                    for (int j = 0; j < 6; j++){
                        cout<<j+1<<". "<<menuComidas[j].nombre<<"\n";
                    }
                    cout<<"Ingrese la comida #"<<i+1<<" (si ya no desea agregar nada ingrese 0): ";
                    cin>>opcionPlato;
                    if(opcionPlato!=0){
                        nuevaOrden.comidas[i] = menuComidas[opcionPlato-1];
                    } else {
                        nuevaOrden.comidas[i] = {"", 0.00};
                    }
                }
                cout<<"A continuación se le presentará el menú de bebidas (puedes escoger máximo 2): \n";
                for (int i = 0; i < 2; i++){
                    for (int j = 0; j < 3; j++){
                        cout<<j+1<<". "<<menuBebidas[j].nombre<<"\n";
                    }
                    cout<<"Ingrese la bebida #"<<i+1<<" (si ya no desea agregar nada ingrese 0): ";
                    cin>>opcionBebida;
                    if(opcionBebida!=0){
                        nuevaOrden.bebidas[i] = menuBebidas[opcionBebida-1];
                    } else {
                        nuevaOrden.bebidas[i] = {"", 0.00};
                    }
                }
                cout<<"A continuación se le presentará el menú de entradas (puedes escoger máximo 2): \n";
                for (int i = 0; i < 2; i++){
                    for (int j = 0; j < 3; j++){
                        cout<<j+1<<". "<<menuEntradas[j].nombre<<"\n";
                    }
                    cout<<"Ingrese la entrada #"<<i+1<<" (si ya no desea agregar nada ingrese 0): ";
                    cin>>opcionEntrada;
                    if(opcionEntrada!=0){
                        nuevaOrden.entradas[i] = menuEntradas[opcionEntrada-1];
                    } else {
                        nuevaOrden.entradas[i] = {"", 0.00};
                    }
                }
                opcionTipoPedido = 2;
                nuevaOrden.tipoPedido = "A domicilio";
                cout<<"Ingrese el método de pago: \n1. Efectivo\n2. Tarjeta de crédito (si el pedido es a domicilio, sólo este método será válido)\n...";
                cin>>opcionMetodoPago;
                if((opcionMetodoPago==1)&&(opcionTipoPedido==1)){
                    nuevaOrden.metodoPago = "Efectivo";
                } else {
                    nuevaOrden.metodoPago = "Tarjeta de crédito";
                }
                if(opcionTipoPedido==2){
                    cout<<"Ingrese su dirección del domicilio: ";
                    cin>>nuevaOrden.direccionDomicilio;
                } else {
                    nuevaOrden.direccionDomicilio = "local";
                }
                AgregarOrden(nuevaOrden);
                break;
            case 2:
                // Agregar orden a restaurante
                nuevaOrden.ordenId = ++contadorPedidos;
                cout<<"Ingrese su nombre: ";
                cin>>nuevaOrden.nombre;
                cout<<"A continuación se le presentará el menú de platos principales (puedes escoger máximo 3): \n";
                for (int i = 0; i < 3; i++){
                    for (int j = 0; j < 6; j++){
                        cout<<j+1<<". "<<menuComidas[j].nombre<<"\n";
                    }
                    cout<<"Ingrese la comida #"<<i+1<<" (si ya no desea agregar nada ingrese 0): ";
                    cin>>opcionPlato;
                    if(opcionPlato!=0){
                        nuevaOrden.comidas[i] = menuComidas[opcionPlato-1];
                    } else {
                        nuevaOrden.comidas[i] = {"", 0.00};
                    }
                }
                cout<<"A continuación se le presentará el menú de bebidas (puedes escoger máximo 2): \n";
                for (int i = 0; i < 2; i++){
                    for (int j = 0; j < 3; j++){
                        cout<<j+1<<". "<<menuBebidas[j].nombre<<"\n";
                    }
                    cout<<"Ingrese la bebida #"<<i+1<<" (si ya no desea agregar nada ingrese 0): ";
                    cin>>opcionBebida;
                    if(opcionBebida!=0){
                        nuevaOrden.bebidas[i] = menuBebidas[opcionBebida-1];
                    } else {
                        nuevaOrden.bebidas[i] = {"", 0.00};
                    }
                }
                cout<<"A continuación se le presentará el menú de entradas (puedes escoger máximo 2): \n";
                for (int i = 0; i < 2; i++){
                    for (int j = 0; j < 3; j++){
                        cout<<j+1<<". "<<menuEntradas[j].nombre<<"\n";
                    }
                    cout<<"Ingrese la entrada #"<<i+1<<" (si ya no desea agregar nada ingrese 0): ";
                    cin>>opcionEntrada;
                    if(opcionEntrada!=0){
                        nuevaOrden.entradas[i] = menuEntradas[opcionEntrada-1];
                    } else {
                        nuevaOrden.entradas[i] = {"", 0.00};
                    }
                }
                opcionTipoPedido = 1;
                nuevaOrden.tipoPedido = "En restaurante";
                cout<<"Ingrese el método de pago: \n1. Efectivo\n2. Tarjeta de crédito (si el pedido es a domicilio, sólo este método será válido)\n...";
                cin>>opcionMetodoPago;
                if((opcionMetodoPago==1)&&(opcionTipoPedido==1)){
                    nuevaOrden.metodoPago = "Efectivo";
                } else {
                    nuevaOrden.metodoPago = "Tarjeta de crédito";
                }
                if(opcionTipoPedido==2){
                    cout<<"Ingrese su dirección del domicilio: ";
                    cin>>nuevaOrden.direccionDomicilio;
                } else {
                    nuevaOrden.direccionDomicilio = "local";
                }
                AgregarOrden(nuevaOrden);
                break;
            case 3:
                // Despachar órdenes a domicilio
                DespacharOrden("A domicilio");
                break;
            case 4:
                // Despachar órdenes a restaurante
                DespacharOrden("En restaurante");
                break;
            case 5:
                // Cancelar orden (solo administrador)
                CancelarOrden();
                break;
            case 6: 
                // Calcular total de ventas
                cout<<"El total de ventas es: $"<<TotalVentas()<<"\n";
                break;
            case 7:
                // Mostar órdenes activas
                MostrarOrdenes();
                break;
            case 8:
                // Cerrar sesión
                cout<<"Cerrando sesión, saliendo del sistema...";
                mantenerEnSistema = false;
                break;
            default:
                // Has ingresado una opción no válida.
                cout<<"Has ingresado una opción no válida, inténtalo de nuevo.";
                break;
        }
    }
}

void AgregarOrden(struct Orden nuevaOrden){
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal = lista;
    nuevoNodo->orden = nuevaOrden;
    nuevoNodo->siguiente = nullptr;
    if(lista==nullptr){
        lista = nuevoNodo;
    } else {
        while(temporal->siguiente!=nullptr){
            temporal = temporal->siguiente;
        }
        temporal->siguiente = nuevoNodo;
    }
    cout<<"La órden ha sido agregada con éxito.\n";
}
void DespacharOrden(string tipoPedido){
    int numOrden = 0;
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;
    bool ordenEncontrada = false;
    MostrarIdOrdenes(tipoPedido);
    cout<<"¿Qué número de órden deseas despachar? ";
    cin>>numOrden;
    while(numOrden!=temporal->orden.ordenId){
        temporal2 = temporal;
        temporal = temporal->siguiente;
    }
    if(numOrden==temporal->orden.ordenId){
        temporal2 = temporal->siguiente;
        temporal->siguiente = temporal2;
        delete temporal;
        temporal = nullptr;
        cout<<"La órden #"<<numOrden<<" ha sido despachada.\n";
    } else {
        cout<<"La órden #"<<numOrden<<" no ha sido encontrada.\n";
    }
}
void CancelarOrden(){
    int numOrden;
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;
    bool ordenEncontrada = false;
    MostrarIdOrdenes("");
    cout<<"¿Qué número de órden desea despachar? ";
    cin>>numOrden;
    while(numOrden!=temporal->orden.ordenId){
        temporal2 = temporal;
        temporal = temporal->siguiente;
    }
    if(numOrden==temporal->orden.ordenId){
        temporal2 = temporal->siguiente;
        temporal->siguiente = temporal2;
        delete temporal;
        temporal = nullptr;
        cout<<"La órden #"<<numOrden<<" ha sido cancelada.\n";
    } else {
        cout<<"La órden #"<<numOrden<<" no ha sido encontrada.\n";
    }
}
float TotalVentas(){
    float totalVentas = 0.00;
    struct Nodo *temporal = lista;
    if(lista!=nullptr){
        while(temporal!=nullptr){
            for(int i = 0; i < 3; i++){
                totalVentas += temporal->orden.comidas[i].precio;
            }
            for(int j = 0; j < 2; j++){
                totalVentas += temporal->orden.bebidas[j].precio;
            }
            for(int h = 0; h < 2; h++){
                totalVentas += temporal->orden.entradas[h].precio;
            }
            temporal = temporal->siguiente;
        }
    }
    return totalVentas;
}
void MostrarOrdenes(){
    struct Nodo *temporal = lista;
    if(lista!=nullptr){
        cout<<"\n------------------------------------------\n";
        while(temporal!=nullptr){
            cout<<"Órden #"<<temporal->orden.ordenId<<"\n";
            cout<<"Nombre: "<<temporal->orden.nombre<<"\n";
            for (int i = 0; i < 3; i++){
                if(temporal->orden.comidas[i].nombre!=""){
                    cout<<"- Plato principal: "<<temporal->orden.comidas[i].nombre<<"\n";
                }
            }
            for (int j = 0; j < 2; j++){
                if(temporal->orden.bebidas[j].nombre!=""){
                    cout<<"+ Bebida: "<<temporal->orden.bebidas[j].nombre<<"\n";
                }
            }
            for (int h = 0; h < 2; h++){
                if(temporal->orden.entradas[h].nombre!=""){
                    cout<<"- Entrada: "<<temporal->orden.entradas[h].nombre<<"\n";
                }
            }
            cout<<"Método de pago: "<<temporal->orden.metodoPago<<"\n";
            cout<<"Tipo de pedido: "<<temporal->orden.tipoPedido<<"\n";
            if(temporal->orden.tipoPedido=="A domicilio"){
                cout<<"Dirección: "<<temporal->orden.direccionDomicilio<<"\n";
            }
            cout<<"------------------------------------------\n\n";
            temporal = temporal->siguiente;
        }
    } else {
        cout<<"No hay órdenes activas actualmente.\n";
    }
}
void MostrarIdOrdenes(string tipoPedido){
    struct Nodo *temporal = lista;
    if(lista!=nullptr){
        cout<<"Número de órdenes activas: \n";
        while(temporal!=nullptr){
            if((tipoPedido=="")||(tipoPedido == temporal->orden.tipoPedido)){
                cout<<"Órden #"<<temporal->orden.ordenId<<" a nombre de "<<temporal->orden.nombre<<"\n";
            }
            temporal = temporal->siguiente;
        }
    } else {
        cout<<"No hay órdenes activas actualmente.\n";
    }
}