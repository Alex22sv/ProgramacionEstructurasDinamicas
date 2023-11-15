#include <iostream>
#include <windows.h>

using namespace std;

// Estructuras
struct Casa {
    string estiloCasa;
    int cantidadHabitaciones;
    int numeroCasa;
    string ubicacion;
};
struct Nodo {
    struct Casa informacionCasa;
    struct Nodo *siguiente;
};
// Declaración de variables globales
struct Nodo *lista = nullptr;
// Declaración de funciones
void InsertarCasaAlInicio(struct Casa infoCasa);
void MostrarCasas();
void MostrarCasasPorEstilo(string estiloCasa);
void MostrarCasasConPosicion();
void EliminarCasaPorPosicion(int posicion);

int main(){
    int opcionMenu, opcionEstiloCasa, posicionCasa, opcionUbicacion;
    struct Casa nuevaCasa;
    string estiloCasaIngresada;
    bool mantenerseEnSistema = true;
    SetConsoleOutputCP(CP_UTF8);
    cout<<"\n-----Bienvenido al sistema de la residencial Elektro-----\n\n";
    do {
        cout<<"1. Insertar casa. \n2. Mostrar todas las casas. \n3. Mostrar casas por estilo. \n4. Eliminar una casa.\n5. Salir del sistema. \n... ";
        cin>>opcionMenu;
        switch (opcionMenu){
            case 1:
                cout<<"Ingrese el número de la casa: ";
                cin>>nuevaCasa.numeroCasa;
                cout<<"¿Qué tipo de estilo tiene la casa?\n1. Mediterránea. \n2. Contemporáneo. \n3. Minimalista. \n4. Nórdico. \n...";
                cin>>opcionEstiloCasa;
                switch (opcionEstiloCasa){
                    case 1:
                        nuevaCasa.estiloCasa = "Mediterránea";
                        break;
                    case 2:
                        nuevaCasa.estiloCasa = "Contemporáneo";
                        break;
                    case 3:
                        nuevaCasa.estiloCasa = "Minimalista";
                        break;
                    case 4:
                        nuevaCasa.estiloCasa = "Nórdico";
                        break;
                    default:
                        nuevaCasa.estiloCasa = "-";
                        break;
                }
                cout<<"Ingrese la cantidad de habitaciones: ";
                cin>>nuevaCasa.cantidadHabitaciones;
                cout<<"¿Dónde se ubica la casa?\n1. Norte. \n2. Sur. \n3. Este. \n4. Oeste. \n...";
                cin>>opcionUbicacion;
                switch (opcionUbicacion){
                    case 1:
                        nuevaCasa.ubicacion = "Norte";
                        break;
                    case 2:
                        nuevaCasa.ubicacion = "Sur";
                        break;
                    case 3:
                        nuevaCasa.ubicacion = "Este";
                        break;
                    case 4:
                        nuevaCasa.ubicacion = "Oeste";
                        break;
                    default:
                        nuevaCasa.ubicacion = "-";
                        break;
                }
                InsertarCasaAlInicio(nuevaCasa);
                system("pause");
                system("cls");
                break;
            case 2:
                MostrarCasas();
                system("pause");
                system("cls");
                break;
            case 3:
                cout<<"¿Qué tipo de estilo desea revisar?\n1. Mediterránea. \n2. Contemporáneo. \n3. Minimalista. \n4. Nórdico. \n...";
                cin>>opcionEstiloCasa;
                switch (opcionEstiloCasa){
                    case 1:
                        estiloCasaIngresada = "Mediterránea";
                        break;
                    case 2:
                        estiloCasaIngresada = "Contemporáneo";
                        break;
                    case 3:
                        estiloCasaIngresada = "Minimalista";
                        break;
                    case 4:
                        estiloCasaIngresada = "Nórdico";
                        break;
                    default:
                        cout<<"Has ingresado una opción no válida.\n";
                        return 0;
                        break;
                }
                MostrarCasasPorEstilo(estiloCasaIngresada);
                system("pause");
                system("cls");
                break;
            case 4:
                MostrarCasasConPosicion();
                if(lista!=nullptr){
                    cout<<"¿Cuál es la posición de la casa que deseas eliminar? ";
                    cin>>posicionCasa;
                    EliminarCasaPorPosicion(posicionCasa);
                }
                system("pause");
                system("cls");
                break;
            case 5:
                cout<<"Saliendo del sistema...\n";
                mantenerseEnSistema = false;
                system("pause");
                system("cls");
                break;
            default:
                cout<<"Has ingresado una opción no válida. Por favor, inténtelo de nuevo.\n";
                opcionMenu = 0;
                system("pause");
                system("cls");
                break;
        }
    } while (mantenerseEnSistema);
}

