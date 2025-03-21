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
    n_actual->value=NULL;
    n_actual.reset();
    n_actual=nullptr;
    lista->size--;

    return;
}

int main(void){
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
