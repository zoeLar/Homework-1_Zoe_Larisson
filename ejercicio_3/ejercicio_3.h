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

shared_ptr<nodo> create_node(int valor);

shared_ptr<list> create_lista (void);