// Definición de funciones
void InsertarCasaAlInicio(struct Casa infoCasa){
    struct Nodo *nuevoNodo = new Nodo();
    nuevoNodo->informacionCasa = infoCasa;
    nuevoNodo->siguiente = nullptr;
    if(lista==nullptr){
        lista = nuevoNodo;
    } else {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    cout<<"La casa ha sido registrada correctamente.\n";
}
void MostrarCasas(){
    struct Nodo *temporal = lista;
    if(temporal!=nullptr){
        cout<<"--- Lista de casas: \n\n";
        while(temporal!=nullptr){
            cout<<"Número de casa: "<<temporal->informacionCasa.numeroCasa<<"\n";
            cout<<"Estilo de la casa: "<<temporal->informacionCasa.estiloCasa<<"\n";
            cout<<"Cantidad de habitaciones: "<<temporal->informacionCasa.cantidadHabitaciones<<"\n";
            cout<<"Ubicación de la casa: "<<temporal->informacionCasa.ubicacion<<"\n";
            cout<<"-----------------------------------------------\n";
            temporal = temporal->siguiente;
        }
    } else {
        cout<<"No hay casas actualmente registradas.\n";
    }
}
void MostrarCasasPorEstilo(string estiloCasa){
    struct Nodo *temporal = lista;
    if(temporal!=nullptr){
        cout<<"--- Casas con estilo "<<estiloCasa<<": \n\n";
        while(temporal!=nullptr){
            if(temporal->informacionCasa.estiloCasa==estiloCasa){
                cout<<"Número de casa: "<<temporal->informacionCasa.numeroCasa<<"\n";
                cout<<"Cantidad de habitaciones: "<<temporal->informacionCasa.cantidadHabitaciones<<"\n";
                cout<<"Ubicación de la casa: "<<temporal->informacionCasa.ubicacion<<"\n";
                cout<<"-----------------------------------------------\n";
            }
            temporal = temporal->siguiente;
        }
    } else {
        cout<<"No hay casas actualmente registradas.\n";
    }
}
void MostrarCasasConPosicion(){
    struct Nodo *temporal = lista;
    int posicionCasa = 1;
    if(temporal!=nullptr){
        cout<<"Lista de casas: \n";
        while(temporal!=nullptr){
            cout<<posicionCasa<<". Casa #"<<temporal->informacionCasa.numeroCasa<<"\n";
            temporal = temporal->siguiente;
            posicionCasa++;
        }
    } else {
        cout<<"No hay casas actualmente registradas.\n";
    }
}
void EliminarCasaPorPosicion(int posicion){
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;
    struct Nodo *temporal3;
    if((temporal->siguiente==nullptr)&&(posicion==1)){
        delete lista;
        lista = nullptr;
        cout<<"La casa ha sido eliminada correctamente.\n";
        return;
    }
    if(posicion==1){
        lista = temporal->siguiente;
        cout<<"La casa ha sido eliminada correctamente.\n";
        return;
    }
    while(posicion!=1){
        temporal2 = temporal;
        temporal = temporal->siguiente;
        temporal3 = temporal->siguiente;
        posicion--;
    }
    temporal2->siguiente = temporal3;
    delete temporal;
    temporal = nullptr;
    
}
