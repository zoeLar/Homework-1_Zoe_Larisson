#include <iostream>
#include <memory>
using namespace std;

struct nodo{
    int value;
    shared_ptr<nodo> next;
};
struct list{
    int size; //no considera al 0
    shared_ptr<nodo> head;
    shared_ptr<nodo> tail;
};

//funcs
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

void push_front (shared_ptr<list> &lista,   shared_ptr<nodo> &nuevo ){
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
void push_back(shared_ptr<list> &lista, shared_ptr<nodo> &nuevo ){
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
        push_front(lista,nuevo);
        cout<< "n es mayor o igual que el tamaño de la lista. Se ha insertado el nodo al final de la misma\n";
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
    auto n_anterior= encuentra_nodo(lista,n-1);
    auto n_actual= n_anterior->next;

    n_anterior->next=n_actual->next;
    n_actual.reset();
    lista->size--;

    return;
}

int main(void)
{
    {//genero un scope para que se elimine solo
    auto listita=create_lista();
    cout<< "Lista creada haciendo push back 10 veces"<<endl;
    for (int i=0; i<=10; i++ ){
        auto nodito=create_node(i);
        push_back(listita,nodito);
    }
    imprime_lista(listita);
    }
    {//genero un scope para que se elimine solo
    auto listita=create_lista();
    cout<< "Lista creada haciendo push front 10 veces"<<endl;
    for (int i=0; i<=10; i++ ){
        auto nodito=create_node(i);
        push_front(listita,nodito);
    }
    imprime_lista(listita);
    //aNado un nodo en la posicion 11 con valor 99
    auto nodito=create_node(99);
    insertar(listita,11, nodito);
    imprime_lista(listita);
    elimina_nodo(listita,10);
    imprime_lista(listita);

    }
    return 0;
}
