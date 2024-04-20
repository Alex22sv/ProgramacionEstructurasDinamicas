/* 21/08/2023 */
#include <iostream>
#include <windows.h>

using namespace std;
/*   
    / ; () > [] ? : $ @ & %  # "" = _ !
*/

int main(){
    // Función que permite mostrar los caracteres especiales en la terminal
    SetConsoleOutputCP(CP_UTF8);

    int n = 33;
    int &r = n;
    cout<<"&n = "<<&n<<", &r = "<<&r<<"\n";

    cout<<"\n\n";

    int n1 = 35;
    int *p1 = &n1;
    int &r1 = *p1;
    cout<<"r  = "<<r1<<"\n";

    cout<<"\n\n";
    
    int n2 = 35;
    int *p2 = &n2;
    cout<<"*p = "<<*p2<<"\n";

    cout<<"\n\n";

    int a = 35;
    int *ptr, *ptr2; 
    ptr = &a;
    ptr2 = ptr;
    if(&ptr==&ptr2){
        cout<<"Son iguales.\n";
    } else { 
        cout<<"No son iguales.\n";
    }

    cout<<"\n\n";
    return 0;
}
