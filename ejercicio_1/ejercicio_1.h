#pragma once
#include <vector>
#include <iostream>
using namespace std;
//Funciones

//funcion del ejercicio 1-a:

//Crea matriz de nxn utilizando vector, el valor se asigna al enumerar 
//las celdas de derecha a izquierda por fila
vector<vector<int>> create_matrix(int n);

//ejercicio 1-b
//Imprime una una matriz de nxn construida con vectores, utilizando un unico FOR.
//se imprime desde el mayor valor hasta al menor, con indices.
void print_square_matrix(vector<vector<int>> matrix, int n);

