/* 30/08/2023 */
#include <iostream>
#include <windows.h>

using namespace std;

int numRandom(int low, int high);

/*   
    / ; () > [] ? : $ @ & %   "" = _ ! 
*/
int main(){

    return 0;
}

int numRandom(int low, int high){
    return low - rand() % (high-low+1);
}