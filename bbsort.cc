#include <iostream>
using namespace std;

typedef int Elem;
struct Node{
    Elem elem;
    Node* prev;
    Node* next;
};

class Iterator{
        public:
            Elem& operator*();
            bool operator == (const Iterator& p) const;
            bool operator != (const Iterator& p) const;
            Iterator& operator++();
            Iterator& operator--();
            friend class NodeList;
            friend class NodeSequence;
        private:
            Node* v;
            Iterator(Node* u);
};
Iterator::Iterator(Node* u)
    { v = u; }

Elem& Iterator::operator*()
    { return v->elem; }

bool Iterator::operator == (const Iterator& p) const
    { return v == p.v; }

bool Iterator::operator != (const Iterator& p) const
    { return v != p.v; }

Iterator& Iterator::operator++()
    { v = v->next; return *this; }

Iterator& Iterator::operator--()
    { v = v->prev; return *this; }

class NodeList{
    public:
        NodeList();
        int size() const;
        bool empty() const;
        Iterator begin() const;
        Iterator end() const;
        void insertFront(const Elem& e);
        void insertBack(const Elem& e);
        void insert(const Iterator& p, const Elem& e);

        Iterator atIndex(int i) const;
        int indexOf(const Iterator& p) const;
        void bubbleSort1 (NodeList& p);
        void bubbleSort2 (NodeList& p);

    private:
        int n;
        Node* header;
        Node* trailer;
};

NodeList::NodeList(){
    n = 0;
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
}

int NodeList::size() const 
    { return n; }

bool NodeList::empty() const
    { return (n == 0); }

Iterator NodeList::begin() const
    { return Iterator(header->next); }

Iterator NodeList::end() const
    { return Iterator(trailer); }

void NodeList::insert(const Iterator& p, const Elem& e){
    Node* w = p.v;
    Node* u = w->prev;
    Node* v = new Node;
    v->elem = e;
    v->next = w; 
    w->prev = v;
    v->prev = u;
    u->next = v;
    n++;
}
void NodeList::insertFront(const Elem& e)
    { insert(begin(), e); }

void NodeList::insertBack(const Elem& e)
    { insert(end(), e); }

Iterator NodeList::atIndex(int i) const{
    Iterator p = begin();
    for (int j = 0; j < i; j++) ++p;
    return p;
}

int NodeList::indexOf(const Iterator& p) const{
    Iterator q = begin();
    int j = 0;
    while (q != p){
        ++q; ++j;
    }
    return j;
}

void NodeList::bubbleSort1(NodeList& p){
    int s = p.size();
    for (int i = 0; i < s; i++){
        for (int j = 1; j < s-i; j++){
            Iterator prec = p.atIndex(j-1);
            Iterator succ = p.atIndex(j);
            if (*prec > *succ){
                int tmp = *prec; 
                *prec = *succ; 
                *succ = tmp;
            }
        }
    }
}

void NodeList::bubbleSort2(NodeList& p){
    int s = p.size();
    for (int i = 0; i < s; i++){
        Iterator prec = p.begin();
        for (int j = 1; j < s-i; j++){
            Iterator succ = prec;
            ++succ;
            if(*prec > *succ){
                int tmp = *prec; 
                *prec = *succ; 
                *succ = tmp;
            }
            ++prec;
        }
    }
}

int main (){
    NodeList list1;
    NodeList list2;
    list1.insertFront(4);
    list1.insertFront(2);
    list1.insertFront(1);
    list1.insertFront(8);
    list1.insertFront(6);

    list1.bubbleSort1(list1);
    cout<<"bubbleSort1: ";
    for (Iterator it = list1.begin(); it != list1.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;
    list2.insertFront(4);
    list2.insertFront(2);
    list2.insertFront(1);
    list2.insertFront(8);
    list2.insertFront(6);
    list2.bubbleSort2(list2);
    cout<<"bubbleSort2: ";
    for (Iterator it = list2.begin(); it != list2.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}