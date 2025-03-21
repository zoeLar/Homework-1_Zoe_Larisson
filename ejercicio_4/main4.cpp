#include "ejercicio_4.h"



int main(void)
{
    //Primero evaluo cual es mas rapido con el mismo texto e imprimo el resultado
    string s="Buenos dias, como estas, espero que bien, nos vemos mañana cuando estes libre?";
    string s2="Buenos dias, como estas, espero que bien, nos vemos mañana cuando estes libre?";
    const char * c1="Buenos dias, como estas, espero que bien, nos vemos mañana cuando estes libre?";
    const char * c2="Buenos dias, como estas, espero que bien, nos vemos mañana cuando estes libre?";
    
    int x=80;

    comparar_velocidad(s,s2,c1,c2);

    /* claramente char * es mucho mas rapido que string, ya que string es modificable mientras que const char *, se almacena en una "pila" en memoria.
    Para el item iii) el unico que se puede utilizar para realizar el codigo es const char * debido a que string al ser modificable no 
    se puede utilizar con string
    */

    cout<<"----------------------------------------------------------------------------"<<endl;
    
    comparar_velocidad(c1,c2);
    return 0;
}

