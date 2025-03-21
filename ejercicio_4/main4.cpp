#include "ejercicio_4.h"

const char * cc1="Buenos dias, como estas, espero que bien, nos vemos mañana cuando estes libre?";
const char * cc2="Buenos dias, como estas, espero que bien, nos vemos mañana cuando estes libre?";
const int len1=80;
const int len2=80;

int main(void)
{
    //Primero evaluo cual es mas rapido con el mismo texto e imprimo el resultado
    string s="Buenos dias, como estas, espero que bien, nos vemos mañana cuando estes libre?";
    string s2="Buenos dias, como estas, espero que bien, nos vemos mañana cuando estes libre?";
    const char * c1="Buenos dias, como estas, espero que bien, nos vemos mañana cuando estes libre?";
    const char * c2="Buenos dias, como estas, espero que bien, nos vemos mañana cuando estes libre?";
    
    comparar_velocidad(s,s2,c1,c2);
    /*claramente char * es mucho mas rapido que string 
    //para el item iii) el unico que se puede utilizar para realizar el codigo en
    tiempo de ejecucion es 
    */
    auto start = std::chrono::high_resolution_clock::now();

    bool resultado= comparar_texto_comp(cc1,cc2,len1,len2,0);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>( end - start);

    cout<<"resultado de la comparacion en tiempo de compilacion  : " <<resultado<< endl;
    cout << "A comparar_texto_comp le tomó: " << elapsed.count() << " nanosegundos" << std::endl;
    //----------------------------------------------------
    auto start2 = std::chrono::high_resolution_clock::now();

    bool resultado2= comparar_texto(c1,c2,len1,len2);

    auto end2 = std::chrono::high_resolution_clock::now();
    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>( end2 - start2);

    cout<<"resultado de la comparacion en tiempo de compilacion  : " <<resultado2<< endl;
    cout << "A comparar_texto_comp le tomó: " << elapsed2.count() << " nanosegundos" << std::endl;

    return 0;
}
//preguntar: hay q tener 4 funcs? o solo con dos q sean const estoy?
