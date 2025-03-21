#include "ejercicio_1.h";
#include <iostream>
using namespace std;


int main (void){
    int n; //recibe input del usuario para el parametro n

    cout << "ingrese el tamaño (n) de su matriz cuadrada (nxn): ";
    cin >> n;

    vector<vector<int>> mine= create_matrix(n);
    print_square_matrix(mine, n); 

}
