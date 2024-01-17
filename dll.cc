#include <iostream>
#include <string>
using namespace std;

template <typename U>
class DLinkedList;


typedef string Elem;
template <typename U>
class DNode {
    private:
        Elem elem;
        DNode<U>* prev;
        DNode<U>* next;
        friend class DLinkedList<U>;
};

template <typename U>
class DLinkedList {
    public:
    DLinkedList();
    ~DLinkedList();
    bool empty() const;
    const Elem& front() const;
    const Elem& back() const;
    void addFront(const Elem& e);
    void addBack(const Elem& e);
    void removeFront();
    void removeBack();
    void insert(const Elem& e); //HW
    void deletee(Elem value); //HW
    void display(); // show output HW

    private:
    DNode<U>* header;
    DNode<U>* trailer;

    protected:
    void add(DNode<U>* v, const Elem& e);
    void remove(DNode<U>* v);
};

template <typename U>
DLinkedList<U>::DLinkedList(){
    header = new DNode<U>;
    trailer = new DNode<U>;
    header->next = trailer;
    trailer->prev = header;
}

template <typename U>
DLinkedList<U>::~DLinkedList(){
    while (!empty()) removeFront();
    delete header;
    delete trailer;
}

template <typename U>
bool DLinkedList<U>::empty() const{
    return (header->next == trailer);
}

template <typename U>
const Elem& DLinkedList<U>::front() const{
    return header->next->elem;
}

template <typename U>
const Elem& DLinkedList<U>::back() const{
    return trailer->prev->elem;
}

template <typename U>
void DLinkedList<U>::add(DNode<U>* v, const Elem& e){
    DNode<U>* u = new DNode<U>;
    u->elem = e;
    u->next = v;
    u->prev = v->prev;
    v->prev = v->prev->next = u;
}

template <typename U>
void DLinkedList<U>::addFront(const Elem& e){
    add(header->next, e);
    cout<<e<<" Added to playlist."<<endl;
}

template <typename U>
void DLinkedList<U>::addBack(const Elem& e){
    add(trailer, e);
}

template <typename U>
void DLinkedList<U>::remove(DNode<U>* v){
    DNode<U>* u = v-> prev;
    DNode<U>* w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}

template <typename U>
void DLinkedList<U>::removeFront(){
    remove(header->next);
}

template <typename U>
void DLinkedList<U>::removeBack(){
    remove(trailer->prev);
}

template <typename U>
void DLinkedList<U>::insert(const Elem& e){ // insert element
    DNode<U>* current = header->next;
    while (current != trailer && current->elem < e) current = current->next;
    
    add(current, e);
}

template<typename U>
void DLinkedList<U>::deletee(Elem value){ // delete element
    if(header == NULL) return;
    if(header->elem == value){
        removeFront();
        return;
    }
    DNode<U>* previous = header;
    DNode<U>* current = header->next;

    while(current && current->elem != value){
        previous=current;
        current=current->next;
    }
    if(!current){
        cout<<"Not in list...\n";
        return;
    }

    if(current->next==NULL){
        removeBack();
        return;
    }

    previous->next = current->next;
    delete current;
}

template<typename U>
void DLinkedList<U>::display(){  // display list
    DNode<U>* current = header->next; 
    while (current != trailer) { 
        cout<<current->elem<<"      "; 
        current = current->next; 
    }
    cout<<endl;
}



int main(){
    DLinkedList<string> ds;
    
    ds.addFront("around the world");
    ds.addFront("Take on Me");
    ds.addFront("Save a Prayer");
    ds.addFront("One More Night");
    ds.addFront("Stand By Me");
    ds.display();

    ds.deletee("Take on Me");
    ds.insert("reebok or nike");
    ds.display();

}