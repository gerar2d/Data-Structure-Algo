#include <iostream>
#include <string>
using namespace std;


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

int main(){
    CircleList playList;
    playList.add("easily");
    playList.add("fred");
    playList.add("californication");

    playList.advance();
    playList.advance();
    playList.remove();
    playList.add("otherside");
    

    cout<<"Now Playing: "<<playList.front()<<endl; 
    while (!playList.empty()) {  // set while parameter to true to continue playing in an infite loop
        playList.advance();
        cout<<"Now Playing: "<<playList.front()<<endl;
        playList.remove(); // as cursor moves to another song the playlist removes it from the playlist in order to end the loop.
    }

    return 0;
}




