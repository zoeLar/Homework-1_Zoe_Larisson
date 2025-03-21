#pragma once

#include <chrono>
#include <iostream>
#include <cstring>
using namespace std;

//Compara dos strings
bool comparar_texto(string texto_1, string texto_2,int size_1,int size_2, int i=0 );

//Compara dos char[]
bool comparar_texto(const char * texto_1, const char * texto_2, int size_1, int size_2, int i=0);

//Compara dos const char * en tiempo de compilacion
constexpr bool comparar_texto_comp(const char* texto_1, const char* texto_2, int size_1, int size_2, int i=0);

//Compara la velocidad entre: comparar dos strings y comparar dos char[]
void comparar_velocidad(string str1, string str2, const char * char1, const char *char2);

//Compara la velocidad entre: comparar dos char[] y comparar dos const char* en una funcion que se ejecuta en tiempo de compilacion
void comparar_velocidad( const char * char1, const char *  char2);