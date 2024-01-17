#include <iostream>
#include <exception>
#include <cstdlib>
#include <string>
using namespace std;

class RuntimeException {
    public:
        RuntimeException(const string& err) {errorMsg = err;}
        string getMessage() const {return errorMsg;}
      private:
        string errorMsg;
};

class QueueEmpty : public RuntimeException {
    public:
        QueueEmpty(const string& err) : RuntimeException(err) {}
};

typedef string Elem;
class CNode {
    private:
        Elem elem;
        CNode* next;

        friend class CircleList;
};

class CircleList{
    public:
        CircleList();
        ~CircleList();
        bool empty() const;
        const Elem& front() const;
        const Elem& back() const;
        void advance();
        void add(const Elem& e);
        void remove();
    private:
        CNode* cursor;
};

CircleList::CircleList()
    : cursor(NULL) {}
CircleList::~CircleList()
    { while (!empty()) remove(); }

bool CircleList::empty() const 
    { return cursor == NULL; }
const Elem& CircleList::back() const
    { return cursor->elem; }
const Elem& CircleList::front() const
    { return cursor->next->elem; }
void CircleList::advance()
    { cursor = cursor->next; }

void CircleList::add(const Elem& e){
    CNode* v  = new CNode;
    v->elem = e;
    if (cursor == NULL){
        v->next = v;
        cursor = v;
    }
    else{
        v->next = cursor->next;
        cursor->next = v;
    }
}

void CircleList::remove(){
    CNode* old = cursor->next;
    if (old == cursor) 
        cursor = NULL;
    else 
        cursor->next = old->next;
    delete old;
}

typedef string Elem;
class LinkedQueue {
    public:
        LinkedQueue();
        int size() const;
        bool empty() const;
        const Elem& front();
        void insertion(const Elem& e); // enqueue
        void deletion(); // dequeue
        void display_queue(); // HW4
    private:
        CircleList C;
        int n;
};

LinkedQueue::LinkedQueue()
    : C(), n(0) {}

int LinkedQueue::size() const
    { return n; }

bool LinkedQueue::empty() const
    { return n == 0; }

const Elem& LinkedQueue::front() {
    try{
        if (empty())
        throw QueueEmpty("front of empty queue");
    }
    catch (QueueEmpty) {
        cout<<"front of empty queue"<<endl;
    }
    return C.front();
}

void LinkedQueue::insertion(const Elem& e){ 
    C.add(e);
    C.advance();
    n++;
    display_queue();
}

void LinkedQueue::deletion(){
    try{
        if (empty())
        throw QueueEmpty("deletion of empty queue");
    }
    catch (QueueEmpty) {
        cout<<"deletion of empty queue"<<endl;
    }
    C.remove();
    n--;
    display_queue();
}
void LinkedQueue::display_queue(){
    int x = 0;
    while (x != n){
        cout<<" -> "<<C.front();
        C.advance(); 
        x++;
       
    }
    cout<<endl;

}

int main(){
    LinkedQueue lk;
    lk.insertion("john");
    lk.insertion("james");
    lk.insertion("jean");

    lk.deletion();
    lk.deletion();
}