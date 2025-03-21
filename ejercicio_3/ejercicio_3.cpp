#include "ejercicio_3.h"
#include <iostream>
#include <memory>
using namespace std;


shared_ptr<nodo> create_node(int valor){
    auto nuevo= make_shared<nodo>();
    nuevo->value=valor;
    nuevo->next=nullptr;
    return nuevo;
}

shared_ptr<list> create_lista (void){
    auto lista= make_unique<list>();
    lista->size=0;
    lista->head=nullptr;
    lista->tail=nullptr;
    return lista;
}

void push_back (shared_ptr<list> &lista,   shared_ptr<nodo> &nuevo ){
    if(lista->size==0){
        lista->head= nuevo;
        lista->tail= nuevo;
        lista->size++;
        return;
    } 
    lista->tail->next=nuevo;
    lista->tail=nuevo;
    lista->size+=1;

}

void push_front(shared_ptr<list> &lista, shared_ptr<nodo> &nuevo ){
    if(lista->size==0){
        lista->head= nuevo; 
        lista->tail= nuevo;
        lista->size++;
        return;  
    } 
    nuevo->next= lista->head;
    lista->head=nuevo;
    lista->size+=1;
}

//n considerando [0,n]
shared_ptr<nodo> encuentra_nodo(shared_ptr<list> &lista, int n){
    int size=lista->size;
    shared_ptr<nodo> actual=lista->head;
    for (int i=1; i<=n;i++){
        actual=actual->next;
    }
    return actual;
}

//n= lugar en la lista
void insertar(shared_ptr<list> &lista, int n, shared_ptr<nodo> &nuevo ){
    int length_l=lista->size;

    if(n>=length_l){
        push_back(lista,nuevo);
        cout<< "n es mayor o igual que el tamaño de la lista. Se ha insertado el nodo al final de la misma\n";
        return;
    }
    if (n==0){
        push_front(lista, nuevo);
        return;
    }

    auto anterior =encuentra_nodo(lista,n-1);

    nuevo->next=anterior->next;
    anterior->next=nuevo;
    lista->size++;

}

void imprime_lista(shared_ptr<list> &lista){
    int size=lista->size;
    shared_ptr<nodo> actual=lista->head;

    for (int i=0; i<size;i++){
        
        if(!actual->next){
            cout <<"[" << actual->value <<"]-> nullptr"<<endl;
            return;
        }

        cout <<"[" << actual->value <<"]->";
        actual=actual->next;
    }
    return;
}

void elimina_nodo(shared_ptr<list> &lista, int n){
    int length_l=lista->size;
    shared_ptr<nodo> n_actual;
    if(n>=length_l){
        cout<< "n es mayor o igual que el tamaño de la lista. Se eliminara el nodo del final de la misma\n";
        n=length_l-1;
        
    }
    if(n!=0){
        auto n_anterior= encuentra_nodo(lista,n-1);
        n_actual= n_anterior->next;
        n_anterior->next=n_actual->next;
    }
    else{
        n_actual=lista->head;
        lista->head=n_actual->next;
    }
    //elimino el nodo
    n_actual->next=nullptr;
    n_actual.reset();
    n_actual=nullptr;
    lista->size--;

    return;
}

