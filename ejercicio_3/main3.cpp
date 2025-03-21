#include "ejercicio_3.h"


int main(void){
    //genero casos de prueba
    {   
        //GENERO SCOPE
        auto lista_p=create_lista(); //la p significa prueba
        cout<< "ACLARACION: cuando se crean las listas el valor del nodo representa el orden en el que se 'insertaron' "<<endl;
        cout<< "Lista creada haciendo push back 10 veces: "<<endl;

        for (int i=0; i<=10; i++ ){
            auto nodo_p=create_node(i);
            push_back(lista_p,nodo_p);
        }

        //imprimo lista
        imprime_lista(lista_p);
        //agrego casos:
        cout<< "Añado un nodo con valor 11 en la posicion 23 con insertar: "<<endl;
        auto nodo_once=create_node(11);
        insertar(lista_p,23,nodo_once);
        imprime_lista(lista_p);

        cout<< "Añado un nodo con valor 12 en la posicion 0: "<<endl;
        auto nodo_doce=create_node(12);
        insertar(lista_p,0,nodo_doce);
        imprime_lista(lista_p);

        cout<< "Añado un nodo con valor 13 en la posicion 5: "<<endl;
        auto nodo_trece=create_node(13);
        insertar(lista_p,5,nodo_trece);
        imprime_lista(lista_p);

        cout<< "Elimino el nodo en la posicion 4: "<<endl;
        elimina_nodo(lista_p,4);
        imprime_lista(lista_p);
        
        cout<< "Elimino el nodo en la posicion 0: "<<endl;
        elimina_nodo(lista_p,0);
        imprime_lista(lista_p);

        cout<< "Elimino el nodo en la posicion 300: "<<endl;
        elimina_nodo(lista_p,300);
        imprime_lista(lista_p);
        
        cout<< "Elimino el nodo en la posicion 10: "<<endl;
        elimina_nodo(lista_p,10);
        imprime_lista(lista_p);

        cout<< "Elimino el nodo en la posicion 10 otra vez: "<<endl;
        elimina_nodo(lista_p,10);
        imprime_lista(lista_p);
    }

    {
        //CREO NUEVA LISTA
        cout<< "\nElimino la lista anterior"<<endl;
        cout<< "Lista creada haciendo push front 10 veces: "<<endl;

        auto lista_p=create_lista();

        for (int i=0; i<=10; i++ ){
            auto nodo_p=create_node(i);
            push_front(lista_p,nodo_p);
        }
        imprime_lista(lista_p);
    }
    return 0;
}
