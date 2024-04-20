/* 04/10/2023 */
#include <iostream>
#include <windows.h>

using namespace std;
/*   
    / ; () > [] ? : $ @ & %  # "" = _ !
*/
/*
    La información ya no es lineal.
    Partes de un árbol: raíz (root, solo hay 1 por árbol), padre (parent), hijo (child) y hojas (leafs, son los últimos hijos que no tienen hijos)
    Ejemplo de uso de árboles: explorador de archivos, expresiones matemáticas
    Propiedades de árboles: altura (num de niveles), cantidad de nodos, las ramas que son las conexiones entre nodos, profundidad
    Un árbol puede tener diferentes tipos de recorridos.
    Para formar un árbol, los números menores al root o parent van a la izquierda, los mayores van a la derecha.
    Veremos únicamente árboles binarios.
    No se pueden repetir valores.
    Tipos de árboles binarios: 
        - equilibrado (altura misma para izquierda y derecha para cada nodo)
        - degenerado (solo existe un nodo hoja y cada nodo no hoja tiene un solo hijo)
        - lleno (cada nodo tiene la misma cantidad de hijos)
        - completo (el árbol está lleno hasta el penúltimo nivel y el último tiene más nodos a la izquierda)
    Tipos de recorridos: 
        - in orden (izquierda->raíz->derecha)
        - pre orden (raíz->izquierda->derecha)
        - post orden (izquierda->derecha->raíz)
        Los árboles no son grafo, porque no tienen ciclos.
    Propiedades: grado, orden, nivel de un nodo, longitud.
*/

struct Nodo {
    int dato;
    struct Nodo *izquierdo;
    struct Nodo *derecho;

};
// ABB = árbol de búsqueda binario
struct Nodo *ABB = nullptr;

struct Nodo *Crear(int);
struct Nodo *Insertar(struct Nodo *, int);
void Borrar(struct Nodo *&, int n);
void Buscar(struct Nodo *&, int, struct Nodo *&);
void BuscarMenor(struct Nodo *&, struct Nodo *&);
void InOrden(struct Nodo *);
void PreOrden(struct Nodo *);
void PostOrden(struct Nodo *);
int ObtenerRaiz(struct Nodo *);
int ObtenerValorMenor(struct Nodo *);
int ObtenerValorMayor(struct Nodo *);

int main(){
    // Función que permite mostrar los caracteres especiales en la terminal
    SetConsoleOutputCP(CP_UTF8);
    int valor = 0, contador = 0;
    cout<<"¿Cuántos valores desea agregar? ";
    cin>>contador;
    for(int i = 0; i < contador; i++){
        cout<<"Ingrese un valor: ";
        cin>>valor;
        ABB = Insertar(ABB, valor);
    }
    cout<<"\nValor de la raíz: "<<ObtenerRaiz(ABB)<<"\n";
    cout<<"\nValor más pequeño: "<<ObtenerValorMenor(ABB)<<"\n";
    cout<<"\nValor más grande: "<<ObtenerValorMayor(ABB)<<"\n";
    cout<<"\nIn Orden: \n";
    InOrden(ABB);
    cout<<"\nPre Orden: \n";
    PreOrden(ABB);
    cout<<"\nPost Orden: \n";
    PostOrden(ABB);
    cout<<"\n¿Qué valor desea borrar? ";
    cin>>valor;
    Borrar(ABB, valor);
    cout<<"\nIn Orden: \n";
    InOrden(ABB);
    cout<<"\nPre Orden: \n";
    PreOrden(ABB);
    cout<<"\nPost Orden: \n";
    PostOrden(ABB);
    return 0;
}

struct Nodo *Crear(int n){
    struct Nodo *nuevoNodo = new Nodo();
    nuevoNodo->dato = n;
    nuevoNodo->izquierdo = nullptr;
    nuevoNodo->derecho = nullptr;
    return nuevoNodo;
}
struct Nodo *Insertar(struct Nodo *ABB, int n){
    if(ABB==nullptr){
        return Crear(n);
    }

    if(n<ABB->dato){
        ABB->izquierdo = Insertar(ABB->izquierdo, n);
    } else {
        ABB->derecho = Insertar(ABB->derecho, n);
    }
    return ABB;
}
void Borrar(Nodo *&ABB, int n){
    struct Nodo *padre = nullptr;
    // ABB nodo raíz
    struct Nodo *aux = ABB;
    Buscar(aux, n, padre);
    //Si el árbol no tiene nodos;
    if(aux==nullptr){
        return;
    }
    // Borrar un nodo hoja
    if((aux->izquierdo==nullptr) && (aux->derecho==nullptr)){
        if(aux==ABB){
            ABB = nullptr;
        } else {
            if(padre->izquierdo==nullptr){
                padre->izquierdo = nullptr;
            } else {
                padre->derecho = nullptr;
            }
        }
        delete aux;
    } else if ((aux->izquierdo) && (aux->derecho)){
        // Borrar nodo con 2 hijos (hijos en der. e izq.)
        //Buscamos en el subárbol derecho el nodo menor
        struct Nodo *sucesor;
        BuscarMenor(ABB, sucesor);
        int val = sucesor->dato;
        Borrar(ABB, sucesor->dato);
        aux->dato = val;
    } else {
        // Borrar un nodo con un solo hijo
        struct Nodo *hijo;
        if(aux->izquierdo){
            hijo = aux->izquierdo;
        } else {
            hijo = aux->derecho;
        }
        if(aux!=ABB){
            if(aux==padre->izquierdo){
                padre->izquierdo = hijo;
            } else  {
                padre->derecho = hijo;
            }
        } else {
            ABB = hijo;
        }
    }
}
void Buscar(struct Nodo *&ABB, int n, struct Nodo *&padre){
    while((ABB!=nullptr) && (ABB->dato!=n)){
        padre = ABB;
        if(n<ABB->dato){
            ABB = ABB->izquierdo;
        } else {
            ABB = ABB->derecho;
        }
    }
}
void BuscarMenor(struct Nodo *&ABB, struct Nodo *&aux){
    while(aux!=nullptr){
        aux = aux->izquierdo;
    }
    ABB = aux;
}
void InOrden(struct Nodo *ABB){
    if(ABB==nullptr){
        return;
    } else {
        InOrden(ABB->izquierdo);
        cout<<ABB->dato<<" | ";
        InOrden(ABB->derecho);
    }
}
void PreOrden(struct Nodo *ABB){
    if(ABB==nullptr){
        return;
    } else {
        cout<<ABB->dato<<" | ";
        PreOrden(ABB->izquierdo);
        PreOrden(ABB->derecho);
    }
}
void PostOrden(struct Nodo *ABB){
    if(ABB==nullptr){
        return;
    } else {
        PostOrden(ABB->izquierdo);
        PostOrden(ABB->derecho);
        cout<<ABB->dato<<" | ";
    }
}
int ObtenerRaiz(struct Nodo *ABB){
    if(ABB==nullptr){
        return -1;
    } else {
        return ABB->dato;
    }
}
int ObtenerValorMenor(struct Nodo *ABB){
    struct Nodo *aux = ABB;
    while((aux)&&(aux->izquierdo!=NULL)){
        aux = aux->izquierdo;
    }
    return aux->dato;
}
int ObtenerValorMayor(struct Nodo *ABB){
    struct Nodo *aux = ABB;
    while((aux)&&(aux->derecho!=NULL)){
        aux = aux->derecho;
    }
    return aux->dato;
}