#pragma once

#include <iostream>
#include <memory>
using namespace std;

struct nodo{
    int value;
    shared_ptr<nodo> next;
};
struct list{
    int size; 
    shared_ptr<nodo> head;
    shared_ptr<nodo> tail;
};

//Crea un nodo con valor tipo int
shared_ptr<nodo> create_node(int valor);

//Crea una lista de nodos
shared_ptr<list> create_lista (void);

//inserta al final
void push_back (shared_ptr<list> &lista,   shared_ptr<nodo> &nuevo );

//inserta al comienzo
void push_front(shared_ptr<list> &lista, shared_ptr<nodo> &nuevo );

//Inserta un nodo en la posicion n. Si n es mayor que el tamaño de la lista se retorna  
void insertar(shared_ptr<list> &lista, int n, shared_ptr<nodo> &nuevo );

//imprime la lista
void imprime_lista(shared_ptr<list> &lista);

//elima el nodo en la posicion n
void elimina_nodo(shared_ptr<list> &lista, int n);

// encuentra un nodo n considerando [0,n]
shared_ptr<nodo> encuentra_nodo(shared_ptr<list> &lista, int n);

