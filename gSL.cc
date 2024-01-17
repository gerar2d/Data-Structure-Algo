#include <iostream>
#include <string>

using namespace std;
template<typename E>
class SLinkedList;

template <typename E> 
class SNode {
    private:
        E elem;
        SNode<E>* next;
        friend class SLinkedList<E>;
};

template <typename E> 
class SLinkedList { 
    public:
        SLinkedList(); 
        ~SLinkedList();
        bool empty() const;
        const E& front() const; 
        void addFront(const E& e); 
        void removeFront();
        void addBack(const E& e);  // HW
        void removeBack(); // HW
        void insert(E value); // HW
        void deletee(E value); // HW
        void display();  // HW
    private: 
        SNode<E>* head;

};

template <typename E> SLinkedList<E>::SLinkedList()
: head(NULL) { }

template <typename E>
bool SLinkedList<E>::empty() const
{ return head == NULL; }

template <typename E>
const E& SLinkedList<E>::front() const
{ return head->elem; }

template <typename E> 
SLinkedList<E>::~SLinkedList()
{ while (!empty()) removeFront(); }

template <typename E>
void SLinkedList<E>::addFront(const E& e){
    SNode<E>* v = new SNode<E>; 
    v->elem = e;
    v->next = head;
    head = v;
}

template <typename E>
void SLinkedList<E>::removeFront() {
    SNode<E>* old = head; 
    head = old->next; 
    delete old;
}

template <typename E>
void SLinkedList<E>::addBack(const E& e){  // add to back
    SNode<E>* v = new SNode<E>;
    v->elem = e;
    v->next = NULL;
    if(head == NULL) head = v;
    
    SNode<E>*current = head;
    
    while(current->next) current = current->next;
    
    current->next = v;
}

template <typename E>
void SLinkedList<E>::removeBack() {  // remove from back
    if (!head) return;
    SNode<E>* current = head,*prev=head;
    if(head->next == NULL){
        head = current->next;
        delete current;
        return;
    }
    while(current->next){
        prev = current;
        current = current->next;
    }
    prev ->next = current->next;
    delete current;
    return;
}

template <typename E>
void SLinkedList<E>::insert(E value){  //insert element into any free space
    if(head == NULL || head->elem > value){
        addFront(value);
        return;
    }
    SNode<E>* v = new SNode<E>;
    v->elem = value;
    v->next = NULL;
    SNode<E>* previous = head;
    SNode<E>* current = head->next;
   
    while (current != NULL && value > current->elem){
        previous = current;
        current = current->next;
    }
    previous->next = v;
    v->next = current;
}

template<typename E>
void SLinkedList<E>::deletee(E value){ // delete element
    if(head == NULL) return;
    if(head->elem == value){
        removeFront();
        return;
    }
    SNode<E>* previous = head;
    SNode<E>* current = head->next;

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


template<typename E>
void SLinkedList<E>::display() {  // display list
    SNode<E>* temp = head;
    cout<<"\n";
    while (temp) {
        int count = 0;
        cout<<temp->elem;
        temp = temp->next;
        if (temp) cout<<" > ";  
    }
    cout<<"\n";
}



int main(){

SLinkedList<string> a; 
SLinkedList<int> b;

b.addFront(10);
b.addFront(80);
b.addBack(23);
b.display();
b.deletee(10);
b.display();

a.insert("here");
a.insert("we");
a.insert("go");
a.display();
a.deletee("here");
a.display();

return 0;
}